/*
 * game.h
 *
 *  Created on: 07 janviers 2020
 *      Author: VisineK
 */

#ifndef GAME_H_
#define GAME_H_

#define LIFE_NBR (3)
#define LIFEX (61)      // coordinates life x
#define LIFEY (2)       // coordinates life y
#define HEARTX (70)     // coordinates heart x  
#define HEARTY (2)      // coordinates heart y

#define SCOREX (6)      // coordinates score x
#define SCOREY (2)      // coordinates score y

#define SHIELDX (9)     // coordinates shield x
#define SHIELDY (19)    // coordinates shield y

void game(void);
void lifes(void);
void score(void);
void shield(void);

#endif /* GAME_H_ */
