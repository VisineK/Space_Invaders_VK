/*
 * player.h
 *
 *  Created on: 20 mars 2020
 *      Author: kiki
 */

#ifndef PLAYER_H_
#define PLAYER_H_

// Spaceship
#define SHIP_APPEARANCE ("|-^-|")
#define SHIP_NO_APPEARANCE ("     ")

#define SHOOT_APPEARANCE ("∴")
#define SHOOT_NO_APPEARANCE (" ")

#define INIT_SHIP_X (38)
#define INIT_SHIP_Y (23)

#define INIT_SHOOT_Y (22)


// Enemies
#define SIZE_ENEM (5)

#define ENEM_APPEARANCE1 ("<-o->")
#define ENEM_APPEARANCE2 ("|-o-|")
#define ENEM_APPEARANCE3 ("!-v-!")
#define ENEM_NO_APPEARANCE ("     ")
#define SHOOT_ENEM_APPEARANCE ('¤')
#define LIFE_ENEM (1)

#define BOSS_APPEARANCE ("BO!SS")
#define BOSS_NO_APPEARANCE ("     ")
#define SHOOT_BOOS_APPEARANCE ('ᚖ')
#define LIFE_BOSS (5)

#define ID_MAX (21)
#define ID_BOSS (22)


// Spaceship
void init_spaceship(void);
void move_spaceship(uint8_t);
void shoot_spaceship(uint8_t);


// Enemies
void init_enemies(void);
//void hitbox_enem(info_enemies *p_enem);

#endif /* PLAYER_H_ */
