/*
 * initialization.c
 *
 *  Created on: 20 mars 2020
 *      Author: kiki
 */


#include "serial.h"
#include "vt100.h"
#include "initialization.h"

void init(void){
	serial_init(BAUDS);
	vt100_clear_screen();
}
