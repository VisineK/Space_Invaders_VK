/*
 * player.c
 *
 *  Created on: 07 janviers 2020
 *      Author: VisineK
 */

#include <stdlib.h>
#include <stdio.h>

#include "vt100.h"
#include "serial.h"

#include "menu.h"
#include "game.h"
#include "players.h"
#include "delay.h"


/* SPACESHIP */

/* Declaration coordinates x and y for the ship and shoot */
static uint8_t xship;
static uint8_t yship;
uint8_t shootx;
uint8_t shooty;


/* ENEMIES */

/* Enemy information board */
uint8_t tab_enem[22][5] = {
		{ 10, 4, LIFE_ENEM, 0, SIZE_ENEM },		// x, y, life, ID, size
		{ 20, 4, LIFE_ENEM, 1, SIZE_ENEM },
		{ 30, 4, LIFE_ENEM, 2, SIZE_ENEM },
		{ 40, 4, LIFE_ENEM, 3, SIZE_ENEM },
		{ 50, 4, LIFE_ENEM, 4, SIZE_ENEM },
		{ 60, 4, LIFE_ENEM, 5, SIZE_ENEM },
		{ 70, 4, LIFE_ENEM, 6, SIZE_ENEM },
		{ 10, 6, LIFE_ENEM, 7, SIZE_ENEM },
		{ 20, 6, LIFE_ENEM, 8, SIZE_ENEM },
		{ 30, 6, LIFE_ENEM, 9, SIZE_ENEM },
		{ 40, 6, LIFE_ENEM, 10, SIZE_ENEM },
		{ 50, 6, LIFE_ENEM, 11, SIZE_ENEM },
		{ 60, 6, LIFE_ENEM, 12, SIZE_ENEM },
		{ 70, 6, LIFE_ENEM, 13, SIZE_ENEM },
		{ 10, 8, LIFE_ENEM, 14, SIZE_ENEM },
		{ 20, 8, LIFE_ENEM, 15, SIZE_ENEM },
		{ 30, 8, LIFE_ENEM, 16, SIZE_ENEM },
		{ 40, 8, LIFE_ENEM, 17, SIZE_ENEM },
		{ 50, 8, LIFE_ENEM, 18, SIZE_ENEM },
		{ 60, 8, LIFE_ENEM, 19, SIZE_ENEM },
		{ 70, 8, LIFE_ENEM, 20, SIZE_ENEM },
		{ 40, 5, LIFE_BOSS, ID_BOSS, SIZE_ENEM },
};

//static uint8_t life_enem = 0;




/* SPACESHIP */

/* Initializes the coordinates ship and shoot */
void init_spaceship(void){
	xship = INIT_SHIP_X;
	yship = INIT_SHIP_Y;

	shooty = INIT_SHOOT_Y;

	vt100_move(xship, yship);
	serial_puts(SHIP_APPEARANCE);
}


/* Function for left and right movement of the spaceship */
void move_spaceship(uint8_t move){

	if ((move == 'q') && (xship > 3)){

		vt100_move(xship, yship);
		serial_puts(SHIP_NO_APPEARANCE);
		xship -= 1;
		vt100_move(xship, yship);
		serial_puts(SHIP_APPEARANCE);

	}else if((move == 'd') && (xship < 74)){
		vt100_move(xship, yship);
		serial_puts(SHIP_NO_APPEARANCE);
		xship += 1;
		vt100_move(xship, yship);
		serial_puts(SHIP_APPEARANCE);
	}

}


/* Function to shoot with the spaceship */
void shoot_spaceship(uint8_t tir){

	if(shooty == 22){ 
		shootx = xship + 2;
	}

	if((tir == 'z') || (shooty != 22)){

		vt100_move(shootx, shooty);
		serial_puts(SHIP_NO_APPEARANCE);
		shooty -= 1;
		vt100_move(shootx, shooty);
		serial_puts(SHOOT_APPEARANCE);
	}

	if (shooty == 3)
	{
		vt100_move(shootx, shooty);
		serial_puts(SHIP_NO_APPEARANCE);

		shooty = INIT_SHOOT_Y;
	}
}


/* ENEMIES */


void init_enemies(void){
	uint8_t i;

	for(i = 0; i < 21; i++){

		if(i < 7){
			vt100_move(tab_enem[i][0], tab_enem[i][1]);
			serial_puts(ENEM_APPEARANCE3);
		}else if (i < 14){

			vt100_move(tab_enem[i][0], tab_enem[i][1]);
			serial_puts(ENEM_APPEARANCE2);
		}else{

			vt100_move(tab_enem[i][0], tab_enem[i][1]);
			serial_puts(ENEM_APPEARANCE1);
		}
	}
}

