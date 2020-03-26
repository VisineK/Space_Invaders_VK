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
#include "players.h"

static uint8_t life_player = LIFE_NBR;						// life_player takes the value defined by LIFE_NBR in game.h
static uint8_t *life = &life_player;						// *life points to the value of life_player


void game(void){

	//uint8_t i=0;

	init_spaceship();										// We call the init_spaceship function, which initializes our ship
	init_enemies();											// We call the init_enemies function, which initializes the enemies

	while(1){												// I+nfinite loop
		uint8_t touch = serial_get_last_char();

		lifes();											// call the lifes function
		score();											// call the score function
		shield();											// call the shield functionœ

		move_spaceship(touch);								// call the move_spaceship function
		shoot_spaceship(touch);								// call the shoot_spaceship function

/*
		for(i = 0; i <= ID_MAX; i++){
			hitbox_enem(&tab_enem[i]);
		}
*/


		if(serial_get_last_char() == 'r'){					// Condition to open the rules
			vt100_clear_screen();							// if we press R
			window_vt100();									// then clears the screen and displays the borders VT100
			rules();										// then call the function that displays the rules
		}else if(serial_get_last_char() == 'm'){			// Condition to return to the menu
			vt100_clear_screen();							// if we press M
			window_vt100();									// clear screen and display VT100 borders
			home();											// call menu function
		}
	}
}


void lifes(void){											// lifes function

	uint8_t l;
	for(l = 0; l <= LIFE_NBR - 1; l++){						//
		vt100_move(LIFEX, LIFEY);							//
		serial_puts("Lifes :");								// Displays the player's life
		vt100_move(HEARTX, HEARTY);							//
		serial_puts("❤ ❤ ❤ ");								//
	}

	switch (*life)											//
	{														//
	case 2:													//
		vt100_move(74, 2);									//
		serial_puts("♡");									//
		break;												//
															//
	case 1:													// Reduces player's life when hit by the enemy
		vt100_move(72, 2);									//
		serial_puts("♡");									//	
		break;												//
															//
	case 0:													//
		vt100_move(70, 2);									//
		serial_puts("♡");									//
		break;												//
	}

}


void score(void){											// score function

	vt100_move(SCOREX, SCOREY);								// Displays the 
	serial_puts("Score : 0000");							// player's score
}


void shield(void){											// shield function
	uint8_t SX = SHIELDX;
	uint8_t SY = SHIELDY;
	uint8_t i = 0;

	while(i < 4){											//
		for(SY = 19; SY < 21; SY++){						//
			vt100_move(SX, SY);								//
			serial_puts(" ████████ ");						//
			SY += 1;										//
			vt100_move(SX, SY);								// Loop which allows to 
			serial_puts("██████████");						// display the 4 shields
			SY += 1;										//
			vt100_move(SX, SY);								//
			serial_puts("████  ████");						//
			SX += 18;										//
			i++;											//
		}
	}
}
