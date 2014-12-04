#ifndef WUNDER_H
#define WUNDER_H

/** Constants */
//#define F_CPU 8000000U
#define SERIAL_SPEED 9600
#define BAUD_RATE (((F_CPU)/(SERIAL_SPEED*8UL))-1)
#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

//void initialize( void );

#endif
