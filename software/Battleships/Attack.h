#ifndef ATTACK_H_
#define ATTACK_H_

#include "GameManager.h"
#include <string.h>

typedef enum
{
	BASIC_ATTACK = 1
}ATTACK;

void HandleBasicAttack(char playerId, unsigned char attackData[]);

#endif
