#include "Attack.h"
#include "GameManager.h"

void HandleBasicAttack(char playerId, unsigned char attackData[])
{
	printf("Handling BASIC_ATTACK from player %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
	BasicAttackPlayer(playerId, (attackData[0] - MESSAGE_OFFSET), (attackData[1] - MESSAGE_OFFSET), (attackData[2] - MESSAGE_OFFSET), (attackData[3] - MESSAGE_OFFSET));
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
				results[0] = (*player).id;
				results[1] = HIT;
				results[2] = j + MESSAGE_OFFSET;
				results[3] = k + MESSAGE_OFFSET;

				(*player).board.board[j][k] = UNOCCUPIED_SPACE;

				SendAttackResult((*player).id, results);
			}
			else
			{
				results[0] = (*player).id;
				results[1] = MISS;
				results[2] = j + MESSAGE_OFFSET;
				results[3] = k + MESSAGE_OFFSET;

				SendAttackResult((*player).id, results);
			}
		}
	}
}
