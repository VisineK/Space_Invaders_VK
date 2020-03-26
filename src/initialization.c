/*
 * initialization.c
 *
 *  Created on: 07 janviers 2020
 *      Author: VisineK
 */

#include "serial.h"
#include "vt100.h"
#include "initialization.h"

void init(void){
	serial_init(BAUDS);		// Initialization of the transmission speed (in seconds)
	vt100_clear_screen();	// Clear screen
}
