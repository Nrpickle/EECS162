/** Includes */
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#include "wunder.h"
#include "usart.h"
#include "adc.h"
#include "leds.h"
/*
void initialize()
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
	TCCR1A = (1<<COM1A0);
	// Clk/64 and CTC mode
	TCCR1B = (1<<WGM12)|(1<<CS11)|(1<<CS10);

	OCR1A = 24;

	USART_send_string("\tSetting SPI\r\n");
	
	//Set the SPI bus appropriately to use the LED array
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);

}
*/
