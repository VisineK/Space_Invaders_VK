/*
 * delay.c
 *
 *  Created on: 07 janviers 2020
 *      Author: VisineK
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


