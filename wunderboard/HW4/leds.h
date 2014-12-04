/** 
 * @file
 * @author Matthew Shuman
 * @author Joey Tomlinson
 * @author Dan Albert
 * @date Created 8/5/09
 * @date Last updated 7/19/10
 * @version 1.1
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
 * Includes functions for setting up and reading the hardware ADC on the attiny26.
 * 
 * @section HARDWARE
 * Target Device: ATTINY26L
 * 
 */
#ifndef LEDS_H
#define LEDS_H

#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>

#include "types.h"


void clear_array(void);

void set_array_green(unsigned char rows);
void set_array_blue(unsigned char rows);
void set_array_red(unsigned char rows);

void update_row( uint8_t red, uint8_t green, uint8_t blue );
void led_red( uint8_t x, uint8_t y );
void led_green( uint8_t x, uint8_t y );
void led_blue( uint8_t x, uint8_t y );
void led_off( void );


#endif
