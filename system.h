/*******************************************************************************
* This is the header file that describes the system properties for PTK40A
*
* Cytron Technologies Sdn. Bhd.
*******************************************************************************/
#ifndef _SYSTEM_H
#define _SYSTEM_H

//	define
//==========================================================================
#define	_XTAL_FREQ	2E6	/* Crystal frequency in 20MHz */

#define LED1	RB6
#define LED2	RB7

//	MAX6675 SPI
//==========================================================================
#define CS	RC2		//SPI Chip Select pin
#define SCK     RC6
#define SO      RC4

// I/O Connections.
// Parallel 2x16 Character LCD
#define LCD_E			RB5		// E clock pin is connected to RA3	
#define LCD_RS			RB4		// RS pin is used for LCD to differentiate data is command or character, RA2

#define	LCD_DATA		PORTD	// Data port of LCD is connected to PORTD, 8 bit mode
								// DB7(LCD) = RD7(PIC)
								// DB6(LCD) = RD6(PIC)
								// DB5(LCD) = RD5(PIC)
								// DB4(LCD) = RD4(PIC)
								// DB3(LCD) = RD3(PIC)
								// DB2(LCD) = RD2(PIC)
								// DB1(LCD) = RD1(PIC)
								// DB0(LCD) = RD0(PIC)

#endif