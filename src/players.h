/*
 * players.h
 *
 *  Created on: 20 mars 2020
 *      Author: kiki
 */

#ifndef PLAYERS_H_
#define PLAYERS_H_


// Spaceship
#define SHIP_APPEARANCE ("|-^-|")           // appearance of the spaceship 
#define SHIP_NO_APPEARANCE ("     ")

#define SHOOT_APPEARANCE ("∴")              // appearance of the shoot
#define SHOOT_NO_APPEARANCE (" ")

#define INIT_SHIP_X (38)                    // coordinates ship x
#define INIT_SHIP_Y (23)                    // coordinates ship y

#define INIT_SHOOT_Y (22)                   // coordinates shoot y


// Enemies
#define SIZE_ENEM (5)                       // size of enemies

#define ENEM_APPEARANCE1 ("<-o->")          // appearance of the enemy 1
#define ENEM_APPEARANCE2 ("|-o-|")          // appearance of the enemy 2
#define ENEM_APPEARANCE3 ("!-v-!")          // appearance of the enemy 3
#define ENEM_NO_APPEARANCE ("     ")
#define SHOOT_ENEM_APPEARANCE ('¤')         // appearance of the enemy shoot
#define LIFE_ENEM (1)                       // life of enemies

#define BOSS_APPEARANCE ("BO!SS")           // appearance of the BOSS
#define BOSS_NO_APPEARANCE ("     ")
#define SHOOT_BOOS_APPEARANCE ('ᚖ')         // appearance of the BOSS shoot
#define LIFE_BOSS (5)                       // life of BOSS

/*
#define ID_MAX (21)
#define ID_BOSS (22)
*/

// Spaceship
void init_spaceship(void);
void move_spaceship(uint8_t);
void shoot_spaceship(uint8_t);


// Enemies
void init_enemies(void);
//void hitbox_enem(info_enemies *p_enem);

#endif /* PLAYERS_H_ */
