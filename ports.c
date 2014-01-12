/* 	Name: 				John Sizemore
	Date: 				02/15/2011
	Compiler Revision:	Version 4.05
*/

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "macros.h"

	
void ports_init(void) // initializes all 11 ports
	{
	port0_init();
	port1_init();
	port2_init();
	port3_init();
	port4_init();
	port5_init();
	port6_init();
	port7_init();
	port8_init();
	port9_init();
	port10_init();
	}
	
//---------------------------------------------------------------------------------
// port0_init
// Purpose: Initialize Port 0
// System registers associated with Port 0 configured
// *Pin 0 - General Purpose I/O
//	Pin 0 - AN0 - Analog Input 0 for A/D Converter
//	Pin 0 - D0  - Data Pin 0
// *Pin 1 - General Purporse I/O
//  Pin 1 - AN1 - Analog Input 1 for A/D Converter
//	Pin 1 - D1	- Data Pin 1
// *Pin 2 - General Purpose I/O
//  Pin 2 - AN2	- Analog Input 2 for A/D Converter
//	Pin 2 - D2  - Data Pin 2
// *Pin 3 - General Purpose I/O
//  Pin 3 - AN3 - Analog Input 3 for A/D Converter
//	Pin 3 - D3  - Data Pin 3
// *Pin 4 - General Purpose I/O
//  Pin 4 - AN4 - Analog Input 4 for A/D Converter
//  Pin 4 - D4  - Data Pin 4
// *Pin 5 - General Purpose I/O
//  Pin 5 - AN5 - Analog Input 5 for A/D Converter
//  Pin 5 - D5  - Data Pin 5
// *Pin 6 - General Purpose I/O
//  Pin 6 - AN6 - Analog Input 6 for A/D Converter
//  Pin 6 - D6 - Data Pin 6
// *Pin 7 - General Purpose I/O
//  Pin 7 - AN7 - Analog Input 7 for A/D Converter
//  Pin 7 - D7  - Data Pin 7
//	Passed - 		no variables passed
//	Locals - 		no locals used
//	Returned - 		no return values.
//	Author: 		John Sizemore
//	Compiler Rev.:	1.0 Initial Release
//	HEW Version:	4.08
//-----------------------------------------------------------------------------------		
void port0_init(void) // initializes port 0
	{
	pd0_0	=	PORT_DIRECTION_IN; // AN0_0 and D0
	p0_0	=	PIN_LOW;
	pd0_1	=	PORT_DIRECTION_IN; // AN0_1 and D1
	p0_1	=	PIN_LOW;
	pd0_2	=	PORT_DIRECTION_IN; // AN0_2 and D2
	p0_2	=	PIN_LOW;
	pd0_3	=	PORT_DIRECTION_IN; // AN0_3 and D3
	p0_3	=	PIN_LOW;
	pd0_4	=	PORT_DIRECTION_IN; // AN0_4 and D4
	p0_4	=	PIN_LOW;
	pd0_5	=	PORT_DIRECTION_IN; // AN0_5 and D5
	p0_5	=	PIN_LOW;
	pd0_6	=	PORT_DIRECTION_IN; // AN0_6 and D6
	p0_6	=	PIN_LOW;
	pd0_7	=	PORT_DIRECTION_IN; // AN0_7 and D7
	p0_7	=	PIN_LOW;
	}
	
//---------------------------------------------------------------------------------
// port1_init
// Purpose: Initialize Port 0
// System registers associated with Port 0 configured
// *Pin 0 - General Purpose I/O
//	Pin 0 - D8 - Data Pin 8
// *Pin 1 - General Purporse I/O
//  Pin 1 - D9 - Data Pin 9
// *Pin 2 - General Purpose I/O
//  Pin 2 - D10 - Data Pin 10
// *Pin 3 - General Purpose I/O
//  Pin 3 - D11 - Data Pin 11
// *Pin 4 - General Purpose I/O
//  Pin 4 - D12 - Data Pin 12
// *Pin 5 - General Purpose I/O
//  Pin 5 - D13 - Data Pin 13
//  Pin 5 - INT3 - Input Pin for Interrupt 3
// *Pin 6 - General Purpose I/O
//  Pin 6 - D14 - Data Pin 14
//  Pin 6 - INT4 - Input Pin for Interrupt 4
// *Pin 7 - General Purpose I/O
//  Pin 7 - D15 - Data Pin 15
//  Pin 7 - INT5 - Input Pin for Interrupt 5
//	Passed - 		no variables passed
//	Locals - 		no locals used
//	Returned - 		no return values.
//	Author: 		John Sizemore
//	Compiler Rev.:	1.0 Initial Release
//	HEW Version:	4.08
//-----------------------------------------------------------------------------------
void port1_init(void) // initializes port 1
	{
	pd1_0	=	PORT_DIRECTION_IN; // D8
	p1_0	=	PIN_LOW;
	pd1_1	=	PORT_DIRECTION_IN; // D9
	p1_1	=	PIN_LOW;
	pd1_2	=	PORT_DIRECTION_IN; // D10
	p1_2	=	PIN_LOW;
	pd1_3	=	PORT_DIRECTION_IN; // D11
	p1_3	=	PIN_LOW;
	pd1_4	=	PORT_DIRECTION_IN; // D12
	p1_4	=	PIN_LOW;
	pd1_5	=	PORT_DIRECTION_IN; // D13 / INT3
	p1_5	=	PIN_LOW;
	pd1_6	=	PORT_DIRECTION_IN; // D14 / INT4
	p1_6	=	PIN_LOW;
	pd1_7	=	PORT_DIRECTION_IN; // D15 / INT5
	p1_7	=	PIN_LOW;
	
	}
//---------------------------------------------------------------------------------
// port2_init
// Purpose: Initialize Port 0
// System registers associated with Port 0 configured
// *Pin 0 - General Purpose I/O
//	Pin 0 - AN2_0 - Analog Input Pin 0 for A/D Converter
//  Pin 0 - A0	  - Output Address Bit 0
// *Pin 1 - General Purporse I/O
//  Pin 1 - AN2_1 - Analog Input Pin 1 for A/D Converter
//  Pin 1 - A1	  - Output Address Bit 1
// *Pin 2 - General Purpose I/O
//  Pin 2 - AN2_2 - Analog Input Pin 2 for A/D Converter
//  Pin 2 - A2    - Output Address Bit 2
// *Pin 3 - General Purpose I/O
//  Pin 3 - AN2_3 - Analog Input Pin 3 for A/D Converter
//  Pin 3 - A3    - Output Address Bit 3
// *Pin 4 - General Purpose I/O
//  Pin 4 - AN2_4 - Analog Input Pin 4 for A/D Converter
//  Pin 4 - A4    - Output Address Bit 4
// *Pin 5 - General Purpose I/O
//  Pin 5 - AN2_5 - Analog Input Pin 5 for A/D Converter
//  Pin 5 - A5    - Output Address Bit 5
// *Pin 6 - General Purpose I/O
//  Pin 6 - AN2_6 - Analog Input Pin 6 for A/D Converter
//  Pin 6 - A6    - Output Address Bit 6
// *Pin 7 - General Purpose I/O
//  Pin 7 - AN2_7 - Analog Input Pin 7 for A/D Converter
//  Pin 7 - A7    - Output Address Bit 7
//	Passed - 		no variables passed
//	Locals - 		no locals used
//	Returned - 		no return values.
//	Author: 		John Sizemore
//	Compiler Rev.:	1.0 Initial Release
//	HEW Version:	4.08
//-----------------------------------------------------------------------------------
void port2_init(void) // initializes port 2
	{
	pd2_0	=	PORT_DIRECTION_OUT; // AN2_0 / A0
	p2_0	=	PIN_LOW;
	pd2_1	=	PORT_DIRECTION_OUT; // AN2_1 / A1
	p2_1	=	PIN_LOW;
	pd2_2	=	PORT_DIRECTION_OUT; // AN2_2 / A2
	p2_2	=	PIN_LOW;
	pd2_3	=	PORT_DIRECTION_OUT; // AN2_3 / A3
	p2_3	=	PIN_LOW;
	pd2_4	=	PORT_DIRECTION_OUT; // AN2_4 / A4
	p2_4	=	PIN_LOW;
	pd2_5	=	PORT_DIRECTION_OUT; // AN2_5 / A5
	p2_5	=	PIN_LOW;
	pd2_6	=	PORT_DIRECTION_OUT; // AN2_6 / A6
	p2_6	=	PIN_LOW;
	pd2_7	=	PORT_DIRECTION_OUT; // AN2_7 / A7
	p2_7	=	PIN_LOW;
	
	}

//---------------------------------------------------------------------------------
// port3_init
// Purpose: Initialize Port 0
// System registers associated with Port 0 configured
// *Pin 0 - General Purpose I/O
//	Pin 0 - A9 - Output Address Bit 8
// *Pin 1 - General Purporse I/O
//  Pin 1 - A10 - Output Address Bit 9
// *Pin 2 - General Purpose I/O
//  Pin 2 - A11 - Output Address Bit 10
// *Pin 3 - General Purpose I/O
//  Pin 3 - A12 - Output Address Bit 11
// *Pin 4 - General Purpose I/O
//  Pin 4 - A13 - Output Address Bit 12
// *Pin 5 - General Purpose I/O
//  Pin 5 - A14 - Output Address Bit 13
// *Pin 6 - General Purpose I/O
//  Pin 6 - A15 - Output Address Bit 14
// *Pin 7 - General Purpose I/O
//  Pin 7 - A16 - Output Address Bit 15
//	Passed - 		no variables passed
//	Locals - 		no locals used
//	Returned - 		no return values.
//	Author: 		John Sizemore
//	Compiler Rev.:	1.0 Initial Release
//	HEW Version:	4.08
//-----------------------------------------------------------------------------------	
void port3_init(void) // initializes port 3
	{
	pd3_0	=	PORT_DIRECTION_OUT; // A8
	p3_0	=	PIN_LOW;
	pd3_1	=	PORT_DIRECTION_OUT; // A9
	p3_1	=	PIN_LOW;
	pd3_2	=	PORT_DIRECTION_OUT; // A10
	p3_2	=	PIN_LOW;
	pd3_3	=	PORT_DIRECTION_OUT; // A11
	p3_3	=	PIN_LOW;
	pd3_4	=	PORT_DIRECTION_OUT; // A12
	p3_4	=	PIN_LOW;
	pd3_5	=	PORT_DIRECTION_OUT; // A13
	p3_5	=	PIN_LOW;
	pd3_6	=	PORT_DIRECTION_OUT; // A14
	p3_6	=	PIN_LOW;
	pd3_7	=	PORT_DIRECTION_OUT; // A15
	p3_7	=	PIN_LOW;
	
	}

//---------------------------------------------------------------------------------
// port4_init
// Purpose: Initialize Port 4
// System registers associated with Port 4 configured
// *Pin 0 - General Purpose I/O
//	Pin 0 - A16 - Output Address Bit A16
// *Pin 1 - General Purporse I/O
//  Pin 1 - A17 - Output Address Bit A17
// *Pin 2 - General Purpose I/O
//  Pin 2 - A18 - Output Address Bit A18
// *Pin 3 - General Purpose I/O
//  Pin 3 - A19 - Output Address Bit A19
// *Pin 4 - General Purpose I/O
//  Pin 4 - CS0 - Chip Select 0
// *Pin 5 - General Purpose I/O
//  Pin 5 - CS1 - Chip Select 1
// *Pin 6 - General Purpose I/O
//  Pin 6 - CS2 - Chip Select 2
// *Pin 7 - General Purpose I/O
//  Pin 7 - CS3 - Chip Select 3
//	Passed - 		no variables passed
//	Locals - 		no locals used
//	Returned - 		no return values.
//	Author: 		John Sizemore
//	Compiler Rev.:	1.0 Initial Release
//	HEW Version:	4.08
//-----------------------------------------------------------------------------------	
	
void port4_init(void) // initializes port 4
	{
	pd4_0	=	PORT_DIRECTION_OUT;	// A16
	p4_0	=	PIN_LOW;
	pd4_1	=	PORT_DIRECTION_OUT; // A17
	p4_1	=	PIN_LOW;
	pd4_2	=	PORT_DIRECTION_OUT; // A18
	p4_2	=	PIN_LOW;
	pd4_3	=	PORT_DIRECTION_OUT; // A19
	p4_3	=	PIN_LOW;
	pd4_4	=	PORT_DIRECTION_OUT; // Chip Select 0-3. This one is CS0.
	p4_4	=	PIN_LOW;		
	pd4_5	=	PORT_DIRECTION_OUT; // CS1
	p4_5	=	PIN_LOW;		
	pd4_6	=	PORT_DIRECTION_OUT;	// CS2
	p4_6	=	PIN_LOW;
	pd4_7	=	PORT_DIRECTION_OUT; // CS3
	p4_7	=	PIN_LOW;
	}
	
//---------------------------------------------------------------------------------
// port5_init
// Purpose: Initialize Port 5
// System registers associated with Port 5 configured
// *Pin 0 - General Purpose I/O
//	Pin 0 - WRL	- Write/Read LSB for 16 Bit Words. Works in conjunction 
//							  with pins 1 and 2 to determine operation.
//	Pin 0 - WR 	- Write for External 8-Bit Bus
// *Pin 1 - General Purporse I/O
//  Pin 1 - WRH - Write/Read MSB. Works in conjunction with pins 0 and 2 to 
//													   determine operation.
//	Pin 1 - BHE - Write/Read Variable for 16 Bit words. Determines read/
//										  		    write at even addresses.
// *Pin 2 - General Purpose I/O
//  Pin 2 - RD	 - 	Read Variable for 16 Bit words. If set low, data is read.
// *Pin 3 - General Purpose I/O
//  Pin 3 - BCLK -	Outputs the Bus CLK signal.
// *Pin 4 - General Purpose I/O
//  Pin 4 - HLDA -  Outputs the HLDA signal. Will output 1 if in a HOLD state.
// *Pin 5 - General Purpose I/O
//  Pin 5 - HOLD -  When low, places the microcomputer into a "HOLD" state.
// *Pin 6 - General Purpose I/O
//  Pin 6 - ALE	 -	Triggers the ALE signal. When the signal falls, the address
//																	is latched.	
// *Pin 7 - General Purpose I/O
//  Pin 7 - RDY	 -	When low, the microcomputer is placed in a "WAIT" state.
//	Pin 7 - CLKOUT - Clock output. Outputs the fC, f8, or f32 clock signal.
//	Passed - 		no variables passed
//	Locals - 		no locals used
//	Returned - 		no return values.
//	Author: 		John Sizemore
//	Compiler Rev.:	1.0 Initial Release
//	HEW Version:	4.08
//-----------------------------------------------------------------------------------
	
void port5_init(void) // initializes port 5
	{
	pd5_0	=	PORT_DIRECTION_OUT;	// WRL or WR
	p5_0	=	PIN_LOW;		
	pd5_1	=	PORT_DIRECTION_OUT; // WRH or BHE
	p5_1	=	PIN_LOW;
	pd5_2	=	PORT_DIRECTION_OUT; // RD
	p5_2	=	PIN_LOW;
	pd5_3	=	PORT_DIRECTION_OUT; // BCLK
	p5_3	=	PIN_LOW;
	pd5_4	=	PORT_DIRECTION_OUT; // HLDA
	p5_4	=	PIN_LOW;
	pd5_5	=	PORT_DIRECTION_OUT; // HOLD
	p5_5	=	PIN_LOW;	   
	pd5_6	=	PORT_DIRECTION_OUT;// ALE
	p5_6	=	PIN_LOW;
	pd5_7	=	PORT_DIRECTION_OUT;// RDY and CLKOUT
	p5_7	=	PIN_LOW; 
	}

//---------------------------------------------------------------------------------
// port6_init
// Purpose: Initialize Port 0
// System registers associated with Port 0 configured
// *Pin 0 - General Purpose I/O
//	Pin 0 - CTS0 / RTS0 - Send Control Pin 0, Recieve Control 1
// *Pin 1 - General Purporse I/O
//  Pin 1 - CLK0		- Clock 0
// *Pin 2 - General Purpose I/O
//  Pin 2 - RXD0 / SCL0 - Serial Input Pin 0, Transfer Clock I/O Pin 0
// *Pin 3 - General Purpose I/O
//  Pin 3 - TXD0 / SDA0 - Serial Output Pin 0, Serial Data I/O Pin 0
// *Pin 4 - General Purpose I/O
//  Pin 4 - CTS1 / RTS1 / CTSO / CLKS1 - Send Control Pin 1, Recieve Control 1,
//										 Send Control 0, Clock Output Pin 
// *Pin 5 - General Purpose I/O
//  Pin 5 - CLK1 - Clock 1
// *Pin 6 - General Purpose I/O
//  Pin 6 - RXD1 / SCL1 - Serial Input Pin 1, Transfer Clock I/O Pin 1
// *Pin 7 - General Purpose I/O
//  Pin 7 - TXD1 / SDA1 - Serial Output Pin 1, Serial Data I/O Pin 1
//	Passed - 		no variables passed
//	Locals - 		no locals used
//	Returned - 		no return values.
//	Author: 		John Sizemore
//	Compiler Rev.:	1.0 Initial Release
//	HEW Version:	4.08
//-----------------------------------------------------------------------------------
void port6_init(void) // initializes port 6
	{
	pd6_0	=	PORT_DIRECTION_IN; // CTSO and RTS0
	p6_0	=	PIN_LOW;					  
	pd6_1	=	PORT_DIRECTION_IN; // CLK0			  
	p6_1	=	PIN_LOW;
	pd6_2	=	PORT_DIRECTION_IN; // RXD0 and SCL0
	p6_2	=	PIN_LOW;
	pd6_3	=	PORT_DIRECTION_IN; // TXD0 and SDA0
	p6_3	=	PIN_LOW;
//	pd6_4	=	PORT_DIRECTION_IN; // CTS1 and RTS1 and CTSO and CLKS1
//	p6_4	=	PIN_LOW;
//	pd6_5	=	PORT_DIRECTION_IN; // CLK1
	p6_5	=	PIN_LOW;
	pd6_6	=	PORT_DIRECTION_IN; // RXD1 and SCL1
	p6_6	=	PIN_LOW;
	pd6_7	=	PORT_DIRECTION_IN; // TXD1 and SDA1
	p6_7	=	PIN_LOW;			
	
	}

//---------------------------------------------------------------------------------
// port7_init
// Purpose: Initialize Port 0
// System registers associated with Port 0 configured
// *Pin 0 - General Purpose I/O
//	Pin 0 - TXD2 / SDA2 / TA0OUT - Serial Output Pin 2, Serial I/O Pin 2,
//								   Time A0 Output Pin 
// *Pin 1 - General Purporse I/O
//  Pin 1 - RXD2 / SCL2 / TA0IN - Serial Input Pin 2, Transfer Clock I/O Pin 2,
//								  Timer A0 Input Pin
// *Pin 2 - General Purpose I/O
//  Pin 2 - CLK2 / TA1OUT -		  Clock 2, Timer A1 Output Pin
// *Pin 3 - General Purpose I/O
//  Pin 3 - CTS2 / RTS2 / TA1IN - Send Control Pin 2, Recieve Control Pin 2,
//								  Timer A1 Input Pin
// *Pin 4 - General Purpose I/O
//  Pin 4 - TA2OUT - Timer A2 Output Pin
// *Pin 5 - General Purpose I/O
//  Pin 5 - TA2IN -  Timer A2 Input Pin
// *Pin 6 - General Purpose I/O
//  Pin 6 - TA3OUT - Timer A3 Output Pin
// *Pin 7 - General Purpose I/O
//  Pin 7 - TA3IN - Timer A3 Input Pin
//	Passed - 		no variables passed
//	Locals - 		no locals used
//	Returned - 		no return values.
//	Author: 		John Sizemore
//	Compiler Rev.:	1.0 Initial Release
//	HEW Version:	4.08
//-----------------------------------------------------------------------------------	
void port7_init(void) // initializes port 7
	{
	pd7_0	=	PORT_DIRECTION_OUT;
	p7_0	=	PIN_LOW;
	pd7_1	=	PORT_DIRECTION_OUT;
	p7_1	=	PIN_LOW;
//	pd7_2	=	PORT_DIRECTION_OUT; Left LED
//	p7_2	=	PIN_LOW;

	LED1_DDR 	=	PORT_DIRECTION_OUT;
	LED1		=	LED_OFF;
	
	pd7_3	=	PORT_DIRECTION_OUT;
	p7_3	=	PIN_LOW;
//	pd7_4	=	PORT_DIRECTION_OUT; //Right LED
//	p7_4	=	PIN_LOW;

	LED2_DDR	=	PORT_DIRECTION_OUT;
	LED2		=	LED_OFF;
	
	pd7_5	=	PORT_DIRECTION_OUT;
	p7_5	=	PIN_LOW;
	pd7_6	=	PORT_DIRECTION_OUT;
	p7_6	=	PIN_LOW;
	pd7_7	=	PORT_DIRECTION_OUT;
	p7_7	=	PIN_LOW; 
	
	
	}
	
//----------------------------------------------------------------------------------
//  Purpose:	Initialize Port 8
//  System registers associated with Port 8 configured
//  * Pin 0 - I/O    General Purpose I/O
//    Pin 0 - TA4OUT Timer A4 Out
//    Pin 0 - U      Three-Phase Positive Waveform Output Pin
//  * Pin 1 - I/O    General Purpose I/O
//    Pin 1 - TA4IN  Timer A4 In
//    Pin 1 - U      Three-Phase Negative Waveform Output Pin
//  * Pin 2 - I/O    General Purpose I/O
//    Pin 2 - INT0   Interrupt 0 Input
//  * Pin 3 - I/O    General Purpose I/O
//    Pin 3 - INT1   Interrupt 1 Input
//  * Pin 4 - I/O    General Purpose I/O
//    Pin 4 - INT2   Interrupt 2 Input
//    Pin 5 - I/O    General Purpose I/O
//  * Pin 5 - NMI    Non-Maskable Interrupt Input
//    Pin 6 - I/O    General Purpose I/O
//  * Pin 6 - XCIN ==> Connected to X2 back side
//    Pin 7 - I/O    General Purpose I/O
//  * Pin 7 - XCOUT ==> Connected to X2 back side
// * as configured below
//  Passed: 		No variables passed
//  Locals: 		No local values used
//  Returned: 		No values returned.
//  Author:			John Sizemore
//  Compiler Rev:	1.0 Initial Release
//  HEW Version: 	4.08
//----------------------------------------------------------------------------------
void port8_init(void) // initializes port 8
	{
	// 	P8_0 is used as and LED port with specific #defines
	//  pd8_0 = PORT_DIRECTION_OUT;
	//  p8_0 = PIN_LOW;
	// 	LED 0
	// 	LED0 Direction Initialization
	 	LED0_DDR = PORT_DIRECTION_OUT; 
		LED0 = LED_OFF; 
	// 	Switches 1,2,3
	// 	Switch 1,2,3 Direction Initialization
	  	pd8_1 = PORT_DIRECTION_IN;  // Switch 2
		pd8_2 = PORT_DIRECTION_IN;  // Switch 3
		pd8_3 = PORT_DIRECTION_IN;  // Switch 1
	// 	Switch 1,2,3 Inputs set low
		p8_1 = PIN_LOW;
		p8_2 = PIN_LOW;
		p8_3 = PIN_LOW;
	// 	Unused Port Pins
	// 	Unused Port Pin Direction Initialization
		pd8_4 = PORT_DIRECTION_IN;
	// 	Unused Port Pin Inputs set low
		p8_4 = PIN_LOW;
	// 	Port * Pin 5 is NMI / sfr62p.h does not support GP I/O
	//  pd8_5 = PORT_DIRECTION_IN;
	//  p8_5 = PIN_LOW;
	// 	XC input is used thus these cannot be used  
	//  pd8_6 = PORT_DIRECTION_IN;
	//  p8_6 = PIN_LOW;
	//  pd8_7 = PORT_DIRECTION_IN;
	//  p8_7 = PIN_LOW;
	
	}

//---------------------------------------------------------------------------------
// port9_init
// Purpose: Initialize Port 0
// System registers associated with Port 0 configured
// *Pin 0 - General Purpose I/O
//	Pin 0 - TB0IN / CLK3 - Timer B0 Input Pin, Clock 3
// *Pin 1 - General Purporse I/O
//  Pin 1 - TB1IN / SIN3 - Timer B1 Input Pin, Serial Data Input Pin 3
// *Pin 2 - General Purpose I/O
//  Pin 2 - TB2IN / SOUT3 - Timer B2 Input Pin, Serial Data Output Pin 3
// *Pin 3 - General Purpose I/O
//  Pin 3 - DA0 / TB3IN - D/A converter output 0, Timer B3 Input Pin
// *Pin 4 - General Purpose I/O
//  Pin 4 - DA1 / TB4IN	- D/A converter output 1, Timer B4 Input Pin
// *Pin 5 - General Purpose I/O
//  Pin 5 - ANEX0 / CLK4 - Extended Analog Input 0, Clock 4
// *Pin 6 - General Purpose I/O
//  Pin 6 - ANEX1 / SOUT4 - Extended Analog Input 1, Serial Data Output Pin 4
// *Pin 7 - General Purpose I/O
//  Pin 7 - ADTRG / SIN4 - A/D Trigger Input Pin, Serial Data Input Pin 4
//	Passed - 		no variables passed
//	Locals - 		no locals used
//	Returned - 		no return values.
//	Author: 		John Sizemore
//	Compiler Rev.:	1.0 Initial Release
//	HEW Version:	4.08
//-----------------------------------------------------------------------------------	
void port9_init(void) // initializes port 9
	{
	pd9_0	=	PORT_DIRECTION_IN;
	p9_0	=	PIN_LOW;
	pd9_1	=	PORT_DIRECTION_IN;
	p9_1	=	PIN_LOW;
	pd9_2	=	PORT_DIRECTION_IN;
	p9_2	=	PIN_LOW;
	pd9_3	=	PORT_DIRECTION_IN;
	p9_3	=	PIN_LOW;
	pd9_4	=	PORT_DIRECTION_IN;
	p9_4	=	PIN_LOW;
	pd9_5	=	PORT_DIRECTION_IN;
	p9_5	=	PIN_LOW;
	pd9_6	=	PORT_DIRECTION_IN;
	p9_6	=	PIN_LOW;
	pd9_7	=	PORT_DIRECTION_IN;
	p9_7	=	PIN_LOW;
	
	}

//---------------------------------------------------------------------------------
// port10_init
// Purpose: Initialize Port 0
// System registers associated with Port 0 configured
// *Pin 0 - General Purpose I/O
//	Pin 0 - AN0 - Analog Input 0 for A/D Converter
// *Pin 1 - General Purporse I/O
//  Pin 1 - AN1 - Analog Input 1 for A/D Converter
// *Pin 2 - General Purpose I/O
//  Pin 2 - AN2 - Analog Input 2 for A/D Converter
// *Pin 3 - General Purpose I/O
//  Pin 3 - AN3 - Analog Input 3 for A/D Converter
// *Pin 4 - General Purpose I/O
//  Pin 4 - AN4 / KI0 - Analog Input 4 for A/D Converter, Key Input Interrupt 0
// *Pin 5 - General Purpose I/O
//  Pin 5 - AN5 / KI1 - Analog Input 5 for A/D Converter, Key Input Interrupt 1
// *Pin 6 - General Purpose I/O
//  Pin 6 - AN6 / KI2 - Analog Input 6 for A/D Converter, Key Input Interrupt 2
// *Pin 7 - General Purpose I/O
//  Pin 7 - AN7 / KI3 - Analog Input 7 for A/D Converter, Key Input Interrupt 3
//	Passed - 		no variables passed
//	Locals - 		no locals used
//	Returned - 		no return values.
//	Author: 		John Sizemore
//	Compiler Rev.:	1.0 Initial Release
//	HEW Version:	4.08
//-----------------------------------------------------------------------------------	
void port10_init(void) // initializes port 10
	{
	pd10_0	=	PORT_DIRECTION_OUT;
	p10_0	=	PIN_LOW;
	pd10_1	=	PORT_DIRECTION_OUT;
	p10_1	=	PIN_LOW;
	pd10_2	=	PORT_DIRECTION_IN;
	p10_2	=	PIN_LOW;
	pd10_3	=	PORT_DIRECTION_OUT;
	p10_3	=	PIN_LOW;
	pd10_4	=	PORT_DIRECTION_OUT;
	p10_4	=	PIN_LOW;
	pd10_5	=	PORT_DIRECTION_OUT;
	p10_5	=	PIN_LOW;
	pd10_6	=	PORT_DIRECTION_OUT;
	p10_6	=	PIN_LOW;
	pd10_7	=	PORT_DIRECTION_OUT;
	p10_7	=	PIN_LOW;
	
	}
	
void set_port3_pin0(void)
	{
	if (p3_0 == PIN_LOW)
		{
		BNSPrintf(LCD,"\tL-ON    \n        ");
		p3_0 = PIN_HIGH;
		}
	else if (p3_0 == PIN_HIGH)
		{
		BNSPrintf(LCD,"\tL-OFF    \n        ");
		p3_0 = PIN_LOW;
		}
	}
	
void clear_port3_pin0_and_pin2(void)
	{
	BNSPrintf(LCD,"\tALL OFF  \n        ");
	p3_0 = PIN_LOW;
	p3_2 = PIN_LOW;
	}
		
void set_port3_pin2(void)
	{
	if (p3_2 == PIN_LOW)
		{
		BNSPrintf(LCD,"\tR-ON    \n        ");
		p3_2 = PIN_HIGH;
		}
	else if (p3_2 == PIN_HIGH)
		{
		BNSPrintf(LCD,"\tR-OFF    \n        ");
		p3_2 = PIN_LOW;
		}
	}
	
	
	