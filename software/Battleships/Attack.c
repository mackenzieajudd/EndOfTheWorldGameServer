#include "Attack.h"

void HandleBasicAttack(char playerId, unsigned char attackData[])
{
	printf("Handling BASIC_ATTACK from player %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
}
