/*
 * menu.c
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


/* Display of the borders of the VT100 80x24 terminal */
void window_vt100(void){

	for (int i = 0; i < SCREEN_WIDTH; i++) {
		vt100_move(i, 0);
		serial_putchar(CHARACTER);
		vt100_move(i, 24);
		serial_putchar(CHARACTER);
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		vt100_move(0, i);
		serial_putchar(CHARACTER);
		vt100_move(80, i);
		serial_putchar(CHARACTER);
	}
}


/* Home menu */
void home(void) {
	vt100_clear_screen();
	window_vt100();

	for (int i = 20; i < 61; i++) {
		vt100_move(i, 3);
		serial_putchar(CHARACTER);
		vt100_move(i, 7);
		serial_putchar(CHARACTER);
	}
	for (int i = 4; i < 8; i++) {
		vt100_move(20, i);
		serial_putchar(CHARACTER);
		vt100_move(60, i);
		serial_putchar(CHARACTER);
	}

	vt100_move(33,5);
	serial_puts("SPACE INVADERS");

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

	vt100_move(28,18);
	serial_puts("Press to SPACE for start");

	vt100_move(30,20);
	serial_puts("Press to R for rules");

	vt100_move(33,23);
	serial_puts("VISINE Killian");

	while(1){
		if(serial_get_last_char() == ' '){
			vt100_clear_screen();
			window_vt100();
			game();
		}else if(serial_get_last_char() == 'r'){
			vt100_clear_screen();
			window_vt100();
			rules();
		}
	}

}


/* End game - If the player wins */
void endgame(void){

	vt100_clear_screen();
	window_vt100();

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

	vt100_move(32, 21);
	window_vt100();

	serial_puts("Press to M for return Menu");

	vt100_move(32, 23);
	serial_puts("Press to G for Replay");

	if(serial_get_last_char() == 'g'){
		vt100_clear_screen();
		window_vt100();
		game();
	}else if(serial_get_last_char() == 'm'){
		vt100_clear_screen();
		window_vt100();
		home();
	}
}


/* End game - If the player loses */
void game_over(void){

	vt100_clear_screen();
	window_vt100();

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

	if(serial_get_last_char() == 'g'){
		vt100_clear_screen();
		window_vt100();
		game();
	}else if(serial_get_last_char() == 'm'){
		vt100_clear_screen();
		window_vt100();
		home();
	}
}

