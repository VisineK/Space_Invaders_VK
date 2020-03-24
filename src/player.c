/*
 * player.c
 *
 *  Created on: 20 mars 2020
 *      Author: kiki
 */
#include <stdlib.h>
#include <stdio.h>

#include "vt100.h"
#include "serial.h"

#include "menu.h"
#include "game.h"
#include "player.h"
#include "delay.h"

static uint8_t xship;
static uint8_t yship;
uint8_t shootx;
uint8_t shooty;

/*
typedef struct {
	uint8_t E1[7][5];
	uint8_t E2[7][5];
	uint8_t E3[7][5];
	uint8_t Boss[1][5];
}pos_enem;

pos_enem position_enemies;
pos_enem *p_enem = &position_enemies;

uint8_t info_enemies tabenem[22][5] = {
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
};*/

//static uint8_t life_enem = 0;


void init_spaceship(void){
	xship = INIT_SHIP_X;
	yship = INIT_SHIP_Y;

	shooty = INIT_SHOOT_Y;

	vt100_move(xship, yship);																				//
	serial_puts(SHIP_APPEARANCE);
}


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



void init_enemies(void){

	vt100_move(10, 4);
	serial_puts(ENEM_APPEARANCE1);
	vt100_move(20, 4);
	serial_puts(ENEM_APPEARANCE1);
	vt100_move(30, 4);
	serial_puts(ENEM_APPEARANCE1);
	vt100_move(40, 4);
	serial_puts(ENEM_APPEARANCE1);
	vt100_move(50, 4);
	serial_puts(ENEM_APPEARANCE1);
	vt100_move(60, 4);
	serial_puts(ENEM_APPEARANCE1);
	vt100_move(70, 4);
	serial_puts(ENEM_APPEARANCE1);

	vt100_move(10, 6);
	serial_puts(ENEM_APPEARANCE2);
	vt100_move(20, 6);
	serial_puts(ENEM_APPEARANCE2);
	vt100_move(30, 6);
	serial_puts(ENEM_APPEARANCE2);
	vt100_move(40, 6);
	serial_puts(ENEM_APPEARANCE2);
	vt100_move(50, 6);
	serial_puts(ENEM_APPEARANCE2);
	vt100_move(60, 6);
	serial_puts(ENEM_APPEARANCE2);
	vt100_move(70, 6);
	serial_puts(ENEM_APPEARANCE2);

	vt100_move(10, 8);
	serial_puts(ENEM_APPEARANCE3);
	vt100_move(20, 8);
	serial_puts(ENEM_APPEARANCE3);
	vt100_move(30, 8);
	serial_puts(ENEM_APPEARANCE3);
	vt100_move(40, 8);
	serial_puts(ENEM_APPEARANCE3);
	vt100_move(50, 8);
	serial_puts(ENEM_APPEARANCE3);
	vt100_move(60, 8);
	serial_puts(ENEM_APPEARANCE3);
	vt100_move(70, 8);
	serial_puts(ENEM_APPEARANCE3);

}
/*
	for(x = 0; x != 7; x ++){
		p_enem->E1[x][0] = x * 10;
		p_enem->E2[x][0] = x * 10;
		p_enem->E3[x][0] = x * 10;

		p_enem->E1[x][1] = 4;
		p_enem->E2[x][1] = 6;
		p_enem->E3[x][1] = 8;

		p_enem->E1[x][2] = LIFE_ENEM;
		p_enem->E2[x][2] = LIFE_ENEM;
		p_enem->E3[x][2] = LIFE_ENEM;

		p_enem->E1[x][3] = x;
		p_enem->E2[x][3] = x + 7;
		p_enem->E3[x][3] = x + 14;

		p_enem->E1[x][4] = SIZE_ENEM;
		p_enem->E2[x][4] = SIZE_ENEM;
		p_enem->E3[x][4] = SIZE_ENEM;

		if(x < 7)
		vt100_move(tab_enem[i][j], tab_enem[i][j]);
		serial_puts(ENEM_APPEARANCE3);
	}else if (i < 14){

		vt100_move(tab_enem[i][j], tab_enem[i][j]);
		serial_puts(ENEM_APPEARANCE2);
	}else{

		vt100_move(tab_enem[i][j], tab_enem[i][j]);
		serial_puts(ENEM_APPEARANCE1);
	}
}*/

