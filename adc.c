/*
FILE: adc.c
CONTAINS: ADInit function
AUTHOR: John Sizemore
DATE: 01/30/2011
*/


#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "macros.h"


void ADInit(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	Set up the A2D for one shot mode.
//  
//
//  Rev:    1.0     Initial Release
//  
//  Notes:          None    
//-----------------------------------------------------------------------------------------------------
{
	
   /* Configure ADC - AN0 (Analog Adjust Pot) */
   adcon0 = SRC_F32;	// AN0, One-shot, software trigger, fAD/2
   adcon1 = TEN_BIT_MODE;	// 10-bit mode, Vref connected.
   adcon2 = ENABLED;	// Sample and hold enabled
}   