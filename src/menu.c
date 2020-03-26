/*
 * menu.c
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


void window_vt100(void){

	for (int i = 0; i < SCREEN_WIDTH; i++) {			//
		vt100_move(i, 0);								//
		serial_putchar(CHARACTER);						// display of borders VT100 in x (horizontally)
		vt100_move(i, 24);								//
		serial_putchar(CHARACTER);						//
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++) {			//
		vt100_move(0, i);								//
		serial_putchar(CHARACTER);						// display of VT100 borders in y (vertically)
		vt100_move(80, i);								//
		serial_putchar(CHARACTER);						//
	}
}



void home(void) {
	vt100_clear_screen();								// clear screen
	window_vt100();										// call the function which displays the borders VT100

	for (int i = 20; i < 61; i++) {						//
		vt100_move(i, 3);								//
		serial_putchar(CHARACTER);						// display of the title frame in x
		vt100_move(i, 7);								//
		serial_putchar(CHARACTER);						//
	}
	for (int i = 4; i < 8; i++) {						//
		vt100_move(20, i);								//
		serial_putchar(CHARACTER);						// display of the title frame in y
		vt100_move(60, i);								//
		serial_putchar(CHARACTER);						//
	}

	vt100_move(33,5);									// coordinates x, y
	serial_puts("SPACE INVADERS");						// and title display

	vt100_move(20,9);
	serial_puts("  ▄▄      ▄▄  ");
	vt100_move(20,10);
	serial_puts("    █    █    ");
	vt100_move(20,11);
	serial_puts("   ████████   ");
	vt100_move(20,12);
	serial_puts("  ██ ████ ██  ");
	vt100_move(20,13);
	serial_puts(" ████████████ ");
	vt100_move(20,14);
	serial_puts("█ █        █ █");
	vt100_move(20,15);
	serial_puts("   ██    ██   ");				

	vt100_move(45,9);
	serial_puts("  ▄▄      ▄▄  ");
	vt100_move(45,10);
	serial_puts("    █    █    ");
	vt100_move(45,11);
	serial_puts("   ████████   ");
	vt100_move(45,12);
	serial_puts("█ ██ ████ ██ █");
	vt100_move(45,13);
	serial_puts(" ████████████ ");
	vt100_move(45,14);
	serial_puts("   █      █   ");
	vt100_move(45,15);
	serial_puts("  ██      ██  ");

	vt100_move(28,18);									// coordinates x, y
	serial_puts("Press to SPACE for start");			// instruction to start the game

	vt100_move(30,20);									// coordinates x, y
	serial_puts("Press to R for rules");				// instruction to display the rules

	vt100_move(33,23);									// coordinates x, y
	serial_puts("VISINE Killian");						// author of the program

	while(1){
		if(serial_get_last_char() == ' '){				// Condition to launch the game
			vt100_clear_screen();						// if we press space
			window_vt100();								// then clears the screen and displays the borders VT100
			game();										// then call the function that starts the game
		}else if(serial_get_last_char() == 'r'){		// Condition to open the rules
			vt100_clear_screen();						// if we press R
			window_vt100();								// then clears the screen and displays the borders VT100
			rules();									// then call the function that displays the rules
		}
	}

}




void endgame(void){

	vt100_clear_screen();								// clear screen
	window_vt100();										// call the function which displays the borders VT100

	vt100_move(5, 3);
	serial_puts("███      ███  ████████  ██     ██    ██               ██ ██ ███   ██");
	vt100_move(5, 4);
	serial_puts("  ███  ███   ██      ██ ██     ██     ██     ███     ██  ██ ████  ██");
	vt100_move(5, 5);
	serial_puts("    ████     ██      ██ ██     ██      ██   ██ ██   ██   ██ ██ ██ ██");
	vt100_move(5, 6);
	serial_puts("     ██      ██      ██ ██     ██       ██ ██   ██ ██    ██ ██  ████");
	vt100_move(5, 7);
	serial_puts("     ██       ████████   ███████         ███     ███     ██ ██   ███");

	vt100_move(32, 8);
	serial_puts("Your Score : ");
	/*	vt100_move(35, 8);
	serial_puts(score);*/
	vt100_move(32, 10);
	serial_puts("With");
	/*	vt100_move(37, 10);
	serial_puts(life);*/
	vt100_move(32, 10);
	serial_puts("remaining");

	vt100_move(32, 21);									// clear screen
	window_vt100();										// call the function which displays the borders VT100

	serial_puts("Press to M for return Menu");

	vt100_move(32, 23);
	serial_puts("Press to G for Replay");

	if(serial_get_last_char() == 'g'){					// Condition to replay
		vt100_clear_screen();							// if we press G
		window_vt100();									// clear the screen and display the borders VT100
		game();											// then call the function that launches the game
	}else if(serial_get_last_char() == 'm'){			// Condition to return to the menu
		vt100_clear_screen();							// if we press M
		window_vt100();									// clear the screen and display the borders VT100
		home();											// then call the function that opens the menu
	}
}



void game_over(void){

	vt100_clear_screen();								// clear screen
	window_vt100();										// call the function which displays the borders VT100

	vt100_move(5, 3);
	serial_puts("████████   ████   ███    ███ ████████     ███████  ██      ██ ████████ ████████");
	vt100_move(5, 4);
	serial_puts("██         █  █   ████  ████ ██          ██     ██ ██      ██ ██       ██    ██");
	vt100_move(5, 5);
	serial_puts("██        ██  ██  ██ ████ ██ ██████      ██     ██  ██    ██  ██████   ██    ██");
	vt100_move(5, 6);
	serial_puts("██  ████  ██████  ██  ██  ██ ██████      ██     ██  ██    ██  ██████   ████████");
	vt100_move(5, 7);
	serial_puts("██    ██ ██    ██ ██      ██ ██          ██     ██   ██  ██   ██       ██   ██ ");
	vt100_move(5, 8);
	serial_puts("████████ ██    ██ ██      ██ ████████     ███████     ████    ████████ ██    ██");

	vt100_move(32, 9);
	serial_puts("Your Score : ");
	/*	vt100_move(35, 8);
		serial_puts(score);*/

	vt100_move(32, 21);
	serial_puts("Press to M for return Menu");

	vt100_move(32, 23);
	serial_puts("Press to G for Replay");

	if(serial_get_last_char() == 'g'){					// Condition to replay
		vt100_clear_screen();							// if we press G
		window_vt100();									// clear the screen and display the borders VT100
		game();											// then call the function that launches the game
	}else if(serial_get_last_char() == 'm'){			// Condition to return to the menu
		vt100_clear_screen();							// if we press M
		window_vt100();									// clear the screen and display the borders VT100
		home();											// then call the function that opens the menu
	}
}

