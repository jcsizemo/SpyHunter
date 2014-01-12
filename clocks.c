//**********************************************************************/
//
//  DATE        :Mon, February 19, 2011 
//
//  DESCRIPTION : This file sets up the CPU clock and PLL
//
//  CPU GROUP   :62P
//
// Jim Carlson
//
//**********************************************************************/
#include "macros.h"
#include "proto.h"
#include "QSKDefines.h"
#include "extern.h"


//------------------------------------------------------------------------------------------
//  Purpose: Clock_Init initializes the clock circuit to the main crystal [6.0MHz]
//           with a divide by 1. This function also sets the main clock to divide by 1.
//           It then enables the PLL.
//
//           f1_CLK_SPEED = 6.0MHz
//
//  Rev:    1.0     Initial Release
//
//  Notes:          None
//------------------------------------------------------------------------------------------
void system_clock_init(void){
  unsigned int count = 40000;
// configure clock for divide by 1 mode 
  prc0 = ENABLE_ACCESS;            // enable access to clock registers 
// cm0 System Clock Control Register 0
  cm0 = CLEAR_REGISTER;            // Clear System Control Register
  cm0 |= IO_PORT_P5_7;             // pin available as GP I/O
  cm0 |= PF_CLK_NO_STOP;           // pf clock no stop in wait mode
  cm0 |= XC_HI_DRIVE;              // XC drive capacity high
  cm0 |= IO_PORT_P8_6_P8_7;        // pin available as GP I/O
  cm0 |= MAIN_CLOCK_STOP_ON;       // main clock stop
  cm0 |= CM16_CM17;                // set CM16,CM17 enabled
  cm0 |= MAIN_CLK;                 // main clock no Sub Clock
// cm1 System Clock Control Register 1
  cm1 = CLEAR_REGISTER;            // Clear System Control Register
  cm1 |= CLKS_ON;                  // clocks on
  cm1 |= MAIN_CLK;                 // main clock
  cm1 |= XC_HI_DRIVE;              // high drive
  cm1 |= MAIN_DIVIDE_1;            // no division
// cm2 System Clock Control Register 2 defaults all 0

// set SFR access to 2 wait cycles, required for operation >16 MHz  
  prc1 = ENABLE_ACCESS;            // allow writing to processor mode register
//  pm20 = WAIT_2;                   // Configure for 2 wait states
  pm20 = WAIT_1;                   // Configure for 2 wait states
  prc1 = DISABLE_ACCESS;           // protect processor mode register
// Configure PLL
  plc0 = CLEAR_REGISTER;           // Clear PLL Control Register
  plc0 |= PLL_ON + PLL_MULTIPLY_2; // enable PLL (2X) and turn on

// wait for PLL to stabilize (20mS maximum, 240,000 cycles @12Mhz)
  while(count > 0){
    count--;                       // this decrement with no optimization is 12 cycles each
  }                        
  cm11 = PLL_CLK;                  // switch to PLL
  prc0 = DISABLE_ACCESS;           // protect clock control register
  
// enable data flash area
  prc1 = ENABLE_ACCESS;            // enable access to clock registers 
  pm10 = ENABLE_DATA_FLASH;        // enable data flash area
  prc1 = DISABLE_ACCESS;           // protect processor mode register
}
//------------------------------------------------------------------------------------------

// Configure Timer B0 - Timer 5 millisecond
//---------------------------------------------------------------------------
//  Purpose:  Set Timer B0 5 ms.
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//---------------------------------------------------------------------------// Toggle Port 3 pin 0 to see on oscilloscope - each transition 5 msec 


void TimerB0_Init(void){
  tb0mr = CLEAR_REGISTER;  // Clear Timer B0 Mode Register
  tb0mr |= TIMER_MODE;	   // Timer mode
  tb0mr |= SRC_F32;	       // Clock Source f32
  DISABLE_IRQ		
  tb0ic = 3;  // Set the timer B0's IPL (interrupt priority level) to 3
  ENABLE_IRQ  // enable interrupts macro defined in skp_bsp.h
// Start timer 
  tb0s = 1;	    // Start timer B0
// (6MHz / 32 * [time in millisecond] / 1000 ms per second )-1
  tb0 = (unsigned int) (((f1_CLK_SPEED/32)*DESIRED_TIME_MS/1000) - 1);	
}
//---------------------------------------------------------------------------





