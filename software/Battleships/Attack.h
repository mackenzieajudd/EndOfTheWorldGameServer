#ifndef ATTACK_H_
#define ATTACK_H_

#include "GameManager.h"
#include <string.h>
#include "House.h"

#define HIT 65
#define MISS 66

typedef enum
{
	BASIC_ATTACK = 65,
	SCATTER_ATTACK
}ATTACK;

void HandleBasicAttack(char playerId, unsigned char attackData[]);

void CalculateBasicDamages(struct GamePlayer* player, char x1, char y1, char x2, char y2);

#endif
