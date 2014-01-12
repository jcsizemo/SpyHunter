// The following #defines would normally be in macros.h, but are included
// here for ease or reference
#define CLEAR_REGISTER        (0x00)
#define DISABLE_ACCESS        (0X00)
#define ENABLE_ACCESS         (0X01)

// cm0 System Clock Control Register 0
// cm00,cm01 Clock output function
#define IO_PORT_P5_7          (0x00) // I/O Port P5_7
#define OUTPUT_FC             (0x01) // Output FC
#define OUTPUT_F8             (0x02) // Output F8
#define OUTPUT_F32            (0x03) // Output F32
// cm02 WAIT mode Peripheral Function Clock Stop Bit
#define PF_CLK_NO_STOP        (0x00) // Peripheral function clock no stop in wait mode
#define PF_CLK_STOP_WAIT      (0x04) // Peripheral function clock stops in wait mode
// cm03 XCIN-XCOUT Drive Capacity Select Bit
#define XC_LO_DRIVE           (0x00) // Low Drive
#define XC_HI_DRIVE           (0x08) // High Drive
// cm04 Port XC Select Bit == 0 = I/O Ports P8_6, P8_7, 1 = XCIN-XCOUT oscillation function
#define IO_PORT_P8_6_P8_7     (0x00) // I/O Port P8_6 and P8_7
#define XC_OSC                (0x10) //  XCIN-XCOUT oscillation function
// cm05 Main Clock Stop Bit == 0 = On, 1 = Off
#define MAIN_CLOCK_STOP_ON    (0x00) //  XCIN-XCOUT oscillation function
#define MAIN_CLOCK_STOP_OFF   (0x20) //  XCIN-XCOUT oscillation function
// cm06 Main Clock Division == 0 = CM16 and CM17 enabled, 1 = Division by 8
#define CM16_CM17             (0x00) // CM16, CM17 enabled
#define DIVIDE_8              (0x40) // XCIN-XCOUT oscillation function
// cm07 System Clock Select Bit == 0 = Main. PLL, or Internal Osc, 1 = Sub-Clock
#define MAIN_CLOCK            (0x00) //  Main clock, PLL clock, or on-chip oscillator clock
#define SUB_CLK               (0x80) //  XCIN-XCOUT oscillation function

// cm1 System Clock Control Register 1
// cm10 All Stop Control Bit == 0 = Clock On, 1 = All Clocks Off
#define CLKS_ON               (0x00) //  Clocks On
#define CLKS_OFF              (0x01) //  Clocks Off
// cm11 System Clock Select Bit == 0 = Main, 1 = PLL
#define MAIN_CLK              (0x00) //  Main Clock
#define PLL_CLK               (0x02) //  PLL Clock
// cm15 XCIN-XCOUT Drive Capacity Select Bit == 0 = Low, 1 = High
#define X_LO_DRIVE            (0x00) // Low Drive
#define X_HI_DRIVE            (0x20) // High Drive
// cm16,cm17 Main Clock Division Select Bit
#define MAIN_DIVIDE_1         (0x00) // No Division
#define MAIN_DIVIDE_2         (0x40) // Divide by 2
#define MAIN_DIVIDE_4         (0x80) // Divide by 4
#define MAIN_DIVIDE_16        (0xC0) // Divide by 16

// pm1 Processor Mode Register 1
// pm10 CS2 Area Switch Bit (Data Block Enable Bit)
#define ENABLE_DATA_FLASH     (0x01)
// pm2 Processor Mode Register 2
// pm20 Specifying Wait when Accessing SFR at PLL Operation == 0 = 2 waits, 1 =  wait
#define WAIT_1                (0x01)
#define WAIT_2                (0x00)
// pm21 System Clock Protective Bit
// pm22 Watch Dog Timer Count Source

// plc0 Register PLL Control Register
// PLL Multiplying Factor
#define PLL_DO_NOT_SET        (0x00) // I/O Port P5_7
#define PLL_MULTIPLY_2        (0x01) // Multiply by 2
#define PLL_MULTIPLY_4        (0x02) // Multiply by 4
#define PLL_MULTIPLY_6        (0x03) // Multiply by 6
#define PLL_MULTIPLY_8        (0x04) // Multiply by 8
#define PLL_ON                (0x80) // Turn PLL On

// Timer Bi Mode Register (i=0 to 4)
// 0 TMOD0 Operation Mode Select Bit
// 1 TMOD1 Operation Mode Select Bit
// 2 MR0, MR1 No effect with timer
// 4 MR2 Set to "0" in event timer mode
// 5 MR3 Set to "0" in event timer mode
// 6 TCK0, TCK1 Clock Source
//      00 : f1 of f2 [selected in PCLKR Register bit 0]
//      01 : f8
//      10 : f32
//      11 : fC32
//#define f1_CLK_SPEED	    (6000000L) // Installed Oscillator
#define CLEAR_REGISTER        (0x00) // Clear Register
#define DESIRED_TIME_MS       (0x05) //  5 millisecond timer
#define ONE_MSEC			  (0x01) // 1 msec
#define TIMER_MODE            (0x00) //  Timer Mode
#define EVENT_MODE            (0x01) //  Event Mode
#define PULSE_MODE            (0x02) //  Pulse Period Mode
#define SRC_F1_F2_PCLK0       (0x00) //  selected in PCLKR Register bit 0
#define SRC_F8                (0x40) //  clock source f8
#define SRC_F32               (0x80) //  clock source f32
#define SRC_FC32              (0xC0) //  clock source fC32
#define EVENT_TRIGGER		  (0x02) //  event trigger enable
//---------------------------------------------------------------------------

#define PUSHED 				0
#define FOREVER 			1
#define LEFT_BUTTON 		S1
#define CENTER_BUTTON 		S2
#define RIGHT_BUTTON 		S3

#define BEGIN 				1
#define PRIORITY_3 			3	// Interrupt Priority
#define	PRIORITY_OFF		0	// Remove priority from interrupt

#define RESET 				0

#define PORT_DIRECTION_IN  	0	// Input designation 
#define PORT_DIRECTION_OUT 	1	// Output designation

#define PIN_LOW 			0		// Set low
#define PIN_HIGH			1		// Set high

#define MAX_VALUE 			0x3FF	// Max Voltage Value
#define TEN_BIT_MODE 		0x28	// 10-Bit mode for ADC

#define	ENABLED				0x01

#define DELAY				20		// Debounce delay

#define INITIALIZE			0		// multipurpose initialization

#define VALID_STATE			4
#define INITIAL_STATE		1
#define COUNTER_OFFSET		10

// Circle defines 
#define EIGHTH_CIRCLE_DELAY		40
#define STRAIGHT_TIME			10

// Square defines
#define SIDE_DRIVE_TIME			85
#define CORNER_DRIVE_TIME		75

// Figure 8 defines
#define LEFT_DELAY				66
#define RIGHT_DELAY				55

#define LEFT_WHEEL					p3_2
#define	RIGHT_WHEEL					p3_0

#define ONE_MILLISECOND				1e-3
#define	OFFSET_TEN					10

#define LINE_DELAY					100
#define READ_DELAY					300

#define IR_LED						p3_7

#define MAX_SLOW_COUNT				7000

// adc control defines

#define REPEAT_SWEEP_MODE			0x98
#define TEN_BIT_MODE_VREF			0x39
#define SAMPLE_AND_HOLD				0x01
#define SAMPLE_AND_HOLD_DISABLED	0x00

#define THIRD_CYCLE					3

#define FORTYK_CYCLES					40000
				

// menu variables
#define LOCK_FUNCTION				1
#define RELEASE						0

#define LOW_BOUND					0
#define LOW_BOUND_SONG				15
#define TEN_PERCENT					102
#define TWENTY_PERCENT				204
#define THIRTY_PERCENT				306
#define FORTY_PERCENT				408
#define FIFTY_PERCENT				510
#define SIXTY_PERCENT				612
#define SEVENTY_PERCENT				714
#define EIGHTY_PERCENT				816
#define NINETY_PERCENT				918
#define MAXIMUM_SONG				1000
#define MAXIMUM						1023

#define SONG_DELAY					600

#define THUMB_WHEEL					ad0

// GPS defines
#define BUFFER_LENGTH				64
#define PREFIX_LENGTH				6
#define LAT_LONG_LENGTH				8
#define GPS_STRING_BEGINNER			'$'
#define SEPARATOR					','
#define PRECISION_CORRECTION		1

#define BEGINNING					0
#define MINUTES_TENS				0
#define MINUTES_ONES				1
#define PERIOD						2
#define MINUTES_TENTHS				3
#define MINUTES_HUNDREDTHS			4
#define SECONDS_TENS				5
#define SECONDS_ONES				6
#define CARDINAL_DIRECTION			7
#define END							7

#define THOUSANDS_PLACE				1000
#define HUNDREDS_PLACE				100
#define TENS_PLACE					10

#define MAX_DELAY					60000

#define EIGHT_BIT_DATA_MODE			0x05
#define TRANSMIT_RECEIVE_ENABLE		0x05
#define f1_CONFIGURED_CLOCK			0x00

// clocks.c defines
#define PLL_ENABLE					1
#define PROTECT_REGISTER			0
#define REGISTER_ACCESS				1
#define DIVIDE_BY_ONE				0
#define MAIN_CLOCK_DRIVE_HIGH		0x20
#define ALLOW_WRITE					1
#define ONE_WAIT					1
#define PLL_TIMES_TWO				0x92
#define WRITE_ENABLE				1
#define WRITE_PROTECTED				0
#define ENABLE_FLASH				1

#define MAX_COUNT					10
#define AVERAGER					11

#define THRESHOLD					2
#define LIGHT_DELAY					1000000

#define LONG_DRIVE					5000000
#define SHORT_DRIVE					1000000