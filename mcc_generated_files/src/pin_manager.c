/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
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


#include "../include/pin_manager.h"
static void (*PORTD_DEncDOutD_InterruptHandler)(void);
static void (*PORTB_KeyS_A_InterruptHandler)(void);
static void (*PORTD_DEncDOutC_InterruptHandler)(void);
static void (*PORTB_BckConv_EN_InterruptHandler)(void);
static void (*PORTD_DEncDOutEnable_InterruptHandler)(void);
static void (*PORTD_DEncDOutE_InterruptHandler)(void);
static void (*PORTB_KeyS_B_InterruptHandler)(void);
static void (*PORTE_IO_PE0_InterruptHandler)(void);
static void (*PORTE_IO_PE2_InterruptHandler)(void);
static void (*PORTC_PC0_InterruptHandler)(void);
static void (*PORTE_IO_PE1_InterruptHandler)(void);
static void (*PORTA_PA0_InterruptHandler)(void);
static void (*PORTE_IO_PE3_InterruptHandler)(void);
static void (*PORTC_PC1_InterruptHandler)(void);
static void (*PORTC_IO_PC4_InterruptHandler)(void);
static void (*PORTA_PA2_InterruptHandler)(void);
static void (*PORTA_PA1_InterruptHandler)(void);
static void (*PORTC_PC3_InterruptHandler)(void);
static void (*PORTC_IO_PC6_InterruptHandler)(void);
static void (*PORTC_IO_PC5_InterruptHandler)(void);
static void (*PORTC_IO_PC7_InterruptHandler)(void);
static void (*PORTF_IO_PF1_InterruptHandler)(void);
static void (*PORTF_IO_PF0_InterruptHandler)(void);
static void (*PORTF_LED_S_InterruptHandler)(void);
static void (*PORTD_DEncDAvail_InterruptHandler)(void);
static void (*PORTF_IO_PF2_InterruptHandler)(void);
static void (*PORTD_PD0_InterruptHandler)(void);
static void (*PORTD_DEncDOutB_InterruptHandler)(void);
static void (*PORTB_IGN_SNS_InterruptHandler)(void);
static void (*PORTF_PWR_BTN_InterruptHandler)(void);
static void (*PORTD_DEncDOutA_InterruptHandler)(void);
static void (*PORTB_RPI_RUN_InterruptHandler)(void);

void PORT_Initialize(void);

void PIN_MANAGER_Initialize()
{
    PORT_Initialize();

    /* DIR Registers Initialization */
    PORTA.DIR = 0x07;
    PORTB.DIR = 0x05;
    PORTC.DIR = 0xF9;
    PORTD.DIR = 0x80;
    PORTE.DIR = 0x0F;
    PORTF.DIR = 0x0F;

    /* OUT Registers Initialization */
    PORTA.OUT = 0x00;
    PORTB.OUT = 0x04;
    PORTC.OUT = 0x00;
    PORTD.OUT = 0x00;
    PORTE.OUT = 0x00;
    PORTF.OUT = 0x40;

    /* PINxCTRL registers Initialization */
    PORTA.PIN0CTRL = 0x00;
    PORTA.PIN1CTRL = 0x00;
    PORTA.PIN2CTRL = 0x00;
    PORTA.PIN3CTRL = 0x00;
    PORTA.PIN4CTRL = 0x00;
    PORTA.PIN5CTRL = 0x00;
    PORTA.PIN6CTRL = 0x00;
    PORTA.PIN7CTRL = 0x00;
    PORTB.PIN0CTRL = 0x00;
    PORTB.PIN1CTRL = 0x01;
    PORTB.PIN2CTRL = 0x00;
    PORTB.PIN3CTRL = 0x01;
    PORTB.PIN4CTRL = 0x01;
    PORTB.PIN5CTRL = 0x00;
    PORTB.PIN6CTRL = 0x00;
    PORTB.PIN7CTRL = 0x00;
    PORTC.PIN0CTRL = 0x00;
    PORTC.PIN1CTRL = 0x00;
    PORTC.PIN2CTRL = 0x00;
    PORTC.PIN3CTRL = 0x00;
    PORTC.PIN4CTRL = 0x00;
    PORTC.PIN5CTRL = 0x00;
    PORTC.PIN6CTRL = 0x00;
    PORTC.PIN7CTRL = 0x00;
    PORTD.PIN0CTRL = 0x04;
    PORTD.PIN1CTRL = 0x00;
    PORTD.PIN2CTRL = 0x00;
    PORTD.PIN3CTRL = 0x00;
    PORTD.PIN4CTRL = 0x00;
    PORTD.PIN5CTRL = 0x00;
    PORTD.PIN6CTRL = 0x00;
    PORTD.PIN7CTRL = 0x00;
    PORTE.PIN0CTRL = 0x00;
    PORTE.PIN1CTRL = 0x00;
    PORTE.PIN2CTRL = 0x00;
    PORTE.PIN3CTRL = 0x00;
    PORTE.PIN4CTRL = 0x00;
    PORTE.PIN5CTRL = 0x00;
    PORTE.PIN6CTRL = 0x00;
    PORTE.PIN7CTRL = 0x00;
    PORTF.PIN0CTRL = 0x00;
    PORTF.PIN1CTRL = 0x00;
    PORTF.PIN2CTRL = 0x00;
    PORTF.PIN3CTRL = 0x00;
    PORTF.PIN4CTRL = 0x0B;
    PORTF.PIN5CTRL = 0x0B;
    PORTF.PIN6CTRL = 0x00;
    PORTF.PIN7CTRL = 0x00;

    /* PORTMUX Initialization */
    PORTMUX.CCLROUTEA = 0x00;
    PORTMUX.EVSYSROUTEA = 0x00;
    PORTMUX.TCAROUTEA = 0x00;
    PORTMUX.TCBROUTEA = 0x00;
    PORTMUX.TWISPIROUTEA = 0x00;
    PORTMUX.USARTROUTEA = 0x00;

    // register default ISC callback functions at runtime; use these methods to register a custom function
    PORTD_DEncDOutD_SetInterruptHandler(PORTD_DEncDOutD_DefaultInterruptHandler);
    PORTB_KeyS_A_SetInterruptHandler(PORTB_KeyS_A_DefaultInterruptHandler);
    PORTD_DEncDOutC_SetInterruptHandler(PORTD_DEncDOutC_DefaultInterruptHandler);
    PORTB_BckConv_EN_SetInterruptHandler(PORTB_BckConv_EN_DefaultInterruptHandler);
    PORTD_DEncDOutEnable_SetInterruptHandler(PORTD_DEncDOutEnable_DefaultInterruptHandler);
    PORTD_DEncDOutE_SetInterruptHandler(PORTD_DEncDOutE_DefaultInterruptHandler);
    PORTB_KeyS_B_SetInterruptHandler(PORTB_KeyS_B_DefaultInterruptHandler);
    PORTE_IO_PE0_SetInterruptHandler(PORTE_IO_PE0_DefaultInterruptHandler);
    PORTE_IO_PE2_SetInterruptHandler(PORTE_IO_PE2_DefaultInterruptHandler);
    PORTC_PC0_SetInterruptHandler(PORTC_PC0_DefaultInterruptHandler);
    PORTE_IO_PE1_SetInterruptHandler(PORTE_IO_PE1_DefaultInterruptHandler);
    PORTA_PA0_SetInterruptHandler(PORTA_PA0_DefaultInterruptHandler);
    PORTE_IO_PE3_SetInterruptHandler(PORTE_IO_PE3_DefaultInterruptHandler);
    PORTC_PC1_SetInterruptHandler(PORTC_PC1_DefaultInterruptHandler);
    PORTC_IO_PC4_SetInterruptHandler(PORTC_IO_PC4_DefaultInterruptHandler);
    PORTA_PA2_SetInterruptHandler(PORTA_PA2_DefaultInterruptHandler);
    PORTA_PA1_SetInterruptHandler(PORTA_PA1_DefaultInterruptHandler);
    PORTC_PC3_SetInterruptHandler(PORTC_PC3_DefaultInterruptHandler);
    PORTC_IO_PC6_SetInterruptHandler(PORTC_IO_PC6_DefaultInterruptHandler);
    PORTC_IO_PC5_SetInterruptHandler(PORTC_IO_PC5_DefaultInterruptHandler);
    PORTC_IO_PC7_SetInterruptHandler(PORTC_IO_PC7_DefaultInterruptHandler);
    PORTF_IO_PF1_SetInterruptHandler(PORTF_IO_PF1_DefaultInterruptHandler);
    PORTF_IO_PF0_SetInterruptHandler(PORTF_IO_PF0_DefaultInterruptHandler);
    PORTF_LED_S_SetInterruptHandler(PORTF_LED_S_DefaultInterruptHandler);
    PORTD_DEncDAvail_SetInterruptHandler(PORTD_DEncDAvail_DefaultInterruptHandler);
    PORTF_IO_PF2_SetInterruptHandler(PORTF_IO_PF2_DefaultInterruptHandler);
    PORTD_PD0_SetInterruptHandler(PORTD_PD0_DefaultInterruptHandler);
    PORTD_DEncDOutB_SetInterruptHandler(PORTD_DEncDOutB_DefaultInterruptHandler);
    PORTB_IGN_SNS_SetInterruptHandler(PORTB_IGN_SNS_DefaultInterruptHandler);
    PORTF_PWR_BTN_SetInterruptHandler(PORTF_PWR_BTN_DefaultInterruptHandler);
    PORTD_DEncDOutA_SetInterruptHandler(PORTD_DEncDOutA_DefaultInterruptHandler);
    PORTB_RPI_RUN_SetInterruptHandler(PORTB_RPI_RUN_DefaultInterruptHandler);
}

void PORT_Initialize(void)
{
    /* On AVR devices all peripherals are enable from power on reset, this
     * disables all peripherals to save power. Driver shall enable
     * peripheral if used */

    /* Set all pins to low power mode */
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTE + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTF + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTA + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTB + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTC + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
    for (uint8_t i = 0; i < 8; i++) {
        *((uint8_t *)&PORTD + 0x10 + i) |= 1 << PORT_PULLUPEN_bp;
    }
    
}

/**
  Allows selecting an interrupt handler for PORTD_DEncDOutD at application runtime
*/
void PORTD_DEncDOutD_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_DEncDOutD_InterruptHandler = interruptHandler;
}

void PORTD_DEncDOutD_DefaultInterruptHandler(void)
{
    // add your PORTD_DEncDOutD interrupt custom code
    // or set custom function using PORTD_DEncDOutD_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_KeyS_A at application runtime
*/
void PORTB_KeyS_A_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_KeyS_A_InterruptHandler = interruptHandler;
}

void PORTB_KeyS_A_DefaultInterruptHandler(void)
{
    // add your PORTB_KeyS_A interrupt custom code
    // or set custom function using PORTB_KeyS_A_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_DEncDOutC at application runtime
*/
void PORTD_DEncDOutC_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_DEncDOutC_InterruptHandler = interruptHandler;
}

void PORTD_DEncDOutC_DefaultInterruptHandler(void)
{
    // add your PORTD_DEncDOutC interrupt custom code
    // or set custom function using PORTD_DEncDOutC_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_BckConv_EN at application runtime
*/
void PORTB_BckConv_EN_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_BckConv_EN_InterruptHandler = interruptHandler;
}

void PORTB_BckConv_EN_DefaultInterruptHandler(void)
{
    // add your PORTB_BckConv_EN interrupt custom code
    // or set custom function using PORTB_BckConv_EN_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_DEncDOutEnable at application runtime
*/
void PORTD_DEncDOutEnable_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_DEncDOutEnable_InterruptHandler = interruptHandler;
}

void PORTD_DEncDOutEnable_DefaultInterruptHandler(void)
{
    // add your PORTD_DEncDOutEnable interrupt custom code
    // or set custom function using PORTD_DEncDOutEnable_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_DEncDOutE at application runtime
*/
void PORTD_DEncDOutE_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_DEncDOutE_InterruptHandler = interruptHandler;
}

void PORTD_DEncDOutE_DefaultInterruptHandler(void)
{
    // add your PORTD_DEncDOutE interrupt custom code
    // or set custom function using PORTD_DEncDOutE_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_KeyS_B at application runtime
*/
void PORTB_KeyS_B_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_KeyS_B_InterruptHandler = interruptHandler;
}

void PORTB_KeyS_B_DefaultInterruptHandler(void)
{
    // add your PORTB_KeyS_B interrupt custom code
    // or set custom function using PORTB_KeyS_B_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTE_IO_PE0 at application runtime
*/
void PORTE_IO_PE0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTE_IO_PE0_InterruptHandler = interruptHandler;
}

void PORTE_IO_PE0_DefaultInterruptHandler(void)
{
    // add your PORTE_IO_PE0 interrupt custom code
    // or set custom function using PORTE_IO_PE0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTE_IO_PE2 at application runtime
*/
void PORTE_IO_PE2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTE_IO_PE2_InterruptHandler = interruptHandler;
}

void PORTE_IO_PE2_DefaultInterruptHandler(void)
{
    // add your PORTE_IO_PE2 interrupt custom code
    // or set custom function using PORTE_IO_PE2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_PC0 at application runtime
*/
void PORTC_PC0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_PC0_InterruptHandler = interruptHandler;
}

void PORTC_PC0_DefaultInterruptHandler(void)
{
    // add your PORTC_PC0 interrupt custom code
    // or set custom function using PORTC_PC0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTE_IO_PE1 at application runtime
*/
void PORTE_IO_PE1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTE_IO_PE1_InterruptHandler = interruptHandler;
}

void PORTE_IO_PE1_DefaultInterruptHandler(void)
{
    // add your PORTE_IO_PE1 interrupt custom code
    // or set custom function using PORTE_IO_PE1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA0 at application runtime
*/
void PORTA_PA0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA0_InterruptHandler = interruptHandler;
}

void PORTA_PA0_DefaultInterruptHandler(void)
{
    // add your PORTA_PA0 interrupt custom code
    // or set custom function using PORTA_PA0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTE_IO_PE3 at application runtime
*/
void PORTE_IO_PE3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTE_IO_PE3_InterruptHandler = interruptHandler;
}

void PORTE_IO_PE3_DefaultInterruptHandler(void)
{
    // add your PORTE_IO_PE3 interrupt custom code
    // or set custom function using PORTE_IO_PE3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_PC1 at application runtime
*/
void PORTC_PC1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_PC1_InterruptHandler = interruptHandler;
}

void PORTC_PC1_DefaultInterruptHandler(void)
{
    // add your PORTC_PC1 interrupt custom code
    // or set custom function using PORTC_PC1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_IO_PC4 at application runtime
*/
void PORTC_IO_PC4_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_IO_PC4_InterruptHandler = interruptHandler;
}

void PORTC_IO_PC4_DefaultInterruptHandler(void)
{
    // add your PORTC_IO_PC4 interrupt custom code
    // or set custom function using PORTC_IO_PC4_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA2 at application runtime
*/
void PORTA_PA2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA2_InterruptHandler = interruptHandler;
}

void PORTA_PA2_DefaultInterruptHandler(void)
{
    // add your PORTA_PA2 interrupt custom code
    // or set custom function using PORTA_PA2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTA_PA1 at application runtime
*/
void PORTA_PA1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTA_PA1_InterruptHandler = interruptHandler;
}

void PORTA_PA1_DefaultInterruptHandler(void)
{
    // add your PORTA_PA1 interrupt custom code
    // or set custom function using PORTA_PA1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_PC3 at application runtime
*/
void PORTC_PC3_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_PC3_InterruptHandler = interruptHandler;
}

void PORTC_PC3_DefaultInterruptHandler(void)
{
    // add your PORTC_PC3 interrupt custom code
    // or set custom function using PORTC_PC3_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_IO_PC6 at application runtime
*/
void PORTC_IO_PC6_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_IO_PC6_InterruptHandler = interruptHandler;
}

void PORTC_IO_PC6_DefaultInterruptHandler(void)
{
    // add your PORTC_IO_PC6 interrupt custom code
    // or set custom function using PORTC_IO_PC6_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_IO_PC5 at application runtime
*/
void PORTC_IO_PC5_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_IO_PC5_InterruptHandler = interruptHandler;
}

void PORTC_IO_PC5_DefaultInterruptHandler(void)
{
    // add your PORTC_IO_PC5 interrupt custom code
    // or set custom function using PORTC_IO_PC5_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTC_IO_PC7 at application runtime
*/
void PORTC_IO_PC7_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTC_IO_PC7_InterruptHandler = interruptHandler;
}

void PORTC_IO_PC7_DefaultInterruptHandler(void)
{
    // add your PORTC_IO_PC7 interrupt custom code
    // or set custom function using PORTC_IO_PC7_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_IO_PF1 at application runtime
*/
void PORTF_IO_PF1_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_IO_PF1_InterruptHandler = interruptHandler;
}

void PORTF_IO_PF1_DefaultInterruptHandler(void)
{
    // add your PORTF_IO_PF1 interrupt custom code
    // or set custom function using PORTF_IO_PF1_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_IO_PF0 at application runtime
*/
void PORTF_IO_PF0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_IO_PF0_InterruptHandler = interruptHandler;
}

void PORTF_IO_PF0_DefaultInterruptHandler(void)
{
    // add your PORTF_IO_PF0 interrupt custom code
    // or set custom function using PORTF_IO_PF0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_LED_S at application runtime
*/
void PORTF_LED_S_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_LED_S_InterruptHandler = interruptHandler;
}

void PORTF_LED_S_DefaultInterruptHandler(void)
{
    // add your PORTF_LED_S interrupt custom code
    // or set custom function using PORTF_LED_S_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_DEncDAvail at application runtime
*/
void PORTD_DEncDAvail_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_DEncDAvail_InterruptHandler = interruptHandler;
}

void PORTD_DEncDAvail_DefaultInterruptHandler(void)
{
    // add your PORTD_DEncDAvail interrupt custom code
    // or set custom function using PORTD_DEncDAvail_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_IO_PF2 at application runtime
*/
void PORTF_IO_PF2_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_IO_PF2_InterruptHandler = interruptHandler;
}

void PORTF_IO_PF2_DefaultInterruptHandler(void)
{
    // add your PORTF_IO_PF2 interrupt custom code
    // or set custom function using PORTF_IO_PF2_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_PD0 at application runtime
*/
void PORTD_PD0_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_PD0_InterruptHandler = interruptHandler;
}

void PORTD_PD0_DefaultInterruptHandler(void)
{
    // add your PORTD_PD0 interrupt custom code
    // or set custom function using PORTD_PD0_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_DEncDOutB at application runtime
*/
void PORTD_DEncDOutB_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_DEncDOutB_InterruptHandler = interruptHandler;
}

void PORTD_DEncDOutB_DefaultInterruptHandler(void)
{
    // add your PORTD_DEncDOutB interrupt custom code
    // or set custom function using PORTD_DEncDOutB_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_IGN_SNS at application runtime
*/
void PORTB_IGN_SNS_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_IGN_SNS_InterruptHandler = interruptHandler;
}

void PORTB_IGN_SNS_DefaultInterruptHandler(void)
{
    // add your PORTB_IGN_SNS interrupt custom code
    // or set custom function using PORTB_IGN_SNS_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTF_PWR_BTN at application runtime
*/
void PORTF_PWR_BTN_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTF_PWR_BTN_InterruptHandler = interruptHandler;
}

void PORTF_PWR_BTN_DefaultInterruptHandler(void)
{
    // add your PORTF_PWR_BTN interrupt custom code
    // or set custom function using PORTF_PWR_BTN_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTD_DEncDOutA at application runtime
*/
void PORTD_DEncDOutA_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTD_DEncDOutA_InterruptHandler = interruptHandler;
}

void PORTD_DEncDOutA_DefaultInterruptHandler(void)
{
    // add your PORTD_DEncDOutA interrupt custom code
    // or set custom function using PORTD_DEncDOutA_SetInterruptHandler()
}
/**
  Allows selecting an interrupt handler for PORTB_RPI_RUN at application runtime
*/
void PORTB_RPI_RUN_SetInterruptHandler(void (* interruptHandler)(void)) 
{
    PORTB_RPI_RUN_InterruptHandler = interruptHandler;
}

void PORTB_RPI_RUN_DefaultInterruptHandler(void)
{
    // add your PORTB_RPI_RUN interrupt custom code
    // or set custom function using PORTB_RPI_RUN_SetInterruptHandler()
}
ISR(PORTF_PORT_vect)
{  
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTF.INTFLAGS & PORT_INT1_bm)
    {
       PORTF_IO_PF1_InterruptHandler();
    }
    if(VPORTF.INTFLAGS & PORT_INT0_bm)
    {
       PORTF_IO_PF0_InterruptHandler();
    }
    if(VPORTF.INTFLAGS & PORT_INT3_bm)
    {
       PORTF_LED_S_InterruptHandler();
    }
    if(VPORTF.INTFLAGS & PORT_INT2_bm)
    {
       PORTF_IO_PF2_InterruptHandler();
    }
    if(VPORTF.INTFLAGS & PORT_INT4_bm)
    {
       PORTF_PWR_BTN_InterruptHandler();
    }

    /* Clear interrupt flags */
    VPORTF.INTFLAGS = 0xff;
}

ISR(PORTB_PORT_vect)
{  
    // Call the interrupt handler for the callback registered at runtime
    if(VPORTB.INTFLAGS & PORT_INT3_bm)
    {
       PORTB_KeyS_A_InterruptHandler();
    }
    if(VPORTB.INTFLAGS & PORT_INT2_bm)
    {
       PORTB_BckConv_EN_InterruptHandler();
    }
    if(VPORTB.INTFLAGS & PORT_INT4_bm)
    {
       PORTB_KeyS_B_InterruptHandler();
    }
    if(VPORTB.INTFLAGS & PORT_INT1_bm)
    {
       PORTB_IGN_SNS_InterruptHandler();
    }
    if(VPORTB.INTFLAGS & PORT_INT0_bm)
    {
       PORTB_RPI_RUN_InterruptHandler();
    }

    /* Clear interrupt flags */
    VPORTB.INTFLAGS = 0xff;
}

