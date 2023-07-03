/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/include/usart1.h"
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <time.h>

#define RES_10BIT 0x3FF
#define MAX_VOL 5.0 // VREF=2.5V

#define MAX_BUFFER_SIZE 64
//#define MAX_COMMAND_SIZE 16
#define MAX_VAR_SIZE 240

#define MAX_DISPLAY_STR_LEN 24

#define DENC_INPT_bm 0x7C
#define SIGNAL_STRENGTH_STEPS 11
#define DISP_DRIVER_PORTMASK 0xC3
#define DISP_DECODER_PORTMASK 0x1F


uint16_t LDR_res;
float calc_volt;


char display_array[MAX_DISPLAY_STR_LEN] ;
char* display_str = &display_array[0];
uint8_t display_str_len = 0;
int32_t display_last_shift;
bool display_shift_dir = 1;

char clock_array[2];
bool clock_minutes;
time_t disp_time;
struct tm* disp_tm_ptr;


uint8_t signal_strength;
bool signal_strength_changed = true;
uint8_t sig_str_cmp_vals[SIGNAL_STRENGTH_STEPS] = {0, 4, 8, 12, 18, 27, 35, 45, 60, 80, 100};

uint8_t brightness_factor = 1;
float brightness_test = 1;

uint8_t RPI_state;
#define RPI_shut_down 0
#define RPI_shutting_down 10
#define RPI_sleep 20
#define RPI_active 30


time_t shutdown_timestamp = UINT32_MAX;
time_t rpi_os_shutdown_complete = 0xFFFFFFFF ;//UINT32_MAX;

uint8_t button_states;
#define PowerButtonbm 0x08;
#define KeySwitchAbm 0x10;
#define KeySwitchBbm 0x20;


//TODO: remove startHigh from RPI_RUN if desired

struct LED {
    uint8_t     freq;
    bool        enable;
    uint16_t    thresh;
    bool        thresh_wrapped;
    bool        clock_wrapped;
    uint8_t     PD_POS;
    volatile uint8_t *   SET_REGISTER; //+=1: CLR +=2: TGL
    
};

struct LED LED_R = {0,0,0,0,0, 0x04, &PORTD_OUTSET};
struct LED LED_Y = {0,0,0,0,0, 0x02, &PORTD_OUTSET};
struct LED LED_G = {0,0,0,0,0, 0x08, &PORTD_OUTSET};

struct LED LED_S = {0,0,0,0,0, 0x04, &PORTE_OUTSET};

char buffer_array[MAX_BUFFER_SIZE];
char* buffer = &buffer_array[0];

//char command_array[MAX_COMMAND_SIZE];
//char* command = &command_array[0];
char command = 0;

uint8_t uart_read_index = 0;

uint16_t nextKeyThresh = 0;
uint8_t minKeyStrokeDifference = 250;
uint8_t nextKeyWrapped = 2; //0: not wrapped; 1: wrapped; 2: wrapped more than once -> don't compare RTC.CNT

void handle_RTC_overflow(void)
{
    system_tick();
    
    LED_R.clock_wrapped = LED_R.enable;
    LED_Y.clock_wrapped = LED_Y.enable;
    LED_G.clock_wrapped = LED_G.enable;
    
    LED_S.clock_wrapped = LED_S.enable;    
    
    nextKeyWrapped += 1;
    
    if (nextKeyWrapped == 3)
        nextKeyWrapped = 2;
    
    display_last_shift = -(UINT16_MAX - display_last_shift);
    
}

void handle_RTC_compare(void)
{
    system_tick();    
}


void handle_PWR_BTN_Press(void)
{
    if (RPI_state == RPI_active)
    {
        //button pressed
        printf("PWRBTN_SLEEP\r\n");                    
    }
    else if (RPI_state == RPI_sleep)
    {
        printf("PWRBTN_WAKEUP\r\n");                    
    }
    else if (RPI_state == RPI_shut_down)
    {
        RPI_RUN_SetHigh(); 
        rpi_os_shutdown_complete = UINT32_MAX;
        //TODO: necessary timespan  for boot?
        
    }
}

void handle_KeyS_A_change(void)
{
    if (KeyS_A_GetValue())
    {
        printf("KeyS_A;1\r\n");
    }
    else
    {
        printf("KeyS_A;0\r\n");
    }
}

void handle_KeyS_B_change(void)
{
    if (KeyS_B_GetValue())
    {
        printf("KeyS_B;1\r\n");
    }
    else
    {
        printf("KeyS_B;0\r\n");    
    }
}

void handle_IGN_SNS_change(void)
{
    if (IGN_SNS_GetValue())
    {
        printf("IGN_SNS;1\r\n");
    }     
    else
    {
        printf("IGN_SNS;0\r\n");
        
        //save timestamp if ignition low
        time(&shutdown_timestamp);
    }
}

//Serial handling
bool UART_ReadLine(char* buff)
{
    uint8_t c;
    
    while(USART1_IsRxReady())
    {        
        c = USART1_Read();
        //printf("%d%c", c, c);
        if(c != '\n' && c != '\r')
        {
            buff[uart_read_index++] = c;
            if(uart_read_index > MAX_BUFFER_SIZE)
            {
                uart_read_index = 0;
            }
        }
        //printf(buff);
        //printf("\r\n");
        if(((c == '\n') || (c == '\r' )) && (uart_read_index > 0))
        {
            buff[uart_read_index] = '\0';
            
            uart_read_index = 0;
            
            return true;                     
        }
    }
    
    return false;
}

void handle_LED(struct LED* led_ptr) 
{
    //TODO: correct frequencing -> RTC
    //TODO: LED R,Y debugging
    //TODO: check brightness
    if (led_ptr->enable)
    {
        if (led_ptr->freq == 0)
        {
            *(led_ptr->SET_REGISTER + 1 ) = led_ptr->PD_POS; //CLR -> Active Low
        }
        else if (led_ptr->thresh < RTC.CNT && led_ptr->thresh_wrapped == led_ptr->clock_wrapped)
        {
            //toggle
            *(led_ptr->SET_REGISTER + 2 ) = led_ptr->PD_POS; //TGL

            led_ptr->clock_wrapped = led_ptr->thresh_wrapped = false;            

            uint16_t prev_thresh = led_ptr->thresh;
            led_ptr->thresh += 1000 / led_ptr->freq;
            
            if (led_ptr->thresh > RTC.PER)
            {
                led_ptr->thresh %= RTC.PER;
                led_ptr->thresh_wrapped = true;
            }
        }
        else if (led_ptr->thresh > RTC.CNT && !led_ptr->thresh_wrapped && led_ptr->clock_wrapped)
        {
            
            *(led_ptr->SET_REGISTER + 2 ) = led_ptr->PD_POS;
            
            uint16_t prev_thresh = led_ptr->thresh;
            led_ptr->thresh += 1000 / led_ptr->freq;

            if (led_ptr->thresh > RTC.PER)
            {
                led_ptr->thresh %= RTC.PER;
                led_ptr->thresh_wrapped = true;
            }

        }
        
    }
    else 
    {
        *(led_ptr->SET_REGISTER) |= led_ptr->PD_POS;
    }
}

void setup_LED(struct LED* led_ptr, char* config_buffer)
{
    //enable;freq
    led_ptr->enable = strsep(&config_buffer, ";")[0] - '0';
    led_ptr->freq = atoi(config_buffer);
    
    if (led_ptr->freq > 0)
    {
        uint16_t temp_CNT = RTC_ReadCounter();
        led_ptr->thresh = temp_CNT + 1000 / led_ptr->freq;
        
        *(led_ptr->SET_REGISTER + 2 ) = led_ptr->PD_POS;

        if (led_ptr->thresh < temp_CNT)
        {
            led_ptr->thresh_wrapped = true;
        }        
    }
}

void init(void) 
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();
    
    for (uint8_t i = 0; i < MAX_DISPLAY_STR_LEN; i++) 
    {
        display_array[i] = 0xa;
    }
    
    //register interrupts
    RTC_SetOVFIsrCallback(&handle_RTC_overflow);
    RTC_SetCMPIsrCallback(&handle_RTC_compare);
    RTC_EnableOVFInterrupt();
    RTC_EnableCMPInterrupt();
    
    PORTD_PWR_BTN_SetInterruptHandler(&handle_PWR_BTN_Press);
    
    PORTA_KeyS_A_SetInterruptHandler(&handle_KeyS_A_change);
    PORTA_KeyS_B_SetInterruptHandler(&handle_KeyS_B_change);
    PORTC_IGN_SNS_SetInterruptHandler(&handle_IGN_SNS_change);
    
    //fill display array with 10s   
    
    
//    LED_R.PD_POS = 0x02;
//    LED_Y.PD_POS = 0x01;
//    LED_G.PD_POS = 0x04;
//
//    LED_S.PD_POS = 0x08;
    
    //raspberry wakeup
    
    //clock
    time(&disp_time);
    disp_tm_ptr = localtime(&disp_time);
    
    clock_array[0] = disp_tm_ptr->tm_hour / 10;
    clock_array[1] = disp_tm_ptr->tm_hour % 10;
}


/*
    Main application
*/
int main(void)
{
    init();
    
    
    
    while (1)
    {
        
        if (clock_minutes && RTC.CNT < RTC.PER/3)
        {
            time(&disp_time);
            disp_tm_ptr = localtime(&disp_time);

            clock_array[0] = disp_tm_ptr->tm_hour / 10;
            clock_array[1] = disp_tm_ptr->tm_hour % 10;
            //clock_array[0] = 10;
            //clock_array[1] = 10;
            
            clock_minutes = 0;
        }
        else if (!clock_minutes && RTC.CNT > RTC.PER/3)
        {
            time(&disp_time);
            disp_tm_ptr = localtime(&disp_time);

            clock_array[0] = disp_tm_ptr->tm_min / 10;
            clock_array[1] = disp_tm_ptr->tm_min % 10;
            //clock_array[0] = 10;
            //clock_array[1] = 10;
            
            
            clock_minutes = 1;
        }
                 
        ////Display logic
        //iterate through digits
        for (uint8_t i = 0; i<16; i++)
        {
            //set anode driver
            if (i < 2)
            {
                VPORTB_OUT = ((clock_array[i] & 0x1) * 4 + (clock_array[i] & 0x2) * 16 + (clock_array[i] & 0x4) * 4 + (clock_array[i] & 0x8)) | (VPORTB_OUT & DISP_DRIVER_PORTMASK);
                
            }
            else
            {
                VPORTB_OUT = ((display_str[i - 2] & 0x1) * 4 + (display_str[i-2] & 0x2) * 16 + (display_str[i-2] & 0x4) * 4 + (display_str[i-2] & 0x8)) | (VPORTB_OUT & DISP_DRIVER_PORTMASK);
            }
            
            //set cathode driver
            //VPORTC_OUT = i << 4;
            uint8_t decoder_mask = (i & 0x1) * 32 + (i & 0x2) * 64 + (i & 0x8) * 8; //too much fun working this out
            VPORTA_OUT = decoder_mask | (VPORTA_OUT & DISP_DECODER_PORTMASK);
            
            if ((i & 0x4) > 0)
                DecD3_SetHigh();
            else 
                DecD3_SetLow();
                
            
            DELAY_microseconds(700);
            
        }
        
        
        
        //calculate next excerpt
        if (display_str_len > 14 && RTC.CNT - display_last_shift > 500 )
        {
            uint8_t diff = display_str - &display_array[0];
            if(diff == 0)
            {
                display_shift_dir = true;
            }  
            else if (diff == (display_str_len - 14))
            {
                display_shift_dir = false;
            }
            
            
            if (display_shift_dir)
            {
                display_str++;
            }
            else 
            {
                display_str--;
            }
            
            display_last_shift = RTC.CNT;
        }
        
        
        ////Keyboard logic
        //check Data available
        if (DEncDOutAvail_GetValue())
        {
            //set output enable
            DEncDOutEnable_SetLow();
            
            //wait? propagation delay: max 250ns
            DELAY_microseconds(1);
            uint8_t tempInt = DEncDOutA_GetValue() >> 1;
            tempInt |= DEncDOutB_GetValue() >> 6;
            tempInt |= DEncDOutC_GetValue() << 2;
            tempInt |= DEncDOutD_GetValue();
            tempInt |= DEncDOutE_GetValue() << 4;            
            //read inputs
            //write to UART 
            DEncDOutEnable_SetHigh();
            
            
            if ( nextKeyWrapped == 2 || ( RTC.CNT > nextKeyThresh && nextKeyWrapped > 0))
            {
                printf("KeyIn;%x\r\n", tempInt);
                
                nextKeyThresh = (RTC.CNT + minKeyStrokeDifference) % RTC.PER;
                nextKeyWrapped = nextKeyThresh > RTC.CNT ? 1 : 0;
            }
        }
        
        ////Serial logic
        //check Data Avail
        
        //read until line break
        if (UART_ReadLine(buffer))
        {
            //evaluate command
            //printf("\r\nBuffer:");            
            //printf(buffer);
            command = buffer[0];
            buffer += 2;//hop <command>;
            //printf("\r\nCommand:");            
            //printf(&command);
            //printf("\r\nVars:");
            //printf(buffer);
            
            if (command == '0')
            {
                //setNum
                    // printf("\r\nBuffer: ");
                    // printf(buffer);
                    bool end_reached = 0;
                    
                    for (int i = 0; i<MAX_DISPLAY_STR_LEN; i++)        
                    {
                        if (buffer[i] == '\0' && !end_reached)
                        {
                            end_reached = 1;
                            display_str_len = i;
                        }                            
                        
                        if (end_reached)
                        {
                            display_array[i] = 10;
                        }
                        else 
                        {
                            display_array[i] = buffer[i] - '0';
                            if (display_array[i] > '9' - '0')
                                display_array[i] = 0x0a;
                        }
                        
                        buffer[i] = '\0';
                    }
                    
                    display_str = &display_array[0];
                    
            }
            else if (command == '1')
            {
                //SetSignal
                signal_strength = atoi(buffer);
                signal_strength_changed = true;
            }   
            else if (command == '2')
            {
                //SetLED;G;1;0
                switch (strsep(&buffer, ";")[0]) 
                {
                    case '0':
                        setup_LED(&LED_R, buffer);
                        break;
                    case '1':
                        setup_LED(&LED_Y, buffer);
                        break;
                    case '2':
                        setup_LED(&LED_G, buffer);
                        break;
                    case '3':
                        setup_LED(&LED_S, buffer);
                        break;
                }                
            }
            else if (command == '3')
            {
                //SetTime
                time_t temp_time;
                struct tm * time_struct;
                // ctime_r(&temp_time, buffer);     
                int year, month, day, hour, minute, second;
                if (sscanf  (buffer, "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second) != EOF)
                {
                    time_struct->tm_year = year;
                    time_struct->tm_mon = month;
                    time_struct->tm_mday = day;
                    time_struct->tm_hour = hour;
                    time_struct->tm_min = minute;
                    time_struct->tm_sec = second;
                    temp_time = mktime(time_struct);
                    set_system_time(temp_time);
                }
            }
            else if (command == '4')
            {
                //SetBrFac
                brightness_factor = atoi(buffer);
            }
            else if (command == '5')
            {
                //SetBrTest
                brightness_test = atof(buffer);
            }
            else if (command == '6')
            {
                //GetLDR
                printf("200;GetLDR;%d",ADC0_GetConversion(ADC_MUXPOS_AIN0_gc) );
            }
            else if (command == '7')
            {
                //SetShtComp
                RPI_state = RPI_shut_down;
                time(&rpi_os_shutdown_complete);
            }
            else if (command == '8')
            {
                //SetSleep
                RPI_state = RPI_sleep;
            }
            else if (command == '9')
            {
                //SetActive
                RPI_state = RPI_active;
            }
            else if (command == 'A')
            {
                //SetBckConv_EN
                //if (strcmp(strsep(&buffer, ";")[0],"1") == 0)
                if ( strsep(&buffer, ";")[0] == '1')
                {
                    BckConv_EN_SetHigh();
                }
                else
                {
                    BckConv_EN_SetLow();
                }
            }
            else if (command == 'B')
            {
                //SetBacklight
                if ( strsep(&buffer, ";")[0] == '1')
                {
                    Backlight_EN_SetHigh();
                }
                else
                {
                    Backlight_EN_SetLow();
                }
            }
            else if (command == 'C')
            {
                //GetTime
                time_t temp_time;
                time(&temp_time);
                //printf("200;GetTime;" + ctime(&temp_time));
                printf(strcat("200;GetTime;", ctime(&temp_time)));
            }
            else if (command == 'D')
            {
                //SetKeyInterval
                minKeyStrokeDifference = atoi(buffer);
            }
            
            //printf("rst\r\n");
            buffer_array[0] = '\0';
            buffer = &buffer_array[0];           
            
        }
        
        
        
        
        ////LDR
        if (RTC.CNT % 32 == 0)
        {
            //read            
            LDR_res = ADC0_GetConversion(ADC_MUXPOS_AIN0_gc);
            //calc_volt  = (LDR_res * MAX_VOL) / RES_10BIT;
            
            //set brightness
            //TODO: formula correction
//            TCA0.SINGLE.CMP0 = TCA0.SINGLE.PER * ((LDR_res/UINT8_MAX) * 1/brightness_factor);
            TCA0.SINGLE.CMP0 = TCA0.SINGLE.PER * brightness_test;
        }
        
        
        ////Signal Strength Dial
        //check changed flag
        if (signal_strength_changed)
        {
            //TODO: debug algorithm, CMP values tested
            uint8_t testint = signal_strength/10;
            
            
            //uint16_t testint = TCA0.SINGLE.PER * (signal_strength/500);            
            //PMW        
            TCA0.SINGLE.CMP1 = sig_str_cmp_vals[testint];
            signal_strength_changed = false;
        }
        
        ////LEDs
        handle_LED(&LED_R);
        handle_LED(&LED_Y);
        handle_LED(&LED_G);
        
        handle_LED(&LED_S);

        
        
        //compare timestamps -> sleep/shutdown
        if (RPI_state == RPI_shut_down && RTC.CNT %  320 == 0)
        {
            time_t temp_time;
            time(&temp_time);
            
            if ( rpi_os_shutdown_complete != UINT32_MAX && temp_time - 3 > rpi_os_shutdown_complete && RPI_RUN_GetValue())
            {
                //RPI_RUN_SetLow(); //Set RPI.Global_EN
                rpi_os_shutdown_complete = UINT32_MAX;
            }
            
            if (difftime(temp_time, shutdown_timestamp) > 20 && !RPI_RUN_GetValue()) //1800
            {
                //complete shutdown
                BckConv_EN_SetLow();
            }
        }
        
        
        
        DELAY_milliseconds(5);
        
               
        
    }
}


/**
    End of File
*/