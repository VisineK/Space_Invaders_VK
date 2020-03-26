/*
 * enemies.h
 *
 *  Created on: 07 janviers 2020
 *      Author: VisineK
 */
/*
#ifndef ENEMIES_H_
#define ENEMIES_H_




typedef struct
{
	uint8_t enemx;
	uint8_t enemy;
	uint8_t life_enem;
	uint8_t id;
	uint8_t taille;
} info_enemies;

extern info_enemies tab_enem[22];

extern uint8_t shootx;
extern uint8_t *p_sx;
extern uint8_t shooty;
extern uint8_t *p_sy;

void init_enemies(void);
void hitbox_enem(info_enemies *p_enem);

#endif /* ENEMIES_H_ */


