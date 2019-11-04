/*
 * oled.c
 *
 * Created: 2019/11/4 13:45:20
 * Author : Pluto
 */ 

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <util/delay.h>
#include "bmp.h"
#include "oled.h"

void Sys_Init(void);

int main(void)
{
	Sys_Init();

	OLED_Init();			//≥ı ºªØOLED
	OLED_Clear();
	OLED_ShowString(30,1,"OLED TEST");

    /* Replace with your application code */
    while (1) 
    {
    }
}

void Sys_Init(void)
{
	/* SPI Init*/
	PORTB |= _BV(0);
	DDRB |= _BV(0); // PB0: SS
	PORTB &= ~_BV(1);
	DDRB |= _BV(1); // PB1: SCK
	PORTB &= ~_BV(2);
	DDRB |= _BV(2); // PB2: MOSI
	PORTB &= ~_BV(3);
	DDRB &= ~_BV(3); // PB3: MISO
	/* Control PIN */
	PORTA |= _BV(0);
	DDRA |= _BV(0); // PA0: DC
	PORTA |= _BV(1);
	DDRA |= _BV(1); // PA1: RST
	
	// SPI Master device, LSB first, Mode 3, 8MHz/16 = 500kHz
	SPCR = ((1<<SPE) | (1<<MSTR) | (1<<SPR0));
	// No interrupts or double speed...
	SPSR  = (0<<SPI2X);
	SPCR |= ( 1 << SPIE );
	
	_delay_ms(10);	
}