/***********************************************************************/
/*                                                                     */
/*  DATE        :Mon, Mar 23, 2009                                     */
/*																	   */
/*  DESCRIPTION :  All functions that need prototyping should be       */
/* 	  				prototyped here. 								   */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/


void A2DInit(void);
void InitDisplay(char far StartupString1[] );
void DisplayString(unsigned char position, _far const char * string);
void LCD_write(unsigned char data_or_ctrl, unsigned char value);
void DisplayDelay(unsigned long int units);
void BNSPutch(unsigned int where, char c);
unsigned char BNSPrintf(unsigned int where, char far * f, ...);

// Project Specific

void TimerInit(void);
void ADInit(void);
void LEDDisplay(void);

void ports_init(void);			// Function declarations for initialization functions
void port0_init(void);
void port1_init(void);
void port2_init(void);
void port3_init(void);
void port4_init(void);
void port5_init(void);
void port6_init(void);
void port7_init(void);
void port8_init(void);
void port9_init(void);
void port10_init(void);
