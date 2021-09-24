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
#define MAX_COMMAND_SIZE 16
#define MAX_VAR_SIZE 240

#define MAX_DISPLAY_STR_LEN 24

#define DENC_INPT_bm 0x7C
#define SIGNAL_STRENGTH_STEPS 11


uint16_t LDR_res;
float calc_volt;

char display_array[MAX_DISPLAY_STR_LEN] = {10};
char* display_str = &display_array[0];
uint8_t display_str_len = 0;
int32_t display_last_shift;
bool display_shift_dir = 1;

char clock_array[2];
bool clock_minutes;
time_t disp_time;
struct tm* disp_tm_ptr;


uint8_t signal_strength;
bool signal_strength_changed;
uint8_t sig_str_cmp_vals[SIGNAL_STRENGTH_STEPS] = {0, 4, 8, 12, 18, 27, 35, 45, 60, 80, 100};

uint8_t brightness_factor = 1;

uint8_t RPI_state;
#define RPI_shut_down 0
#define RPI_shutting_down 10
#define RPI_sleep 20
#define RPI_active 30


time_t shutdown_timestamp;

uint8_t button_states;
#define PowerButtonbm 0x08;
#define KeySwitchAbm 0x10;
#define KeySwitchBbm 0x20;




struct LED {
    uint8_t     freq;
    bool        enable;
    uint16_t    thresh;
    bool        tresh_wrapped;
    bool        clock_wrapped;
    uint8_t     PF_POS;
};

struct LED LED_R = {0,0,0,0,0, 0x02};
struct LED LED_Y = {0,0,0,0,0, 0x01};
struct LED LED_G = {0,0,0,0,0, 0x04};

struct LED LED_S = {0,0,0,0,0, 0x08};

char buffer_array[MAX_BUFFER_SIZE];
char* buffer = &buffer_array[0];

char command_array[MAX_COMMAND_SIZE];
char* command = &command_array[0];

void handle_RTC_overflow(void)
{
    system_tick();
    
    LED_R.clock_wrapped = LED_R.enable;
    LED_Y.clock_wrapped = LED_Y.enable;
    LED_G.clock_wrapped = LED_G.enable;
    
    LED_S.clock_wrapped = LED_S.enable;    
    
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
        printf("PWRBTN_SLEEP\n");                    
    }
    else if (RPI_state == RPI_sleep)
    {
        printf("PWRBTN_WAKEUP\n");                    
    }
    else if (RPI_state == RPI_shut_down)
    {
        RPI_RUN_SetHigh();
        //TODO: necessary timespan  for boot?
    }
}

void handle_KeyS_A_change(void)
{
    if (KeyS_A_GetValue())
    {
        printf("KeyS_A;1\n");
    }
    else
    {
        printf("KeyS_A;0\n");
    }
}

void handle_KeyS_B_change(void)
{
    if (KeyS_B_GetValue())
    {
        printf("KeyS_B;1\n");
    }
    else
    {
        printf("KeyS_B;0\n");    
    }
}

void handle_IGN_SNS_change(void)
{
    if (IGN_SNS_GetValue())
    {
        printf("IGN_SNS;1\n");
    }
    else
    {
        printf("IGN_SNS;0\n");
        
        //save timestamp if ignition low
        time(&shutdown_timestamp);
    }
}

//Serial handling
bool UART_ReadLine(char* buffer)
{
    uint8_t c;
    uint8_t index = 0;
    while(USART1_IsRxReady())
    {        
        c = USART1_Read();
        printf("%d", c);
        if(c != '\n' && c != '\r')
        {
            buffer[index++] = c;
            if(index > MAX_BUFFER_SIZE)
            {
                index = 0;
            }
        }
        
        if(c == '\n')
        {
            buffer[index] = '\0';
            
            index = 0;
            
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
            PORTF_OUTCLR = led_ptr->PF_POS;
        }
        else if (led_ptr->thresh < RTC.CNT && led_ptr->tresh_wrapped == led_ptr->clock_wrapped)
        {
            //toggle
            PORTF_OUTTGL = led_ptr->PF_POS;

            led_ptr->clock_wrapped = led_ptr->tresh_wrapped = false;            

            uint16_t prev_thresh = led_ptr->thresh;
            led_ptr->thresh += 31.25 / led_ptr->freq;

            if (prev_thresh > led_ptr->thresh)
            {
                led_ptr->tresh_wrapped = true;
            }
        }
        else if (led_ptr->thresh > RTC.CNT && !led_ptr->tresh_wrapped && led_ptr->clock_wrapped)
        {
            
            PORTF_OUTTGL = led_ptr->PF_POS;
            
            uint16_t prev_thresh = led_ptr->thresh;
            led_ptr->thresh += 31.25 / led_ptr->freq;

            if (prev_thresh > led_ptr->thresh)
            {
                led_ptr->tresh_wrapped = true;
            }

        }
        
    }
    else 
    {
        PORTF_OUTSET |= led_ptr->PF_POS;
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
        led_ptr->thresh = temp_CNT + 31.25 / led_ptr->freq;
        
        PORTF_OUTTGL = led_ptr->PF_POS;

        if (led_ptr->thresh < temp_CNT)
        {
            led_ptr->tresh_wrapped = true;
        }        
    }
}

void init(void) 
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();
    
    //register interrupts
    RTC_SetOVFIsrCallback(&handle_RTC_overflow);
    RTC_SetCMPIsrCallback(&handle_RTC_compare);
    RTC_EnableOVFInterrupt();
    RTC_EnableCMPInterrupt();
    
    PORTF_PWR_BTN_SetInterruptHandler(&handle_PWR_BTN_Press);
    PORTB_KeyS_A_SetInterruptHandler(&handle_KeyS_A_change);
    PORTB_KeyS_B_SetInterruptHandler(&handle_KeyS_B_change);
    PORTB_IGN_SNS_SetInterruptHandler(&handle_IGN_SNS_change);
    
    //fill display array with 10s   
    
    
    LED_R.PF_POS = 0x02;
    LED_Y.PF_POS = 0x01;
    LED_G.PF_POS = 0x04;

    LED_S.PF_POS = 0x08;
    
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
            
            clock_minutes = 0;
        }
        else if (!clock_minutes && RTC.CNT > RTC.PER/3)
        {
            time(&disp_time);
            disp_tm_ptr = localtime(&disp_time);

            clock_array[0] = disp_tm_ptr->tm_min / 10;
            clock_array[1] = disp_tm_ptr->tm_min % 10;
            
            clock_minutes = 1;
        }
                 
        ////Display logic
        //iterate through digits
        for (uint8_t i = 0; i<16; i++)
        {
            //set anode driver
            if (i < 2)
            {
                VPORTE_OUT = clock_array[i];
            }
            else
            {
                VPORTE_OUT = display_str[i-2];
            }
            
            //set cathode driver
            VPORTC_OUT = i << 4;
            
            DELAY_microseconds(700);
            
        }
        
        
        
        //calculate next excerpt
        if (display_str_len > 14 && RTC.CNT - display_last_shift > 15 )
        {
            uint8_t diff = display_str - &display_array[0];
            if(diff == 0)
            {
                display_shift_dir = true;
            }
            else if (diff == display_str_len)
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
        if (DEncDAvail_GetValue())
        {
            //set output enable
            DEncDOutEnable_SetHigh();
            
            //wait? propagation delay: max 250ns
            //DELAY_microseconds(1);
            
            //read inputs
            //write to UART     
            printf("KeyIn;%x\n", (VPORTD_IN & DENC_INPT_bm) >> 2);
        }
        
        ////Serial logic
        //check Data Avail
        
        //read until line break
        if (UART_ReadLine(buffer))
        {
            //evaluate command
            printf("\nBuffer:");            
            printf(buffer);
            command = strsep(&buffer, ";");
            printf("\nCommand:");            
            printf(command);
            printf("\nVars:");
            printf(buffer);
            
            if (strcmp(command, "SetNum") == 0)
            {
                    printf("\nBuffer: ");
                    printf(buffer);
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
                        }
                        
                        buffer[i] = '\0';
                    }
                    
                    display_str = &display_array[0];
                    
            }
            else if (strcmp(command, "SetSignal") == 0)
            {
                signal_strength = atoi(buffer);
                signal_strength_changed = true;
            }   
            else if (strcmp(command, "SetLED") == 0)
            {
                //SetLED;G;1;0
                switch (strsep(&buffer, ";")[0]) 
                {
                    case 'R':
                        setup_LED(&LED_R, buffer);
                        break;
                    case 'Y':
                        setup_LED(&LED_Y, buffer);
                        break;
                    case 'G':
                        setup_LED(&LED_G, buffer);
                        break;
                    case 'S':
                        setup_LED(&LED_S, buffer);
                        break;
                }                
            }
            else if (strcmp(command, "SetTime") == 0)
            {
                time_t temp_time;
                ctime_r(&temp_time, buffer);                
                
                set_system_time(temp_time);
            }
            else if (strcmp(command, "SetBrFac") == 0)
            {
                brightness_factor = atoi(buffer);
            }
            else if (strcmp(command, "SetShtComp") == 0)
            {
                RPI_state = RPI_shut_down;
            }
            else if (strcmp(command, "SetSleep") == 0)
            {
                RPI_state = RPI_sleep;
            }
            else if (strcmp(command, "SetActive") == 0)
            {
                RPI_state = RPI_active;
            }
            else if (strcmp(command, "SetBckConv_EN") == 0)
            {
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
            else if (strcmp(command, "GetTime") == 0)
            {
                time_t temp_time;
                time(&temp_time);
                printf(ctime(&temp_time));
            }
            
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
            TCA0.SINGLE.CMP0 = TCA0.SINGLE.PER * ((LDR_res/UINT8_MAX) * 1/brightness_factor);
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
            
            if (difftime(temp_time, shutdown_timestamp) > 1800)
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