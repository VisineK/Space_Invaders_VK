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
#include "players.h"
#include "delay.h"

static uint8_t xship;							// coordinates ship x
static uint8_t yship;							// coordinates ship y
uint8_t shootx;									// coordinates shoot ship x
uint8_t shooty;									// coordinates shoot ship y

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


void init_spaceship(void){						//
	xship = INIT_SHIP_X;						//
	yship = INIT_SHIP_Y;						//
												// Initializes the coordinates 
	shooty = INIT_SHOOT_Y;						// of the ship and the shoot
												//
	vt100_move(xship, yship);					//															//
	serial_puts(SHIP_APPEARANCE);				// We display the ship
}


void move_spaceship(uint8_t move){				// Initialization of the spaceship movement

	if ((move == 'q') && (xship > 3)){			// If you press "q" and the ship's x is > 3, then
												//
		vt100_move(xship, yship);				//
		serial_puts(SHIP_NO_APPEARANCE);		// We erase the ship
		xship -= 1;								// We decrement x
		vt100_move(xship, yship);				// And we display the ship at the new coordinates
		serial_puts(SHIP_APPEARANCE);			//
												//
	}else if((move == 'd') && (xship < 74)){	// If you press "d" and the ship's x is < 74, then
		vt100_move(xship, yship);				//
		serial_puts(SHIP_NO_APPEARANCE);		// We erase the ship
		xship += 1;								// We increment x
		vt100_move(xship, yship);				// And we display the ship at the new coordinates
		serial_puts(SHIP_APPEARANCE);			//
	}

}


void shoot_spaceship(uint8_t tir){				// Initialization of the spaceship shoot

	if(shooty == 22){							// We place the coordinates of the missile 
		shootx = xship + 2;						// in the middle of the ship
	}

	if((tir == 'z') || (shooty != 22)){			// If you press "z" and the y of the shoot is != 22, then

		vt100_move(shootx, shooty);				//
		serial_puts(SHIP_NO_APPEARANCE);		// We erase the shoot
		shooty -= 1;							// We decrement y
		vt100_move(shootx, shooty);				// And we display the shoot at the new coordinates
		serial_puts(SHOOT_APPEARANCE);			//
	}

	if (shooty == 3)							// If the y of the shoot is == 3, then
	{
		vt100_move(shootx, shooty);				//
		serial_puts(SHIP_NO_APPEARANCE);		// We erase the shoot

		shooty = INIT_SHOOT_Y;					// And we reset the shoot y to the original coordinates
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

