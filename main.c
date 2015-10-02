/*
 * File:   main.c
 * Author: Hatake_Chin
 *
 * Created on September 6, 2012, 8:02 PM
 */

//  Include
//==========================================================================
#include <htc.h>
#include "lcd.h"
#include "system.h"

//   Configuration
//==========================================================================
//if Hi-Tech V9.70-V9.80 compiler is being used, open this device configuration words
//__CONFIG(HS &			// High Speed Crystal.
//		 WDTDIS &		// Disable Watchdog Timer.
//		 PWRTEN &		// Enable Power Up Timer.
//		 BORDIS &		// Disable Brown Out Reset.
//		 LVPDIS);		// Disable Low Voltage Programming.

//if Hi-Tech V9.81-V9.83 compiler is being used, open this device configuration words
__CONFIG(FOSC_HS &		// High Speed Crystal.
		 WDTE_ON &		// Disable Watchdog Timer.
		 PWRTE_ON &		// Enable Power Up Timer.
		 BOREN_OFF &	// Disable Brown Out Reset.
		 LVP_OFF);		// Disable Low Voltage Programming.

//==========================================================================
void initialize(void);
unsigned int readCelsius(void);
unsigned char spiread(void);

//  Main function
//==========================================================================
void main(void)
{
    unsigned int data;
    unsigned int obtain;

    initialize();
    lcd_home();
    lcd_putstr("   Temp(C):");

    while(1)
    {
        obtain = 0;
        obtain = readCelsius();
        data = obtain%100;
        obtain = obtain/100;
        __delay_ms(1500);
        lcd_2ndline();
        lcd_bcd(3, obtain);
        lcd_putchar('.');
        lcd_bcd(2, data);
        RB7 ^= 1;
        __delay_ms(1500);
    }
}

void initialize(void)
{
    	PORTA = 0;				// clear PORT
	PORTB = 0;
	PORTC = 0;
	PORTD = 0;
        PORTE = 0;

	TRISA = 0b00000000;			// set PORTA as OUTPUT
	TRISB = 0b00000011; 			// set PORTB<7:2> AS OUTPUT , PORTB<1:0> as INPUT
	TRISC = 0b00010000;                     // set PORTC as OUTPUT
	TRISD = 0b00000000;                     // set PORTD as OUTPUT
        TRISE = 0b00000000;

	ANSELH = 0; 				// SET PORTB as DIGITAL I/O for PIC16F887
	ANSEL = 0;				// SET PORTA as DIGITAL I/O for PIC16F887

        lcd_initialize();			// Initialise LCD..
}

unsigned int readCelsius(void) {

  unsigned int v;

  CS = 0;
  __delay_ms(1);

  v = spiread();
  v <<= 8;
  v |= spiread();
  CS = 1;

  v >>= 3;
  return v*25;
}


unsigned char spiread(void) {
  int i;
  unsigned char d = 0;

  for (i=7; i>=0; i--)
  {
    SCK = 0;
    __delay_ms(1);
    if (SO) {
      //set the bit to 0 no matter what
      d |= (1 << i);
    }
    SCK = 1;
    __delay_ms(1);
  }

  return d;
}

