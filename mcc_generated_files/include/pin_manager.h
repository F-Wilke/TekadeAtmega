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

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "port.h"

//get/set DEncDOutD aliases
#define DEncDOutD_SetHigh() do { PORTD_OUTSET = 0x20; } while(0)
#define DEncDOutD_SetLow() do { PORTD_OUTCLR = 0x20; } while(0)
#define DEncDOutD_Toggle() do { PORTD_OUTTGL = 0x20; } while(0)
#define DEncDOutD_GetValue() (VPORTD.IN & (0x1 << 5))
#define DEncDOutD_SetDigitalInput() do { PORTD_DIRCLR = 0x20; } while(0)
#define DEncDOutD_SetDigitalOutput() do { PORTD_DIRSET = 0x20; } while(0)
#define DEncDOutD_SetPullUp() do { PORTD_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define DEncDOutD_ResetPullUp() do { PORTD_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define DEncDOutD_SetInverted() do { PORTD_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define DEncDOutD_ResetInverted() do { PORTD_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define DEncDOutD_DisableInterruptOnChange() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define DEncDOutD_EnableInterruptForBothEdges() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define DEncDOutD_EnableInterruptForRisingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define DEncDOutD_EnableInterruptForFallingEdge() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define DEncDOutD_DisableDigitalInputBuffer() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define DEncDOutD_EnableInterruptForLowLevelSensing() do { PORTD.PIN5CTRL = (PORTD.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set KeyS_A aliases
#define KeyS_A_SetHigh() do { PORTB_OUTSET = 0x8; } while(0)
#define KeyS_A_SetLow() do { PORTB_OUTCLR = 0x8; } while(0)
#define KeyS_A_Toggle() do { PORTB_OUTTGL = 0x8; } while(0)
#define KeyS_A_GetValue() (VPORTB.IN & (0x1 << 3))
#define KeyS_A_SetDigitalInput() do { PORTB_DIRCLR = 0x8; } while(0)
#define KeyS_A_SetDigitalOutput() do { PORTB_DIRSET = 0x8; } while(0)
#define KeyS_A_SetPullUp() do { PORTB_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define KeyS_A_ResetPullUp() do { PORTB_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define KeyS_A_SetInverted() do { PORTB_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define KeyS_A_ResetInverted() do { PORTB_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define KeyS_A_DisableInterruptOnChange() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define KeyS_A_EnableInterruptForBothEdges() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define KeyS_A_EnableInterruptForRisingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define KeyS_A_EnableInterruptForFallingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define KeyS_A_DisableDigitalInputBuffer() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define KeyS_A_EnableInterruptForLowLevelSensing() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set DEncDOutC aliases
#define DEncDOutC_SetHigh() do { PORTD_OUTSET = 0x10; } while(0)
#define DEncDOutC_SetLow() do { PORTD_OUTCLR = 0x10; } while(0)
#define DEncDOutC_Toggle() do { PORTD_OUTTGL = 0x10; } while(0)
#define DEncDOutC_GetValue() (VPORTD.IN & (0x1 << 4))
#define DEncDOutC_SetDigitalInput() do { PORTD_DIRCLR = 0x10; } while(0)
#define DEncDOutC_SetDigitalOutput() do { PORTD_DIRSET = 0x10; } while(0)
#define DEncDOutC_SetPullUp() do { PORTD_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define DEncDOutC_ResetPullUp() do { PORTD_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define DEncDOutC_SetInverted() do { PORTD_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define DEncDOutC_ResetInverted() do { PORTD_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define DEncDOutC_DisableInterruptOnChange() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define DEncDOutC_EnableInterruptForBothEdges() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define DEncDOutC_EnableInterruptForRisingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define DEncDOutC_EnableInterruptForFallingEdge() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define DEncDOutC_DisableDigitalInputBuffer() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define DEncDOutC_EnableInterruptForLowLevelSensing() do { PORTD.PIN4CTRL = (PORTD.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set BckConv_EN aliases
#define BckConv_EN_SetHigh() do { PORTB_OUTSET = 0x4; } while(0)
#define BckConv_EN_SetLow() do { PORTB_OUTCLR = 0x4; } while(0)
#define BckConv_EN_Toggle() do { PORTB_OUTTGL = 0x4; } while(0)
#define BckConv_EN_GetValue() (VPORTB.IN & (0x1 << 2))
#define BckConv_EN_SetDigitalInput() do { PORTB_DIRCLR = 0x4; } while(0)
#define BckConv_EN_SetDigitalOutput() do { PORTB_DIRSET = 0x4; } while(0)
#define BckConv_EN_SetPullUp() do { PORTB_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define BckConv_EN_ResetPullUp() do { PORTB_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define BckConv_EN_SetInverted() do { PORTB_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define BckConv_EN_ResetInverted() do { PORTB_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define BckConv_EN_DisableInterruptOnChange() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define BckConv_EN_EnableInterruptForBothEdges() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define BckConv_EN_EnableInterruptForRisingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define BckConv_EN_EnableInterruptForFallingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define BckConv_EN_DisableDigitalInputBuffer() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define BckConv_EN_EnableInterruptForLowLevelSensing() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set DEncDOutEnable aliases
#define DEncDOutEnable_SetHigh() do { PORTD_OUTSET = 0x80; } while(0)
#define DEncDOutEnable_SetLow() do { PORTD_OUTCLR = 0x80; } while(0)
#define DEncDOutEnable_Toggle() do { PORTD_OUTTGL = 0x80; } while(0)
#define DEncDOutEnable_GetValue() (VPORTD.IN & (0x1 << 7))
#define DEncDOutEnable_SetDigitalInput() do { PORTD_DIRCLR = 0x80; } while(0)
#define DEncDOutEnable_SetDigitalOutput() do { PORTD_DIRSET = 0x80; } while(0)
#define DEncDOutEnable_SetPullUp() do { PORTD_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define DEncDOutEnable_ResetPullUp() do { PORTD_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define DEncDOutEnable_SetInverted() do { PORTD_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define DEncDOutEnable_ResetInverted() do { PORTD_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define DEncDOutEnable_DisableInterruptOnChange() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define DEncDOutEnable_EnableInterruptForBothEdges() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define DEncDOutEnable_EnableInterruptForRisingEdge() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define DEncDOutEnable_EnableInterruptForFallingEdge() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define DEncDOutEnable_DisableDigitalInputBuffer() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define DEncDOutEnable_EnableInterruptForLowLevelSensing() do { PORTD.PIN7CTRL = (PORTD.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set DEncDOutE aliases
#define DEncDOutE_SetHigh() do { PORTD_OUTSET = 0x40; } while(0)
#define DEncDOutE_SetLow() do { PORTD_OUTCLR = 0x40; } while(0)
#define DEncDOutE_Toggle() do { PORTD_OUTTGL = 0x40; } while(0)
#define DEncDOutE_GetValue() (VPORTD.IN & (0x1 << 6))
#define DEncDOutE_SetDigitalInput() do { PORTD_DIRCLR = 0x40; } while(0)
#define DEncDOutE_SetDigitalOutput() do { PORTD_DIRSET = 0x40; } while(0)
#define DEncDOutE_SetPullUp() do { PORTD_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define DEncDOutE_ResetPullUp() do { PORTD_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define DEncDOutE_SetInverted() do { PORTD_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define DEncDOutE_ResetInverted() do { PORTD_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define DEncDOutE_DisableInterruptOnChange() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define DEncDOutE_EnableInterruptForBothEdges() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define DEncDOutE_EnableInterruptForRisingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define DEncDOutE_EnableInterruptForFallingEdge() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define DEncDOutE_DisableDigitalInputBuffer() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define DEncDOutE_EnableInterruptForLowLevelSensing() do { PORTD.PIN6CTRL = (PORTD.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set KeyS_B aliases
#define KeyS_B_SetHigh() do { PORTB_OUTSET = 0x10; } while(0)
#define KeyS_B_SetLow() do { PORTB_OUTCLR = 0x10; } while(0)
#define KeyS_B_Toggle() do { PORTB_OUTTGL = 0x10; } while(0)
#define KeyS_B_GetValue() (VPORTB.IN & (0x1 << 4))
#define KeyS_B_SetDigitalInput() do { PORTB_DIRCLR = 0x10; } while(0)
#define KeyS_B_SetDigitalOutput() do { PORTB_DIRSET = 0x10; } while(0)
#define KeyS_B_SetPullUp() do { PORTB_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define KeyS_B_ResetPullUp() do { PORTB_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define KeyS_B_SetInverted() do { PORTB_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define KeyS_B_ResetInverted() do { PORTB_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define KeyS_B_DisableInterruptOnChange() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define KeyS_B_EnableInterruptForBothEdges() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define KeyS_B_EnableInterruptForRisingEdge() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define KeyS_B_EnableInterruptForFallingEdge() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define KeyS_B_DisableDigitalInputBuffer() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define KeyS_B_EnableInterruptForLowLevelSensing() do { PORTB.PIN4CTRL = (PORTB.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PE0 aliases
#define IO_PE0_SetHigh() do { PORTE_OUTSET = 0x1; } while(0)
#define IO_PE0_SetLow() do { PORTE_OUTCLR = 0x1; } while(0)
#define IO_PE0_Toggle() do { PORTE_OUTTGL = 0x1; } while(0)
#define IO_PE0_GetValue() (VPORTE.IN & (0x1 << 0))
#define IO_PE0_SetDigitalInput() do { PORTE_DIRCLR = 0x1; } while(0)
#define IO_PE0_SetDigitalOutput() do { PORTE_DIRSET = 0x1; } while(0)
#define IO_PE0_SetPullUp() do { PORTE_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PE0_ResetPullUp() do { PORTE_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PE0_SetInverted() do { PORTE_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PE0_ResetInverted() do { PORTE_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PE0_DisableInterruptOnChange() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PE0_EnableInterruptForBothEdges() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PE0_EnableInterruptForRisingEdge() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PE0_EnableInterruptForFallingEdge() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PE0_DisableDigitalInputBuffer() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PE0_EnableInterruptForLowLevelSensing() do { PORTE.PIN0CTRL = (PORTE.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PE2 aliases
#define IO_PE2_SetHigh() do { PORTE_OUTSET = 0x4; } while(0)
#define IO_PE2_SetLow() do { PORTE_OUTCLR = 0x4; } while(0)
#define IO_PE2_Toggle() do { PORTE_OUTTGL = 0x4; } while(0)
#define IO_PE2_GetValue() (VPORTE.IN & (0x1 << 2))
#define IO_PE2_SetDigitalInput() do { PORTE_DIRCLR = 0x4; } while(0)
#define IO_PE2_SetDigitalOutput() do { PORTE_DIRSET = 0x4; } while(0)
#define IO_PE2_SetPullUp() do { PORTE_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PE2_ResetPullUp() do { PORTE_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PE2_SetInverted() do { PORTE_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PE2_ResetInverted() do { PORTE_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PE2_DisableInterruptOnChange() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PE2_EnableInterruptForBothEdges() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PE2_EnableInterruptForRisingEdge() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PE2_EnableInterruptForFallingEdge() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PE2_DisableDigitalInputBuffer() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PE2_EnableInterruptForLowLevelSensing() do { PORTE.PIN2CTRL = (PORTE.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PC0 aliases
#define PC0_SetHigh() do { PORTC_OUTSET = 0x1; } while(0)
#define PC0_SetLow() do { PORTC_OUTCLR = 0x1; } while(0)
#define PC0_Toggle() do { PORTC_OUTTGL = 0x1; } while(0)
#define PC0_GetValue() (VPORTC.IN & (0x1 << 0))
#define PC0_SetDigitalInput() do { PORTC_DIRCLR = 0x1; } while(0)
#define PC0_SetDigitalOutput() do { PORTC_DIRSET = 0x1; } while(0)
#define PC0_SetPullUp() do { PORTC_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PC0_ResetPullUp() do { PORTC_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PC0_SetInverted() do { PORTC_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define PC0_ResetInverted() do { PORTC_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PC0_DisableInterruptOnChange() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PC0_EnableInterruptForBothEdges() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PC0_EnableInterruptForRisingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PC0_EnableInterruptForFallingEdge() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PC0_DisableDigitalInputBuffer() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PC0_EnableInterruptForLowLevelSensing() do { PORTC.PIN0CTRL = (PORTC.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PE1 aliases
#define IO_PE1_SetHigh() do { PORTE_OUTSET = 0x2; } while(0)
#define IO_PE1_SetLow() do { PORTE_OUTCLR = 0x2; } while(0)
#define IO_PE1_Toggle() do { PORTE_OUTTGL = 0x2; } while(0)
#define IO_PE1_GetValue() (VPORTE.IN & (0x1 << 1))
#define IO_PE1_SetDigitalInput() do { PORTE_DIRCLR = 0x2; } while(0)
#define IO_PE1_SetDigitalOutput() do { PORTE_DIRSET = 0x2; } while(0)
#define IO_PE1_SetPullUp() do { PORTE_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PE1_ResetPullUp() do { PORTE_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PE1_SetInverted() do { PORTE_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PE1_ResetInverted() do { PORTE_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PE1_DisableInterruptOnChange() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PE1_EnableInterruptForBothEdges() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PE1_EnableInterruptForRisingEdge() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PE1_EnableInterruptForFallingEdge() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PE1_DisableDigitalInputBuffer() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PE1_EnableInterruptForLowLevelSensing() do { PORTE.PIN1CTRL = (PORTE.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA0 aliases
#define PA0_SetHigh() do { PORTA_OUTSET = 0x1; } while(0)
#define PA0_SetLow() do { PORTA_OUTCLR = 0x1; } while(0)
#define PA0_Toggle() do { PORTA_OUTTGL = 0x1; } while(0)
#define PA0_GetValue() (VPORTA.IN & (0x1 << 0))
#define PA0_SetDigitalInput() do { PORTA_DIRCLR = 0x1; } while(0)
#define PA0_SetDigitalOutput() do { PORTA_DIRSET = 0x1; } while(0)
#define PA0_SetPullUp() do { PORTA_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA0_ResetPullUp() do { PORTA_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA0_SetInverted() do { PORTA_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define PA0_ResetInverted() do { PORTA_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA0_DisableInterruptOnChange() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA0_EnableInterruptForBothEdges() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA0_EnableInterruptForRisingEdge() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA0_EnableInterruptForFallingEdge() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA0_DisableDigitalInputBuffer() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA0_EnableInterruptForLowLevelSensing() do { PORTA.PIN0CTRL = (PORTA.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PE3 aliases
#define IO_PE3_SetHigh() do { PORTE_OUTSET = 0x8; } while(0)
#define IO_PE3_SetLow() do { PORTE_OUTCLR = 0x8; } while(0)
#define IO_PE3_Toggle() do { PORTE_OUTTGL = 0x8; } while(0)
#define IO_PE3_GetValue() (VPORTE.IN & (0x1 << 3))
#define IO_PE3_SetDigitalInput() do { PORTE_DIRCLR = 0x8; } while(0)
#define IO_PE3_SetDigitalOutput() do { PORTE_DIRSET = 0x8; } while(0)
#define IO_PE3_SetPullUp() do { PORTE_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PE3_ResetPullUp() do { PORTE_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PE3_SetInverted() do { PORTE_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PE3_ResetInverted() do { PORTE_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PE3_DisableInterruptOnChange() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PE3_EnableInterruptForBothEdges() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PE3_EnableInterruptForRisingEdge() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PE3_EnableInterruptForFallingEdge() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PE3_DisableDigitalInputBuffer() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PE3_EnableInterruptForLowLevelSensing() do { PORTE.PIN3CTRL = (PORTE.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PC1 aliases
#define PC1_SetHigh() do { PORTC_OUTSET = 0x2; } while(0)
#define PC1_SetLow() do { PORTC_OUTCLR = 0x2; } while(0)
#define PC1_Toggle() do { PORTC_OUTTGL = 0x2; } while(0)
#define PC1_GetValue() (VPORTC.IN & (0x1 << 1))
#define PC1_SetDigitalInput() do { PORTC_DIRCLR = 0x2; } while(0)
#define PC1_SetDigitalOutput() do { PORTC_DIRSET = 0x2; } while(0)
#define PC1_SetPullUp() do { PORTC_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PC1_ResetPullUp() do { PORTC_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PC1_SetInverted() do { PORTC_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define PC1_ResetInverted() do { PORTC_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PC1_DisableInterruptOnChange() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PC1_EnableInterruptForBothEdges() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PC1_EnableInterruptForRisingEdge() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PC1_EnableInterruptForFallingEdge() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PC1_DisableDigitalInputBuffer() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PC1_EnableInterruptForLowLevelSensing() do { PORTC.PIN1CTRL = (PORTC.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PC4 aliases
#define IO_PC4_SetHigh() do { PORTC_OUTSET = 0x10; } while(0)
#define IO_PC4_SetLow() do { PORTC_OUTCLR = 0x10; } while(0)
#define IO_PC4_Toggle() do { PORTC_OUTTGL = 0x10; } while(0)
#define IO_PC4_GetValue() (VPORTC.IN & (0x1 << 4))
#define IO_PC4_SetDigitalInput() do { PORTC_DIRCLR = 0x10; } while(0)
#define IO_PC4_SetDigitalOutput() do { PORTC_DIRSET = 0x10; } while(0)
#define IO_PC4_SetPullUp() do { PORTC_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PC4_ResetPullUp() do { PORTC_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PC4_SetInverted() do { PORTC_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PC4_ResetInverted() do { PORTC_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PC4_DisableInterruptOnChange() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PC4_EnableInterruptForBothEdges() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PC4_EnableInterruptForRisingEdge() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PC4_EnableInterruptForFallingEdge() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PC4_DisableDigitalInputBuffer() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PC4_EnableInterruptForLowLevelSensing() do { PORTC.PIN4CTRL = (PORTC.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA2 aliases
#define PA2_SetHigh() do { PORTA_OUTSET = 0x4; } while(0)
#define PA2_SetLow() do { PORTA_OUTCLR = 0x4; } while(0)
#define PA2_Toggle() do { PORTA_OUTTGL = 0x4; } while(0)
#define PA2_GetValue() (VPORTA.IN & (0x1 << 2))
#define PA2_SetDigitalInput() do { PORTA_DIRCLR = 0x4; } while(0)
#define PA2_SetDigitalOutput() do { PORTA_DIRSET = 0x4; } while(0)
#define PA2_SetPullUp() do { PORTA_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA2_ResetPullUp() do { PORTA_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA2_SetInverted() do { PORTA_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define PA2_ResetInverted() do { PORTA_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA2_DisableInterruptOnChange() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA2_EnableInterruptForBothEdges() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA2_EnableInterruptForRisingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA2_EnableInterruptForFallingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA2_DisableDigitalInputBuffer() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA2_EnableInterruptForLowLevelSensing() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PA1 aliases
#define PA1_SetHigh() do { PORTA_OUTSET = 0x2; } while(0)
#define PA1_SetLow() do { PORTA_OUTCLR = 0x2; } while(0)
#define PA1_Toggle() do { PORTA_OUTTGL = 0x2; } while(0)
#define PA1_GetValue() (VPORTA.IN & (0x1 << 1))
#define PA1_SetDigitalInput() do { PORTA_DIRCLR = 0x2; } while(0)
#define PA1_SetDigitalOutput() do { PORTA_DIRSET = 0x2; } while(0)
#define PA1_SetPullUp() do { PORTA_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PA1_ResetPullUp() do { PORTA_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PA1_SetInverted() do { PORTA_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define PA1_ResetInverted() do { PORTA_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PA1_DisableInterruptOnChange() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PA1_EnableInterruptForBothEdges() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PA1_EnableInterruptForRisingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PA1_EnableInterruptForFallingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PA1_DisableDigitalInputBuffer() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PA1_EnableInterruptForLowLevelSensing() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PC3 aliases
#define PC3_SetHigh() do { PORTC_OUTSET = 0x8; } while(0)
#define PC3_SetLow() do { PORTC_OUTCLR = 0x8; } while(0)
#define PC3_Toggle() do { PORTC_OUTTGL = 0x8; } while(0)
#define PC3_GetValue() (VPORTC.IN & (0x1 << 3))
#define PC3_SetDigitalInput() do { PORTC_DIRCLR = 0x8; } while(0)
#define PC3_SetDigitalOutput() do { PORTC_DIRSET = 0x8; } while(0)
#define PC3_SetPullUp() do { PORTC_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PC3_ResetPullUp() do { PORTC_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PC3_SetInverted() do { PORTC_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define PC3_ResetInverted() do { PORTC_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PC3_DisableInterruptOnChange() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PC3_EnableInterruptForBothEdges() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PC3_EnableInterruptForRisingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PC3_EnableInterruptForFallingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PC3_DisableDigitalInputBuffer() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PC3_EnableInterruptForLowLevelSensing() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PC6 aliases
#define IO_PC6_SetHigh() do { PORTC_OUTSET = 0x40; } while(0)
#define IO_PC6_SetLow() do { PORTC_OUTCLR = 0x40; } while(0)
#define IO_PC6_Toggle() do { PORTC_OUTTGL = 0x40; } while(0)
#define IO_PC6_GetValue() (VPORTC.IN & (0x1 << 6))
#define IO_PC6_SetDigitalInput() do { PORTC_DIRCLR = 0x40; } while(0)
#define IO_PC6_SetDigitalOutput() do { PORTC_DIRSET = 0x40; } while(0)
#define IO_PC6_SetPullUp() do { PORTC_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PC6_ResetPullUp() do { PORTC_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PC6_SetInverted() do { PORTC_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PC6_ResetInverted() do { PORTC_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PC6_DisableInterruptOnChange() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PC6_EnableInterruptForBothEdges() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PC6_EnableInterruptForRisingEdge() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PC6_EnableInterruptForFallingEdge() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PC6_DisableDigitalInputBuffer() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PC6_EnableInterruptForLowLevelSensing() do { PORTC.PIN6CTRL = (PORTC.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PC5 aliases
#define IO_PC5_SetHigh() do { PORTC_OUTSET = 0x20; } while(0)
#define IO_PC5_SetLow() do { PORTC_OUTCLR = 0x20; } while(0)
#define IO_PC5_Toggle() do { PORTC_OUTTGL = 0x20; } while(0)
#define IO_PC5_GetValue() (VPORTC.IN & (0x1 << 5))
#define IO_PC5_SetDigitalInput() do { PORTC_DIRCLR = 0x20; } while(0)
#define IO_PC5_SetDigitalOutput() do { PORTC_DIRSET = 0x20; } while(0)
#define IO_PC5_SetPullUp() do { PORTC_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PC5_ResetPullUp() do { PORTC_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PC5_SetInverted() do { PORTC_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PC5_ResetInverted() do { PORTC_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PC5_DisableInterruptOnChange() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PC5_EnableInterruptForBothEdges() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PC5_EnableInterruptForRisingEdge() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PC5_EnableInterruptForFallingEdge() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PC5_DisableDigitalInputBuffer() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PC5_EnableInterruptForLowLevelSensing() do { PORTC.PIN5CTRL = (PORTC.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PC7 aliases
#define IO_PC7_SetHigh() do { PORTC_OUTSET = 0x80; } while(0)
#define IO_PC7_SetLow() do { PORTC_OUTCLR = 0x80; } while(0)
#define IO_PC7_Toggle() do { PORTC_OUTTGL = 0x80; } while(0)
#define IO_PC7_GetValue() (VPORTC.IN & (0x1 << 7))
#define IO_PC7_SetDigitalInput() do { PORTC_DIRCLR = 0x80; } while(0)
#define IO_PC7_SetDigitalOutput() do { PORTC_DIRSET = 0x80; } while(0)
#define IO_PC7_SetPullUp() do { PORTC_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PC7_ResetPullUp() do { PORTC_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PC7_SetInverted() do { PORTC_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PC7_ResetInverted() do { PORTC_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PC7_DisableInterruptOnChange() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PC7_EnableInterruptForBothEdges() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PC7_EnableInterruptForRisingEdge() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PC7_EnableInterruptForFallingEdge() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PC7_DisableDigitalInputBuffer() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PC7_EnableInterruptForLowLevelSensing() do { PORTC.PIN7CTRL = (PORTC.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PF1 aliases
#define IO_PF1_SetHigh() do { PORTF_OUTSET = 0x2; } while(0)
#define IO_PF1_SetLow() do { PORTF_OUTCLR = 0x2; } while(0)
#define IO_PF1_Toggle() do { PORTF_OUTTGL = 0x2; } while(0)
#define IO_PF1_GetValue() (VPORTF.IN & (0x1 << 1))
#define IO_PF1_SetDigitalInput() do { PORTF_DIRCLR = 0x2; } while(0)
#define IO_PF1_SetDigitalOutput() do { PORTF_DIRSET = 0x2; } while(0)
#define IO_PF1_SetPullUp() do { PORTF_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PF1_ResetPullUp() do { PORTF_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PF1_SetInverted() do { PORTF_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PF1_ResetInverted() do { PORTF_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PF1_DisableInterruptOnChange() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PF1_EnableInterruptForBothEdges() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PF1_EnableInterruptForRisingEdge() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PF1_EnableInterruptForFallingEdge() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PF1_DisableDigitalInputBuffer() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PF1_EnableInterruptForLowLevelSensing() do { PORTF.PIN1CTRL = (PORTF.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PF0 aliases
#define IO_PF0_SetHigh() do { PORTF_OUTSET = 0x1; } while(0)
#define IO_PF0_SetLow() do { PORTF_OUTCLR = 0x1; } while(0)
#define IO_PF0_Toggle() do { PORTF_OUTTGL = 0x1; } while(0)
#define IO_PF0_GetValue() (VPORTF.IN & (0x1 << 0))
#define IO_PF0_SetDigitalInput() do { PORTF_DIRCLR = 0x1; } while(0)
#define IO_PF0_SetDigitalOutput() do { PORTF_DIRSET = 0x1; } while(0)
#define IO_PF0_SetPullUp() do { PORTF_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PF0_ResetPullUp() do { PORTF_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PF0_SetInverted() do { PORTF_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PF0_ResetInverted() do { PORTF_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PF0_DisableInterruptOnChange() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PF0_EnableInterruptForBothEdges() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PF0_EnableInterruptForRisingEdge() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PF0_EnableInterruptForFallingEdge() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PF0_DisableDigitalInputBuffer() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PF0_EnableInterruptForLowLevelSensing() do { PORTF.PIN0CTRL = (PORTF.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set LED_S aliases
#define LED_S_SetHigh() do { PORTF_OUTSET = 0x8; } while(0)
#define LED_S_SetLow() do { PORTF_OUTCLR = 0x8; } while(0)
#define LED_S_Toggle() do { PORTF_OUTTGL = 0x8; } while(0)
#define LED_S_GetValue() (VPORTF.IN & (0x1 << 3))
#define LED_S_SetDigitalInput() do { PORTF_DIRCLR = 0x8; } while(0)
#define LED_S_SetDigitalOutput() do { PORTF_DIRSET = 0x8; } while(0)
#define LED_S_SetPullUp() do { PORTF_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LED_S_ResetPullUp() do { PORTF_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LED_S_SetInverted() do { PORTF_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define LED_S_ResetInverted() do { PORTF_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LED_S_DisableInterruptOnChange() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LED_S_EnableInterruptForBothEdges() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LED_S_EnableInterruptForRisingEdge() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LED_S_EnableInterruptForFallingEdge() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LED_S_DisableDigitalInputBuffer() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LED_S_EnableInterruptForLowLevelSensing() do { PORTF.PIN3CTRL = (PORTF.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set DEncDAvail aliases
#define DEncDAvail_SetHigh() do { PORTD_OUTSET = 0x2; } while(0)
#define DEncDAvail_SetLow() do { PORTD_OUTCLR = 0x2; } while(0)
#define DEncDAvail_Toggle() do { PORTD_OUTTGL = 0x2; } while(0)
#define DEncDAvail_GetValue() (VPORTD.IN & (0x1 << 1))
#define DEncDAvail_SetDigitalInput() do { PORTD_DIRCLR = 0x2; } while(0)
#define DEncDAvail_SetDigitalOutput() do { PORTD_DIRSET = 0x2; } while(0)
#define DEncDAvail_SetPullUp() do { PORTD_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define DEncDAvail_ResetPullUp() do { PORTD_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define DEncDAvail_SetInverted() do { PORTD_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define DEncDAvail_ResetInverted() do { PORTD_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define DEncDAvail_DisableInterruptOnChange() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define DEncDAvail_EnableInterruptForBothEdges() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define DEncDAvail_EnableInterruptForRisingEdge() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define DEncDAvail_EnableInterruptForFallingEdge() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define DEncDAvail_DisableDigitalInputBuffer() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define DEncDAvail_EnableInterruptForLowLevelSensing() do { PORTD.PIN1CTRL = (PORTD.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PF2 aliases
#define IO_PF2_SetHigh() do { PORTF_OUTSET = 0x4; } while(0)
#define IO_PF2_SetLow() do { PORTF_OUTCLR = 0x4; } while(0)
#define IO_PF2_Toggle() do { PORTF_OUTTGL = 0x4; } while(0)
#define IO_PF2_GetValue() (VPORTF.IN & (0x1 << 2))
#define IO_PF2_SetDigitalInput() do { PORTF_DIRCLR = 0x4; } while(0)
#define IO_PF2_SetDigitalOutput() do { PORTF_DIRSET = 0x4; } while(0)
#define IO_PF2_SetPullUp() do { PORTF_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PF2_ResetPullUp() do { PORTF_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PF2_SetInverted() do { PORTF_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PF2_ResetInverted() do { PORTF_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PF2_DisableInterruptOnChange() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PF2_EnableInterruptForBothEdges() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PF2_EnableInterruptForRisingEdge() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PF2_EnableInterruptForFallingEdge() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PF2_DisableDigitalInputBuffer() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PF2_EnableInterruptForLowLevelSensing() do { PORTF.PIN2CTRL = (PORTF.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PD0 aliases
#define PD0_SetHigh() do { PORTD_OUTSET = 0x1; } while(0)
#define PD0_SetLow() do { PORTD_OUTCLR = 0x1; } while(0)
#define PD0_Toggle() do { PORTD_OUTTGL = 0x1; } while(0)
#define PD0_GetValue() (VPORTD.IN & (0x1 << 0))
#define PD0_SetDigitalInput() do { PORTD_DIRCLR = 0x1; } while(0)
#define PD0_SetDigitalOutput() do { PORTD_DIRSET = 0x1; } while(0)
#define PD0_SetPullUp() do { PORTD_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PD0_ResetPullUp() do { PORTD_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PD0_SetInverted() do { PORTD_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define PD0_ResetInverted() do { PORTD_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PD0_DisableInterruptOnChange() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PD0_EnableInterruptForBothEdges() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PD0_EnableInterruptForRisingEdge() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PD0_EnableInterruptForFallingEdge() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PD0_DisableDigitalInputBuffer() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PD0_EnableInterruptForLowLevelSensing() do { PORTD.PIN0CTRL = (PORTD.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set DEncDOutB aliases
#define DEncDOutB_SetHigh() do { PORTD_OUTSET = 0x8; } while(0)
#define DEncDOutB_SetLow() do { PORTD_OUTCLR = 0x8; } while(0)
#define DEncDOutB_Toggle() do { PORTD_OUTTGL = 0x8; } while(0)
#define DEncDOutB_GetValue() (VPORTD.IN & (0x1 << 3))
#define DEncDOutB_SetDigitalInput() do { PORTD_DIRCLR = 0x8; } while(0)
#define DEncDOutB_SetDigitalOutput() do { PORTD_DIRSET = 0x8; } while(0)
#define DEncDOutB_SetPullUp() do { PORTD_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define DEncDOutB_ResetPullUp() do { PORTD_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define DEncDOutB_SetInverted() do { PORTD_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define DEncDOutB_ResetInverted() do { PORTD_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define DEncDOutB_DisableInterruptOnChange() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define DEncDOutB_EnableInterruptForBothEdges() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define DEncDOutB_EnableInterruptForRisingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define DEncDOutB_EnableInterruptForFallingEdge() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define DEncDOutB_DisableDigitalInputBuffer() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define DEncDOutB_EnableInterruptForLowLevelSensing() do { PORTD.PIN3CTRL = (PORTD.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IGN_SNS aliases
#define IGN_SNS_SetHigh() do { PORTB_OUTSET = 0x2; } while(0)
#define IGN_SNS_SetLow() do { PORTB_OUTCLR = 0x2; } while(0)
#define IGN_SNS_Toggle() do { PORTB_OUTTGL = 0x2; } while(0)
#define IGN_SNS_GetValue() (VPORTB.IN & (0x1 << 1))
#define IGN_SNS_SetDigitalInput() do { PORTB_DIRCLR = 0x2; } while(0)
#define IGN_SNS_SetDigitalOutput() do { PORTB_DIRSET = 0x2; } while(0)
#define IGN_SNS_SetPullUp() do { PORTB_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IGN_SNS_ResetPullUp() do { PORTB_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IGN_SNS_SetInverted() do { PORTB_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define IGN_SNS_ResetInverted() do { PORTB_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IGN_SNS_DisableInterruptOnChange() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IGN_SNS_EnableInterruptForBothEdges() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IGN_SNS_EnableInterruptForRisingEdge() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IGN_SNS_EnableInterruptForFallingEdge() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IGN_SNS_DisableDigitalInputBuffer() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IGN_SNS_EnableInterruptForLowLevelSensing() do { PORTB.PIN1CTRL = (PORTB.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set PWR_BTN aliases
#define PWR_BTN_SetHigh() do { PORTF_OUTSET = 0x10; } while(0)
#define PWR_BTN_SetLow() do { PORTF_OUTCLR = 0x10; } while(0)
#define PWR_BTN_Toggle() do { PORTF_OUTTGL = 0x10; } while(0)
#define PWR_BTN_GetValue() (VPORTF.IN & (0x1 << 4))
#define PWR_BTN_SetDigitalInput() do { PORTF_DIRCLR = 0x10; } while(0)
#define PWR_BTN_SetDigitalOutput() do { PORTF_DIRSET = 0x10; } while(0)
#define PWR_BTN_SetPullUp() do { PORTF_PIN4CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define PWR_BTN_ResetPullUp() do { PORTF_PIN4CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define PWR_BTN_SetInverted() do { PORTF_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define PWR_BTN_ResetInverted() do { PORTF_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)
#define PWR_BTN_DisableInterruptOnChange() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define PWR_BTN_EnableInterruptForBothEdges() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define PWR_BTN_EnableInterruptForRisingEdge() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define PWR_BTN_EnableInterruptForFallingEdge() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define PWR_BTN_DisableDigitalInputBuffer() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define PWR_BTN_EnableInterruptForLowLevelSensing() do { PORTF.PIN4CTRL = (PORTF.PIN4CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set DEncDOutA aliases
#define DEncDOutA_SetHigh() do { PORTD_OUTSET = 0x4; } while(0)
#define DEncDOutA_SetLow() do { PORTD_OUTCLR = 0x4; } while(0)
#define DEncDOutA_Toggle() do { PORTD_OUTTGL = 0x4; } while(0)
#define DEncDOutA_GetValue() (VPORTD.IN & (0x1 << 2))
#define DEncDOutA_SetDigitalInput() do { PORTD_DIRCLR = 0x4; } while(0)
#define DEncDOutA_SetDigitalOutput() do { PORTD_DIRSET = 0x4; } while(0)
#define DEncDOutA_SetPullUp() do { PORTD_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define DEncDOutA_ResetPullUp() do { PORTD_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define DEncDOutA_SetInverted() do { PORTD_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define DEncDOutA_ResetInverted() do { PORTD_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define DEncDOutA_DisableInterruptOnChange() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define DEncDOutA_EnableInterruptForBothEdges() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define DEncDOutA_EnableInterruptForRisingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define DEncDOutA_EnableInterruptForFallingEdge() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define DEncDOutA_DisableDigitalInputBuffer() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define DEncDOutA_EnableInterruptForLowLevelSensing() do { PORTD.PIN2CTRL = (PORTD.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set RPI_RUN aliases
#define RPI_RUN_SetHigh() do { PORTB_OUTSET = 0x1; } while(0)
#define RPI_RUN_SetLow() do { PORTB_OUTCLR = 0x1; } while(0)
#define RPI_RUN_Toggle() do { PORTB_OUTTGL = 0x1; } while(0)
#define RPI_RUN_GetValue() (VPORTB.IN & (0x1 << 0))
#define RPI_RUN_SetDigitalInput() do { PORTB_DIRCLR = 0x1; } while(0)
#define RPI_RUN_SetDigitalOutput() do { PORTB_DIRSET = 0x1; } while(0)
#define RPI_RUN_SetPullUp() do { PORTB_PIN0CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define RPI_RUN_ResetPullUp() do { PORTB_PIN0CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define RPI_RUN_SetInverted() do { PORTB_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define RPI_RUN_ResetInverted() do { PORTB_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
#define RPI_RUN_DisableInterruptOnChange() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define RPI_RUN_EnableInterruptForBothEdges() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define RPI_RUN_EnableInterruptForRisingEdge() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define RPI_RUN_EnableInterruptForFallingEdge() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define RPI_RUN_DisableDigitalInputBuffer() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define RPI_RUN_EnableInterruptForLowLevelSensing() do { PORTB.PIN0CTRL = (PORTB.PIN0CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

void PIN_MANAGER_Initialize();
void PORTD_DEncDOutD_DefaultInterruptHandler(void);
void PORTD_DEncDOutD_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_KeyS_A_DefaultInterruptHandler(void);
void PORTB_KeyS_A_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_DEncDOutC_DefaultInterruptHandler(void);
void PORTD_DEncDOutC_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_BckConv_EN_DefaultInterruptHandler(void);
void PORTB_BckConv_EN_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_DEncDOutEnable_DefaultInterruptHandler(void);
void PORTD_DEncDOutEnable_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_DEncDOutE_DefaultInterruptHandler(void);
void PORTD_DEncDOutE_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_KeyS_B_DefaultInterruptHandler(void);
void PORTB_KeyS_B_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTE_IO_PE0_DefaultInterruptHandler(void);
void PORTE_IO_PE0_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTE_IO_PE2_DefaultInterruptHandler(void);
void PORTE_IO_PE2_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_PC0_DefaultInterruptHandler(void);
void PORTC_PC0_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTE_IO_PE1_DefaultInterruptHandler(void);
void PORTE_IO_PE1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA0_DefaultInterruptHandler(void);
void PORTA_PA0_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTE_IO_PE3_DefaultInterruptHandler(void);
void PORTE_IO_PE3_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_PC1_DefaultInterruptHandler(void);
void PORTC_PC1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_IO_PC4_DefaultInterruptHandler(void);
void PORTC_IO_PC4_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA2_DefaultInterruptHandler(void);
void PORTA_PA2_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTA_PA1_DefaultInterruptHandler(void);
void PORTA_PA1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_PC3_DefaultInterruptHandler(void);
void PORTC_PC3_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_IO_PC6_DefaultInterruptHandler(void);
void PORTC_IO_PC6_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_IO_PC5_DefaultInterruptHandler(void);
void PORTC_IO_PC5_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTC_IO_PC7_DefaultInterruptHandler(void);
void PORTC_IO_PC7_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_IO_PF1_DefaultInterruptHandler(void);
void PORTF_IO_PF1_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_IO_PF0_DefaultInterruptHandler(void);
void PORTF_IO_PF0_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_LED_S_DefaultInterruptHandler(void);
void PORTF_LED_S_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_DEncDAvail_DefaultInterruptHandler(void);
void PORTD_DEncDAvail_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_IO_PF2_DefaultInterruptHandler(void);
void PORTF_IO_PF2_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_PD0_DefaultInterruptHandler(void);
void PORTD_PD0_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_DEncDOutB_DefaultInterruptHandler(void);
void PORTD_DEncDOutB_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_IGN_SNS_DefaultInterruptHandler(void);
void PORTB_IGN_SNS_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTF_PWR_BTN_DefaultInterruptHandler(void);
void PORTF_PWR_BTN_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTD_DEncDOutA_DefaultInterruptHandler(void);
void PORTD_DEncDOutA_SetInterruptHandler(void (* interruptHandler)(void)) ;
void PORTB_RPI_RUN_DefaultInterruptHandler(void);
void PORTB_RPI_RUN_SetInterruptHandler(void (* interruptHandler)(void)) ;
#endif /* PINS_H_INCLUDED */
