/*
 * game.c
 *
 *  Created on: 07 janviers 2020
 *      Author: VisineK
 */

#include <stdlib.h>

#include "serial.h"
#include "vt100.h"

#include "menu.h"
#include "game.h"
#include "rules.h"
#include "players.h"

static uint8_t life_player = LIFE_NBR;						// life_player takes the value defined by LIFE_NBR in game.h
static uint8_t *life = &life_player;						// *life points to the value of life_player


/* Game function: We first call the functions which initialize the spaceship and the enemies for the coordinates and the display.
   Then in an infinite loop, we call the different functions like: the movement and the shooting of the spaceship and the enemies, 
   the counter of lives, of score and the shields. */
void game(void){

	//uint8_t i=0;

	init_spaceship();
	init_enemies();

	while(1){
		uint8_t touch = serial_get_last_char();

		lifes();
		score();
		shield();

		move_spaceship(touch);
		shoot_spaceship(touch);

/*
		for(i = 0; i <= ID_MAX; i++){
			hitbox_enem(&tab_enem[i]);
		}
*/


		if(serial_get_last_char() == 'r'){
			vt100_clear_screen();
			window_vt100();
			rules();
		}else if(serial_get_last_char() == 'm'){
			vt100_clear_screen();
			window_vt100();
			home();
		}
	}
}


void lifes(void){

	uint8_t l;
	for(l = 0; l <= LIFE_NBR - 1; l++){
		vt100_move(LIFEX, LIFEY);
		serial_puts("Lifes :");
		vt100_move(HEARTX, HEARTY);
		serial_puts("❤ ❤ ❤ ");
	}

	switch (*life)
	{
	case 2:
		vt100_move(74, 2);
		serial_puts("♡");
		break;
		
	case 1:
		vt100_move(72, 2);
		serial_puts("♡");
		break;

	case 0:
		vt100_move(70, 2);
		serial_puts("♡");
		break;
	}

}


void score(void){

	vt100_move(SCOREX, SCOREY);
	serial_puts("Score : 0000");
}


void shield(void){
	uint8_t SX = SHIELDX;
	uint8_t SY = SHIELDY;
	uint8_t i = 0;

	while(i < 4){
		for(SY = 19; SY < 21; SY++){
			vt100_move(SX, SY);
			serial_puts(" ████████ ");
			SY += 1;
			vt100_move(SX, SY);
			serial_puts("██████████");
			SY += 1;
			vt100_move(SX, SY);
			serial_puts("████  ████");
			SX += 18;
			i++;
		}
	}
}
