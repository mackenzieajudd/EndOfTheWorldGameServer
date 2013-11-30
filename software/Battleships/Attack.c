#include "Attack.h"
#include "GameManager.h"

void HandleBasicAttack(char playerId, unsigned char attackData[])
{
	printf("Handling BASIC_ATTACK from player %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
	BasicAttackPlayer(playerId, (attackData[0] - (int)UNOCCUPIED_SPACE), (attackData[1] - (int)UNOCCUPIED_SPACE), (attackData[2] - (int)UNOCCUPIED_SPACE), (attackData[3] - (int)UNOCCUPIED_SPACE));
}

void HandleScatterAttack(char playerId, unsigned char attackData[])
{
	int numAttacks = attackData[0];
	int i;

	printf("Handling SCATTER_ATTACK from player %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	for(i = 0; i < numAttacks; i++)
	{
		BasicAttackPlayer(playerId, (attackData[(2 * i) + 1] - (int)UNOCCUPIED_SPACE), (attackData[(2 * i) + 2] - (int)UNOCCUPIED_SPACE), (attackData[(2 * i) + 1] - (int)UNOCCUPIED_SPACE), (attackData[(2 * i) + 2] - (int)UNOCCUPIED_SPACE));
	}
}

void CalculateBasicDamages(struct GamePlayer* player, char x1, char y1, char x2, char y2)
{
	int i;
	int j;
	int k;
	char results[3];
	int startingHealth;

	printf("Calculating damages at location %d %d %d %d on %s\n", x1, y1, x2, y2, PlayerEnumToString(PlayerIdToPlayer((*player).id)));

	for(j = x1; j <= x2; j++)
	{
		for(k = y1; k <= y2; k++)
		{
			if((*player).board.board[j][k] == OCCUPIED_SPACE)
			{
				results[0] = (*player).id  + MESSAGE_OFFSET;
				results[1] = HIT;
				results[2] = j + MESSAGE_OFFSET;
				results[3] = k + MESSAGE_OFFSET;

				(*player).board.board[j][k] = UNOCCUPIED_SPACE;

				SendAttackResult((*player).id, results);
			}
			else
			{
				results[0] = (*player).id + MESSAGE_OFFSET;
				results[1] = MISS;
				results[2] = j + MESSAGE_OFFSET;
				results[3] = k + MESSAGE_OFFSET;

				SendAttackResult((*player).id, results);
			}
		}
	}
}
