/*
 * delay.c
 *
 *  Created on: 20 mars 2020
 *      Author: kiki
 */

#include "vt100.h"
#include "menu.h"

void delay(unsigned long int t){

	uint8_t i = 0;
	unsigned long int time = t * 100000;
	do{
		i++;
	}while(i <= time);
}


