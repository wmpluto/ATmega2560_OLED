#ifndef _IO_HAL_H
#define _IO_HAL_H

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <util/delay.h>

#define OLED_CS_Clr()  PORTB &= ~_BV(0)
#define OLED_CS_Set()  PORTB |= _BV(0)

#define OLED_RST_Clr() PORTA &= ~_BV(1)
#define OLED_RST_Set() PORTA |= _BV(1)

#define OLED_DC_Clr() PORTA &= ~_BV(0)
#define OLED_DC_Set() PORTA |= _BV(0)

inline void SPI_Send(uint8_t dat){
	SPDR = dat;//dummy write to kick off SCLk
	loop_until_bit_is_set(SPSR, SPIF);	 		 
}

inline void Io_Init(void) {
    /* SPI Init */
    /* Control IO Init */
}
#endif