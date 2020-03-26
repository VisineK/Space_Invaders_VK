/*
 * enemies.c
 *
 *  Created on: 07 janviers 2020
 *      Author: VisineK
 */
/*
#include <stdlib.h>
#include <stdio.h>

#include "vt100.h"
#include "serial.h"

#include "menu.h"
#include "game.h"
#include "rules.h"
#include "players.h"
#include "enemies.h"

info_enemies *p_enem;

typedef struct {
	uint8_t E1[7][5];
	uint8_t E2[7][5];
	uint8_t E3[7][5];
	uint8_t Boss[1][5];
}pos_enem;

pos_enem position_enemies;
pos_enem *p_enem = &position_enemies;

ou

info_enemies tab_enem[22] = {
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

static uint8_t life_enem = 0;
//static uint8_t direction = 0;
//static uint8_t counter = 0;
//static uint8_t counter1 = 0;
//static uint8_t x_shoot_enem;
//static uint8_t y_shoot_enem;


void init_enemies(void){
	static uint8_t i;

	for (i = 0; i < 21; i++){
		if (i < 7){

			vt100_move(p_enem[0]->enemx, p_enem->enemy);
			serial_puts(ENEM_APPEARANCE3);
		}else if (i < 14){

			vt100_move(p_enem->enemx, p_enem->enemy);
			serial_puts(ENEM_APPEARANCE2);
		}else{

			vt100_move(p_enem->enemx, p_enem->enemy);
			serial_puts(ENEM_APPEARANCE1);
		}
	}
}


void hitbox_enem(info_enemies *p_enem){

	uint8_t i;
	for(i = 0; i < 21; i++){
		if((*p_sx >= p_enem->enemx) && (*p_sx <= p_enem->enemx + 4) && (*p_sy == p_enem->enemy)){
			if(life_enem == 1){
				continue;
			}else{
				vt100_move(p_enem->enemx, p_enem->enemy);
				serial_puts(ENEM_NO_APPEARANCE);
				life_enem = 1;
			}
		}
	}
}
*/
