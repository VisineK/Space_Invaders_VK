/*
 * menu.h
 *
 *  Created on: 20 mars 2020
 *      Author: kiki
 */

#ifndef MENU_H_
#define MENU_H_

#define SCREEN_HEIGHT (24)  // We define the height of the window
#define SCREEN_WIDTH (81)   // We define the width of the window
#define CHARACTER ('#')     // We define the character that forms the window

void window_vt100(void);
void home(void);
void endgame(void);
void game_over(void);



#endif /* MENU_H_ */
