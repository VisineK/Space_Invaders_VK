/*
 * rules.c
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


void rules(void){

	vt100_clear_screen();
	window_vt100();
	vt100_move(32,2);
	serial_puts("Rules of the game");

	vt100_move(5,4);
	serial_puts("Commands :");

	vt100_move(5,6);
	serial_puts("z");
	vt100_move(10,6);
	serial_puts("Use z to shoot");

	vt100_move(5,8);
	serial_puts("Q");
	vt100_move(10,8);
	serial_puts("Use q to go left");
	vt100_move(5,10);
	serial_puts("D");
	vt100_move(10,10);
	serial_puts("And use d to go right");

	vt100_move(40,6);
	serial_puts("M");
	vt100_move(45,6);
	serial_puts("Press m to open the menu");
	vt100_move(40,8);
	serial_puts("R");
	vt100_move(45,8);
	serial_puts("press r to open the rules");


	vt100_move(5,12);
	serial_puts("WARNING, a wave of enemies is coming.Your mission is to destroy them");
	vt100_move(5,13);
	serial_puts("without losing your 3❤.");
	vt100_move(5,15);
	serial_puts("There are 3 types of enemies. If you destroy them, you gain points.");
	vt100_move(4,17);
	serial_puts("<-o-> = 10 Points, |-o-| = 20 Points, !-v-! = 50 Points, BO!SS = 100 Points");

	vt100_move(14,19);
	serial_puts("You start the game with 3 ❤. If you are hit, you lose 1 ♡ ");
	vt100_move(14,20);
	serial_puts("As soon as you lose your last ♡. You lost, the game stops.");
	vt100_move(20,22);
	serial_puts("Good luck !	May fate be favorable to you");

	while(1){
		if(serial_get_last_char() == ' '){				// Condition to launch the game
			vt100_clear_screen();						// if we press space
			window_vt100();								// clear screen and display VT100 borders
			game();										// call the game function
		}else if(serial_get_last_char() == 'm'){		// Condition to return to the menu 
			vt100_clear_screen();						// if we press M
			window_vt100();								// clear screen and display VT100 borders
			home();										// call menu function
		}
	}
}
