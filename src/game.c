/*
 * game.c
 *
 *  Created on: 20 mars 2020
 *      Author: kiki
 */
#include <stdlib.h>

#include "serial.h"
#include "vt100.h"

#include "menu.h"
#include "game.h"
#include "rules.h"
#include "player.h"

static uint8_t life_player = LIFE_NBR;
static uint8_t *life = &life_player;

void game(void){

	//uint8_t i=0;

	init_spaceship();
	init_enemies();

	while(1){
		uint8_t touch = serial_get_last_char();

		if(serial_get_last_char() == 'r'){
			vt100_clear_screen();
			window_vt100();
			rules();
		}else if(serial_get_last_char() == 'm'){
			vt100_clear_screen();
			window_vt100();
			home();
		}

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
