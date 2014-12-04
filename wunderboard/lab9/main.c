/**
 * @file wunder.c
 * @author Dan Albert
 * @author Marshal Horn
 * @date Created 12/15/2010
 * @date Last updated 1/20/2013
 * @version 1.0
 *
 * @section LICENSE
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * @section DESCRIPTION
 * 
 * This program will test the various components of the Wunderboard when used
 * with the corresponding host test script.
 * 
 */

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "adc.h"
#include "diskio.h"
#include "types.h"
#include "usart.h"
#include "leds.h"

// 9600 baud
#define BAUD_RATE 51

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))


void initialize( void )
{
   CPU_PRESCALE(0);

   USART_init(BAUD_RATE);
   USART_transmit('\f');	// Send form feed to clear the terminal.
   USART_send_string("WunderBoard initializing...\r\n");

   USART_send_string("\tSetting ADC prescaler and disabling free running mode...\r\n");
   setup_ADC(ADC_PRESCALER_32, FALSE);

   USART_send_string("\tEnabling ADC...\r\n");
   ADC_enable();

   USART_send_string("\tSetting ADC reference to Vcc...\r\n");
   ADC_set_reference(ADC_REF_VCC);

   // Configure IO //
   USART_send_string("\tConfiguring IO...\r\n");
   //DDRx corresponds to PORTx/PINx, dependng on direction of data flow -- PORT for output, PIN for input
   DDRA = 0x00;	// Buttons and switches
   DDRB = 0xE7;	// Red enable, green enable and audio out
   DDRC = 0xff;	// Discrete LEDs
   DDRE = 0x47;	// LED Column
   DDRF = 0x00;	// Accelerometer

   // Disable pullups and set outputs low //
   PORTA = 0x00;
   PORTB = 0x01;
   PORTC = 0x81;
   PORTE = 0x00;
   PORTF = 0x00;

   //Set OC1A to toggle
   TCCR1A = 0b01000000;
   // Clk/64 and CTC mode
   TCCR1B = 0b00001011;

   OCR1A = 24;

   USART_send_string("\tSetting SPI\r\n");

   //Set the SPI bus appropriately to use the LED array
   SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);

}

/*
   ADC Accelerometer channels:
   x-axis: ADC_MUX_ADC5
   y-axis: ADC_MUX_ADC6
   z-axis: ADC_MUX_ADC7

   It is recommended that you create your own macros for these 
   to more meaningful names.
   */

/************************************************************
 *******************		MAIN		*********************
 ***********************************************************/

#define CK1024 ()

/** This function needs to setup the variables used by TIMER0 Compare Match (CTC) mode
  with a base clock frequency of clk/1024. This function should return a 1 if it fails and
  a 0 if it does not. Remember, by default the Wunderboard runs at 8MHz for its system
  clock. @return This function returns a 1 is unsuccessful, else return 0.*/
unsigned char initialize_TIMER0()
{
   //See chapter 13 in the data sheet, and look up each of these values in turn.

   /* Set the CTC mode */
   TCCR1B |= (1<<WGM12);
   TCCR1B &= ~(1<<WGM10);
   TCCR1B &= ~(1<<WGM11);
   TCCR1B &= ~(1<<WGM13);
   //TCCR1B |= (1<<WGM13);

   //TCCR1A &= ~(3<<6);

   //TIMSK1 |= (1<<OCIE1A);

   OCR1A = 23438;  //3 seconds

   /* Set the Clock Frequency */
   TCCR1B |= 5; //1024 prescaler


}

ISR(TIMER1_COMPA_vect){
   PORTC = ~PORTC;
   TIFR1 &= ~(1<<OCF1A);
   TCNT1H = 0;
   TCNT1L = 0;
   USART_send_string("Interrupt\n");
}

/** This function checks if TIMER0 has elapsed. 
  @return This function should return a 1 if the timer has elapsed, else return 0*/
unsigned char checkTimer()
{
   if(TIFR1 & (1<<OCF1A))
      return 1;
   return 0;
   //look at the TIFR0 register in the datasheet. 
}

/** This function takes two values, clock and count. The value of count should be copied
  into OCR0A and the value of clock should be used to set CS02:0 in the TCCR0B register.
  The TCNT0 variable should also be reset to 0 so that the new timer rate starts from 0.
  @param [in] clock Insert Comment @param [in] count Insert Comment @return The function
  returns a 1 or error and 0 on successful completion.*/
unsigned char set_TIMER1(unsigned char clock, unsigned char count)
{
   OCR1A = count;

   TCNT0 = 0;
}

//Abstracted function to reset the timer
void resetTimer(){
   TIFR1 |= (1<<OCF1A);

}

//Statemachine used to manage the states;
typedef enum {GREEN, YELLOW, RED} states;
states state = YELLOW;

//The check state function checks if a flag has been set, and if it has, it both resets the flag and changes and counters / states
void checkState(){
   if(checkTimer()){  //If the timer flag is set
      if(state == RED)
	 state = GREEN;
      else
	 ++state;

      //PORTC = ~PORTC;  //Debugging code
      resetTimer();

      if(state == YELLOW)
	 OCR1A = 7813; //Set the timer to 1 second (with 1024 prescaler)
      else
	 OCR1A = 23438;//Set the timer to 3 seconds (with 1024 prescaler)

      //Debugging USART statements
      if(state == RED)
	 USART_send_string("RED                           \r");
      else if (state == GREEN)
	 USART_send_string("GREEN                         \r");
      else
	 USART_send_string("YELLOW                        \r");
   }

}

const int yellowRow = 24;
int main(int argc, char **argv)
{
   initialize();
   initialize_TIMER0();
   clear_array();
   PORTC = 0;
   USART_send_string("Currently outputing color: \n");
   while(1){
      for(unsigned int i = 0; i < 8; ++i){
	 PORTE = i;
	 switch (state){
	    case RED:
	       //PORTE = 1;
	       update_row(224,0,0);
		checkState();
	       break;
	    case GREEN:
	       update_row(0,7,0);
	       checkState();
	       break;
	    case YELLOW:
	       led_off();
	       update_row(yellowRow,0,0);
	       update_row(yellowRow,0,0);
	       update_row(yellowRow,yellowRow,0);
	       update_row(yellowRow,0,0);
	       update_row(yellowRow,0,0);
	       led_off();
	       checkState();
	       break;
	 }
      }
   }
}	

