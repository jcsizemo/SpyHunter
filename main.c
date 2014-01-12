/*
FILE: main.c
CONTAINS: main function
AUTHOR: John Sizemore
DATE: 01/30/2011
*/

#include "QSKDefines.h"
#include "proto.h"
#include "extern.h"
#include "macros.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



//GLOBALS

long uint Global_Count;				// Reference global count, initialize 3 switches
uint Switch1Count = RESET;
uint Switch2Count = RESET;
uint Switch3Count = RESET;

uint LeftWheelCount;			// Counts for left and right wheels
uint RightWheelCount;

uint eighthCircleCount;			// max drive time for Circle eighth-circles and straights, also used in Figure 8
uint straightCount;

uint sideCount;					// max drive time for Square sides and corners
uint cornerCount;

uint irLEDOn  = FALSE;			// ADC Project 2 variables
uint AD0Value = RESET;
uint AD2Value = RESET;
uint AD3Value = RESET;
uint goingForward = FALSE;
uint goingReverse = FALSE;
long uint lineCount = RESET;
uint blackSurface = RESET;
uint whiteSurface = RESET;
uint surfaceDifference = RESET;

// Variables for use with the menus
uint functionControl = RESET;
uint startPartOne = RESET;
uint startPartTwo = RESET;
uint startPartThree = RESET;
uint startPartFour = RESET;

// GPS variables
char *reader;				

char receive_buffer[BUFFER_LENGTH];
uint buffer_index = RESET;
uint gotCoordinates = FALSE;
uint gotPoint		= FALSE;

long uint position_zero_lat = RESET;
long uint position_zero_long = RESET;
long uint position_one_lat = RESET;
long uint position_one_long = RESET;
long uint position_two_lat = RESET;
long uint position_two_long = RESET;

int positions_zero_one_lat_difference = RESET;
int positions_zero_one_long_difference = RESET;
int positions_one_two_lat_difference = RESET;
int positions_one_two_long_difference = RESET;
int positions_two_zero_lat_difference = RESET;
int positions_two_zero_long_difference = RESET;

uint first_positions_set = FALSE;
uint second_positions_set = FALSE;
uint third_positions_set = FALSE;

uint latCloser = FALSE;
uint longCloser = FALSE;
uint justTurned = FALSE;

// USED IN GETTING ORIGINAL POINTS
uint counter 			  = RESET;

// DYNAMIC POINTS DURING TRAVEL
volatile long int currentLatitude	  = RESET;
volatile long int currentLongitude	  = RESET;
long int lastLongitude   = RESET;
long int lastLatitude    = RESET;
uint crossedLongitude	  = FALSE;
uint crossedLatitude	  = FALSE;

// BOOLEANS TO TELL WHETHER OR NOT A WAYPOINT WAS REACHED
uint gotToFirst = FALSE;
uint gotToSecond = FALSE;
uint gotToHome = FALSE;

uint goingWest = FALSE;
uint goingNorth = FALSE;

long uint delay = RESET;
long uint idelay = RESET;

/*char NCSU[8] = "NCSUis#1";
uint NCSU_index = RESET;
char NCSU_rcv[8];
char NCSU_rcv_index;*/



int disp_count;				// LED control variable
uint A2DValue;
uint A2DValuePot;
uint A2DValueTherm;
uchar A2DProcessed;

/***********************************************************************/
/*                                                                     */
/*  DATE        :March 29, 2011		                                   */
/*																	   */
/*  DESCRIPTION :      This is the main file for Project 2             */
/* 	  															       */
/*																	   */
/*  CPU GROUP   :62P                                                   */
/*                                                                     */
/*  Copyright (c) 2009 by BNS Solutions, Inc.						   */
/*  All rights reserved.											   */
/*                                                                     */
/***********************************************************************/

void main(void)
//-----------------------------------------------------------------------------------------------------
//  Purpose:	The MCU will come here after reset. 
//  
//
//  Rev:    1.0     Initial Release
//			1.1		Modified to include functions governing the shapes to be done in Project 1.
//			1.2     Modified to include code to utilize the ADC and the IR emitters and detectors
//					for Project 2.
//			1.3 	Modified for use with menus for Homework 8.
//  Author: John Sizemore
//  Notes:          Contains code to operate a system of menus governed by the three face buttons and
//					the ADC resolution.   
//-----------------------------------------------------------------------------------------------------
{
	system_clock_init();
	ports_init();	
	InitDisplay("Project4 ");
	InitUART();
//	BNSPrintf(SERIAL, "\n\rProject3\n\r");
//  TimerInit();
	TimerB0_Init();	
	ADInit();	
	ENABLE_SWITCHES;
	
	/* LED initialization - macro defined in qsk_bsp.h */
 	ENABLE_LEDS	
	adst = BEGIN;
	BNSPrintf(LCD,"\t GPS    \n Ready  ");
	
	

	while(FOREVER) {
		LEDDisplay();		// display current value of LED control variable */    
		
		if(LEFT_BUTTON == PUSHED) 
			{
			if (Global_Count >= Switch1Count)
				{
				Switch1Count = (Global_Count  + DELAY);
				BNSPrintf(LCD,"\tGetting \nGPS Lock");
				for (delay = 0; delay < 100; delay++)
					{
					gotPoint = FALSE;
					while (!gotPoint)
						{
						while (buffer_index < BUFFER_LENGTH)
							{
							while (!ri_u2c1);
							receive_buffer[buffer_index] = u2rbl;
							buffer_index++;
							}
						buffer_index = RESET;
						reader = &receive_buffer[BEGINNING];
						parseGPS_travel(reader);
						}
					}
				BNSPrintf(LCD,"\tGPS     \nLocked  ");	
				}
					
			}	
			
		
		else if(CENTER_BUTTON == PUSHED) 
			{
			if (Global_Count >= Switch2Count)
				{
				Switch2Count = (Global_Count  + DELAY);
				lastLatitude = position_one_lat;		// the program sets the position one coordinates as the
				lastLongitude = position_one_long;		// waypoints
				
				while (!gotToFirst)
					{
					counter = RESET;					// reset the counter used for point collection,
					currentLatitude = RESET;			// reset current long and lat
					currentLongitude = RESET;
					crossedLongitude = FALSE;
					crossedLatitude	 = FALSE;
					justTurned		 = FALSE;
					precise_point();					// get a point of reference
					
					//************PHASE ONE		Discover which is closer: Lat or Long
					
					if (abs(position_one_lat - currentLatitude) <= abs(position_one_long - currentLongitude))
						latCloser = TRUE;
					else
						longCloser = TRUE;			// checking to see which is closer of lat or long
						
					//***********PHASE TWO		For which value is closer (lat or long), go to that coordinate.
						
					if (latCloser)		// go to lat first if it is closer
						{
						while(abs((position_one_lat - currentLatitude)) >= THRESHOLD)  // straightforward: go to the lat. if the car
							{														   // gets farther away, turn until it gets closer
							counter = RESET;
							if (abs((position_one_lat - currentLatitude)) < abs((position_one_lat - lastLatitude)))
								{													
								lastLatitude = currentLatitude;	
								forwardSample();				
								precise_point();
								}
							else
								{
								lastLatitude = currentLatitude;	
								pivotRight();
								forwardSample();
								precise_point();
								}
							}
							BNSPrintf(LCD,"\tLatitude\n   OK   ");
							crossedLatitude = TRUE;
							if ((position_one_long - currentLongitude) > 0)
								goingWest = TRUE;
							else
								goingWest = FALSE;
						}
						
						else		// this else loop implies that long was closer. Goes directly to long.
							{
						while(abs((position_one_long - currentLongitude)) >= THRESHOLD)  
							{															  
							counter = RESET;
							if (abs((position_one_long - currentLongitude)) < abs((position_one_long - lastLongitude)))
								{													
								lastLongitude = currentLongitude;	
								forwardSample();				
								precise_point();
								}
							else
								{
								lastLongitude = currentLongitude;	
								pivotRight();
								forwardSample();
								precise_point();
								}
							}
							BNSPrintf(LCD,"\tLngitude\n   OK   ");
							crossedLongitude = TRUE;
							if ((position_one_lat - currentLatitude) > 0)
								goingNorth = TRUE;
							else
								goingNorth = FALSE;
						}
						//**************PHASE 3***************************************** Track found coordinate to other coordinate
						
						if (crossedLongitude)			// This is where it gets messy. There are several conditions which
							{							// must be dealt with when it comes to the car latching onto the long/lat.
							counter = RESET;
							while(abs((position_one_lat - currentLatitude)) >= THRESHOLD)
								{
								if ((abs(position_one_lat - currentLatitude) < abs(position_one_lat - lastLatitude)) && 
								 (lastLongitude >= position_one_long) && (currentLongitude >= position_one_long) && !justTurned)
									{
									lastLatitude = currentLatitude;
									if (goingNorth)							// If the car is getting closer, but on the left side
										pivotRight();							// of the longitude, and the car did NOT just turn,
									else
										pivotLeft();
									forwardSample();						// turn right to cross over the longitude line.
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_one_lat - currentLatitude) < abs(position_one_lat - lastLatitude)) && 
								 (lastLongitude < position_one_long) && (currentLongitude < position_one_long) && !justTurned)
									{
									lastLatitude = currentLatitude;			// If the car is getting closer, but on the right side
									if (goingNorth)
										pivotLeft();							// of the longitude and the car did NOT just turn,
									else
										pivotRight();
									forwardSample();						// turn left to cross over the line.
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_one_lat - currentLatitude) < abs(position_one_lat - lastLatitude)) && 
								(((lastLongitude < position_one_long) && (currentLongitude < position_one_long)) || ((lastLongitude >= position_one_long) && (currentLongitude >= position_one_long))) && justTurned)
									{
									lastLatitude = currentLatitude;			// If the car was on one side of the long side in the current
									forwardSample();						// and past instance, GO FORWARD. This makes the car refrain
									precise_point();						// from infinite turn loops.
									justTurned = FALSE;
									}
								else if ((abs(position_one_lat - currentLatitude) < abs(position_one_lat - lastLatitude)) && 
								 (lastLongitude >= position_one_long) && (currentLongitude < position_one_long) && !justTurned)
									{
									lastLatitude = currentLatitude;			// If the car crossed over the long line, simply turn the other way
									if (goingNorth)
										pivotLeft();
									else
										pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_one_lat - currentLatitude) < abs(position_one_lat - lastLatitude)) && 
								 (lastLongitude < position_one_long) && (currentLongitude >= position_one_long) && !justTurned)
									{
									lastLatitude = currentLatitude;			// About face, but going in the other direction.
									if (goingNorth)
										pivotRight();
									else
										pivotLeft();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else
									{
									lastLatitude = currentLatitude;			// If all else fails, the car is traveling away from the 
									pivotRight();							// longitude and must turn to correct itself.
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								}
							gotToFirst = TRUE;
							BNSPrintf(LCD,"\tLatitude\n   OK   ");
							LED0 = LED_ON;
							}
							
						else if (crossedLatitude)
							{
							while(abs((position_one_long - currentLongitude)) >= THRESHOLD)
								{
								counter = RESET;
								if ((abs(position_one_long - currentLongitude) < abs(position_one_long - lastLongitude)) && 
								 (lastLatitude >= position_one_lat) && (currentLatitude >= position_one_lat) && !justTurned)
									{
									lastLongitude = currentLongitude;
									if (goingWest)
										pivotLeft();
									else	
										pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_one_long - currentLongitude) < abs(position_one_long - lastLongitude)) && 
								 (lastLatitude < position_one_lat) && (currentLatitude < position_one_lat) && !justTurned)
									{
									lastLongitude = currentLongitude;
									if (goingWest)
										pivotRight();
									else	
										pivotLeft();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_one_long - currentLongitude) < abs(position_one_long - lastLongitude)) && 
								(((lastLatitude < position_one_lat) && (currentLatitude < position_one_lat)) || ((lastLatitude >= position_one_lat) && (currentLatitude >= position_one_lat))) && justTurned)
									{
									lastLongitude = currentLongitude;	
									forwardSample();				
									precise_point();
									justTurned = FALSE;
									}
								else if ((abs(position_one_long - currentLongitude) < abs(position_one_long - lastLongitude)) && 
								 (lastLatitude >= position_one_lat) && (currentLatitude < position_one_lat) && !justTurned)
									{
									lastLongitude = currentLongitude;
									if (goingWest)
										pivotRight();
									else	
										pivotLeft();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_one_long - currentLongitude) < abs(position_one_long - lastLongitude)) && 
								 (lastLatitude < position_one_lat) && (currentLatitude >= position_one_lat) && !justTurned)
									{
									lastLongitude = currentLongitude;
									if (goingWest)	
										pivotLeft();
									else
										pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else
									{
									lastLongitude = currentLongitude;	
									pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								}
							gotToFirst = TRUE;
							BNSPrintf(LCD,"\tLatitude\n   OK   ");
							LED0 = LED_ON;
							}
					}
								
				lastLatitude = position_two_lat;
				lastLongitude = position_two_long;	
					
				while (!gotToSecond)
					{
					crossedLongitude = FALSE;
					crossedLatitude	 = FALSE;
					goingNorth = FALSE;
					goingWest = FALSE;
					justTurned = FALSE;
					
					if (abs(position_two_lat - currentLatitude) <= abs(position_two_long - currentLongitude))
						latCloser = TRUE;
					else
						longCloser = TRUE;			// checking to see which is closer of lat or long
						
					if (latCloser)		// go to lat first if it is closer
						{
						while(abs((position_two_lat - currentLatitude)) >= THRESHOLD)  // straightforward: go to the lat. if the car
							{														   // gets farther away, turn until it gets closer
							counter = RESET;
							if (abs((position_two_lat - currentLatitude)) < abs((position_two_lat - lastLatitude)))
								{													
								lastLatitude = currentLatitude;	
								forwardSample();				
								precise_point();
								}
							else
								{
								lastLatitude = currentLatitude;	
								pivotRight();
								forwardSample();
								precise_point();
								}
							}
							BNSPrintf(LCD,"\tLatitude\n   OK   ");
							crossedLatitude = TRUE;
							if ((position_one_long - currentLongitude) > 0)
								goingWest = TRUE;
							else
								goingWest = FALSE;
						}
						
						else		// this else loop implies that long was closer
							{
						while(abs((position_two_long - currentLongitude)) >= THRESHOLD)  
							{															  
							counter = RESET;
							if (abs((position_two_long - currentLongitude)) < abs((position_two_long - lastLongitude)))
								{													
								lastLongitude = currentLongitude;	
								forwardSample();				
								precise_point();
								}
							else
								{
								lastLongitude = currentLongitude;	
								pivotRight();
								forwardSample();
								precise_point();
								}
							}
							BNSPrintf(LCD,"\tLngitude\n   OK   ");
							crossedLongitude = TRUE;
							if ((position_one_lat - currentLatitude) > 0)
								goingNorth = TRUE;
							else
								goingNorth = FALSE;
						}
						
						if (crossedLongitude)			// This is where it gets messy. There are several conditions which
							{							// must be dealt with when it comes to the car latching onto the long/lat.
							counter = RESET;
							while(abs((position_two_lat - currentLatitude)) >= THRESHOLD)
								{
								if ((abs(position_two_lat - currentLatitude) < abs(position_two_lat - lastLatitude)) && 
								 (lastLongitude >= position_two_long) && (currentLongitude >= position_two_long) && !justTurned)
									{
									lastLatitude = currentLatitude;
									if (goingNorth)	
										pivotRight();
									else
										pivotLeft();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_two_lat - currentLatitude) < abs(position_two_lat - lastLatitude)) && 
								 (lastLongitude < position_two_long) && (currentLongitude < position_two_long) && !justTurned)
									{
									lastLatitude = currentLatitude;	
									if (goingNorth)
										pivotLeft();
									else
										pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_two_lat - currentLatitude) < abs(position_two_lat - lastLatitude)) && 
								(((lastLongitude < position_two_long) && (currentLongitude < position_two_long)) || ((lastLongitude >= position_two_long) && (currentLongitude >= position_two_long))) && justTurned)
									{
									lastLatitude = currentLatitude;	
									forwardSample();				
									precise_point();
									justTurned = FALSE;
									}
								else if ((abs(position_two_lat - currentLatitude) < abs(position_two_lat - lastLatitude)) && 
								 (lastLongitude >= position_two_long) && (currentLongitude < position_two_long) && !justTurned)
									{
									lastLatitude = currentLatitude;
									if (goingNorth)	
										pivotLeft();
									else
										pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_two_lat - currentLatitude) < abs(position_two_lat - lastLatitude)) && 
								 (lastLongitude < position_two_long) && (currentLongitude >= position_two_long) && !justTurned)
									{
									lastLatitude = currentLatitude;
									if (goingNorth)
										pivotRight();
									else	
										pivotLeft();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else
									{
									lastLatitude = currentLatitude;	
									pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								}
							gotToSecond = TRUE;
							BNSPrintf(LCD,"\tLatitude\n   OK   ");
							LED1 = LED_ON;
							}
							
						else if (crossedLatitude)
							{
							while(abs((position_two_long - currentLongitude)) >= THRESHOLD)
								{
								counter = RESET;
								if ((abs(position_two_long - currentLongitude) < abs(position_two_long - lastLongitude)) && 
								 (lastLatitude >= position_two_lat) && (currentLatitude >= position_two_lat) && !justTurned)
									{
									lastLongitude = currentLongitude;
									if (goingWest)
										pivotLeft();
									else	
										pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_two_long - currentLongitude) < abs(position_two_long - lastLongitude)) && 
								 (lastLatitude < position_two_lat) && (currentLatitude < position_two_lat) && !justTurned)
									{
									lastLongitude = currentLongitude;
									if (goingWest)
										pivotRight();
									else	
										pivotLeft();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_two_long - currentLongitude) < abs(position_two_long - lastLongitude)) && 
								(((lastLatitude < position_two_lat) && (currentLatitude < position_two_lat)) || ((lastLatitude >= position_two_lat) && (currentLatitude >= position_two_lat))) && justTurned)
									{
									lastLongitude = currentLongitude;	
									forwardSample();				
									precise_point();
									justTurned = FALSE;
									}
								else if ((abs(position_two_long - currentLongitude) < abs(position_two_long - lastLongitude)) && 
								 (lastLatitude >= position_two_lat) && (currentLatitude < position_two_lat) && !justTurned)
									{
									lastLongitude = currentLongitude;
									if (goingWest)
										pivotRight();
									else	
										pivotLeft();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_two_long - currentLongitude) < abs(position_two_long - lastLongitude)) && 
								 (lastLatitude < position_two_lat) && (currentLatitude >= position_two_lat) && !justTurned)
									{
									lastLongitude = currentLongitude;
									if (goingWest)	
										pivotLeft();
									else
										pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else
									{
									lastLongitude = currentLongitude;	
									pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								}
							gotToSecond = TRUE;
							BNSPrintf(LCD,"\tLatitude\n   OK   ");
							LED1 = LED_ON;
							}
					}
					
				lastLatitude = position_zero_lat;
				lastLongitude = position_zero_long;	
					
				while (!gotToHome)
					{
					crossedLongitude = FALSE;
					crossedLatitude	 = FALSE;
					justTurned = FALSE;
					goingNorth = FALSE;
					goingWest = FALSE;
					
					if (abs(position_zero_lat - currentLatitude) <= abs(position_zero_long - currentLongitude))
						latCloser = TRUE;
					else
						longCloser = TRUE;			// checking to see which is closer of lat or long
						
					if (latCloser)		// go to lat first if it is closer
						{
						while(abs((position_zero_lat - currentLatitude)) >= THRESHOLD)  // straightforward: go to the lat. if the car
							{														   // gets farther away, turn until it gets closer
							counter = RESET;
							if (abs((position_zero_lat - currentLatitude)) < abs((position_zero_lat - lastLatitude)))
								{													
								lastLatitude = currentLatitude;	
								forwardSample();				
								precise_point();
								}
							else
								{
								lastLatitude = currentLatitude;	
								pivotRight();
								forwardSample();
								precise_point();
								}
							}
							BNSPrintf(LCD,"\tLatitude\n   OK   ");
							crossedLatitude = TRUE;
							if ((position_one_long - currentLongitude) > 0)
								goingWest = TRUE;
							else
								goingWest = FALSE;
						}
						
						else		// this else loop implies that long was closer
							{
						while(abs((position_zero_long - currentLongitude)) >= THRESHOLD)  
							{															  
							counter = RESET;
							if (abs((position_zero_long - currentLongitude)) < abs((position_zero_long - lastLongitude)))
								{													
								lastLongitude = currentLongitude;	
								forwardSample();				
								precise_point();
								}
							else
								{
								lastLongitude = currentLongitude;	
								pivotRight();
								forwardSample();
								precise_point();
								}
							}
							BNSPrintf(LCD,"\tLngitude\n   OK   ");
							crossedLongitude = TRUE;
							if ((position_one_lat - currentLatitude) > 0)
								goingNorth = TRUE;
							else
								goingNorth = FALSE;
						}
						
						if (crossedLongitude)			// This is where it gets messy. There are several conditions which
							{							// must be dealt with when it comes to the car latching onto the long/lat.
							counter = RESET;
							while(abs((position_zero_lat - currentLatitude)) >= THRESHOLD)
								{
								if ((abs(position_zero_lat - currentLatitude) < abs(position_zero_lat - lastLatitude)) && 
								 (lastLongitude >= position_zero_long) && (currentLongitude >= position_zero_long) && !justTurned)
									{
									lastLatitude = currentLatitude;
									if (goingNorth)	
										pivotRight();
									else
										pivotLeft();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_zero_lat - currentLatitude) < abs(position_zero_lat - lastLatitude)) && 
								 (lastLongitude < position_zero_long) && (currentLongitude < position_zero_long) && !justTurned)
									{
									lastLatitude = currentLatitude;
									if (goingNorth)	
										pivotLeft();
									else
										pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_zero_lat - currentLatitude) < abs(position_zero_lat - lastLatitude)) && 
								(((lastLongitude < position_zero_long) && (currentLongitude < position_zero_long)) || ((lastLongitude >= position_zero_long) && (currentLongitude >= position_zero_long))) && justTurned)
									{
									lastLatitude = currentLatitude;	
									forwardSample();				
									precise_point();
									justTurned = FALSE;
									}
								else if ((abs(position_zero_lat - currentLatitude) < abs(position_zero_lat - lastLatitude)) && 
								 (lastLongitude >= position_zero_long) && (currentLongitude < position_zero_long) && !justTurned)
									{
									lastLatitude = currentLatitude;
									if (goingNorth)	
										pivotLeft();
									else
										pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_zero_lat - currentLatitude) < abs(position_zero_lat - lastLatitude)) && 
								 (lastLongitude < position_zero_long) && (currentLongitude >= position_zero_long) && !justTurned)
									{
									lastLatitude = currentLatitude;
									if (goingNorth)
										pivotRight();
									else	
										pivotLeft();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else
									{
									lastLatitude = currentLatitude;	
									pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								}
							gotToHome = TRUE;
							BNSPrintf(LCD,"\tLatitude\n   OK   ");
							LED2 = LED_ON;
							}
							
						else if (crossedLatitude)
							{
							while(abs((position_zero_long - currentLongitude)) >= THRESHOLD)
								{
								counter = RESET;
								if ((abs(position_zero_long - currentLongitude) < abs(position_zero_long - lastLongitude)) && 
								 (lastLatitude >= position_zero_lat) && (currentLatitude >= position_zero_lat) && !justTurned)
									{
									lastLongitude = currentLongitude;
									if (goingWest)
										pivotLeft();
									else	
										pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_zero_long - currentLongitude) < abs(position_zero_long - lastLongitude)) && 
								 (lastLatitude < position_zero_lat) && (currentLatitude < position_zero_lat) && !justTurned)
									{
									lastLongitude = currentLongitude;
									if (goingWest)
										pivotRight();
									else	
										pivotLeft();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_zero_long - currentLongitude) < abs(position_zero_long - lastLongitude)) && 
								(((lastLatitude < position_zero_lat) && (currentLatitude < position_zero_lat)) || ((lastLatitude >= position_zero_lat) && (currentLatitude >= position_zero_lat))) && justTurned)
									{
									lastLongitude = currentLongitude;	
									forwardSample();				
									precise_point();
									justTurned = FALSE;
									}
								else if ((abs(position_zero_long - currentLongitude) < abs(position_zero_long - lastLongitude)) && 
								 (lastLatitude >= position_zero_lat) && (currentLatitude < position_zero_lat) && !justTurned)
									{
									lastLongitude = currentLongitude;
									if (goingWest)
										pivotRight();
									else	
										pivotLeft();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else if ((abs(position_zero_long - currentLongitude) < abs(position_zero_long - lastLongitude)) && 
								 (lastLatitude < position_zero_lat) && (currentLatitude >= position_zero_lat) && !justTurned)
									{
									lastLongitude = currentLongitude;
									if (goingWest)	
										pivotLeft();
									else
										pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								else
									{
									lastLongitude = currentLongitude;	
									pivotRight();
									forwardSample();
									precise_point();
									justTurned = TRUE;
									}
								}
							gotToHome = TRUE;
							BNSPrintf(LCD,"\tLatitude\n   OK   ");
							LED2 = LED_ON;
							}
					}
					
				pimpSpin();	//-- ghost ridin' the whip
				
				}
				
			}		
						
			
		
		else if(RIGHT_BUTTON == PUSHED) 
			{
			if (Global_Count >= Switch3Count)
				{
				Switch3Count = (Global_Count  + DELAY);
				gotPoint = FALSE;
				counter = RESET;
				if (third_positions_set)
					{
					BNSPrintf(LCD,"\tGot All \n Points ");
					}
				else
					{
					while (counter <= MAX_COUNT)
						{
						BNSPrintf(LCD,"\tGetting \nPosition");
						getPoint();
						}	
					}
				}
			}
				
		
		
		
	//	else{
  //         if (A2DProcessed == TRUE)
	//			{         // only update the display when a new value is available
      //          A2DProcessed = FALSE;
        //        BNSPrintf(LCD,"\tRT1:%04u \nAD0:%04u",A2DValueTherm,A2DValuePot);
          //	}
 			
				
	//		}	
	
	}
}
/*
void loopback(void)
{
NCSU_index = RESET;
NCSU_rcv_index = RESET;
BNSPrintf(LCD,"\t%c%c%c%c%c%c%c%c\n         ",NCSU[0],NCSU[1],NCSU[2],NCSU[3],NCSU[4],NCSU[5],NCSU[6],NCSU[7]);
				while (NCSU_rcv_index < 8)
					{
					while (!ti_u2c1);
					u2tbl = NCSU[NCSU_index];
					for (delay = RESET; delay < 10000; delay++);
					if (!ri_u2c1)
						{
						BNSPrintf(LCD,"\t\n        ");
						NCSU_index = RESET;
						NCSU_rcv_index = RESET;
						}
					else
						{
						NCSU_rcv[NCSU_rcv_index] = u2rbl;
						NCSU_rcv_index++;
						NCSU_index++;
						}
					}
				
				BNSPrintf(LCD,"\t\n%c%c%c%c%c%c%c%c",NCSU_rcv[0],NCSU_rcv[1],
				NCSU_rcv[2],NCSU_rcv[3],NCSU_rcv[4],NCSU_rcv[5],NCSU_rcv[6],NCSU_rcv[7]);
				NCSU_rcv_index = RESET;
				NCSU_index = RESET;
				
}*/

void getPoint(void)
{
	gotPoint = FALSE;
	while (!gotPoint)
		{
		while (buffer_index < BUFFER_LENGTH)
			{
			while (!ri_u2c1);
			receive_buffer[buffer_index] = u2rbl;
			buffer_index++;
			}
		buffer_index = RESET;
		reader = &receive_buffer[BEGINNING];
		parseGPS(reader);
		}
counter++;
	
}

void getPoint_travel(void)
{
gotPoint = FALSE;
while (!gotPoint)
		{
		while (buffer_index < BUFFER_LENGTH)
			{
			while (!ri_u2c1);
			receive_buffer[buffer_index] = u2rbl;
			buffer_index++;
			}
		buffer_index = RESET;
		reader = &receive_buffer[BEGINNING];
		parseGPS_travel(reader);
		}
counter++;	
}

uint getDistance(uint currentLatitude,uint currentLongitude,uint position_lat,uint position_long)
{
int latDifference = position_lat - currentLatitude;
int longDifference = position_long - currentLongitude;
uint distance = sqrt(pow(latDifference,2) + pow(longDifference,2));
return distance;
}

void precise_point(void)
{
while (counter <= MAX_COUNT)
	{
	getPoint_travel();
	}	
}
