#include "GameManager.h"

struct GameManager gameManager;

void InitialiseGame()
{
	int i;

	for(i = 0; i < 2; i++)
		gameManager.players[i] = GetInitialisedGamePlayer();

	printf("Game Initialised\n");
}

void AddNewPlayer(PLAYER newPlayer)
{
	int i;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].valid == 0)
		{
			gameManager.players[i] = GetNewGamePlayer(newPlayer);
			break;
		}
	}

	printf("%s was added to the game\n", PlayerEnumToString(newPlayer));
}

void SetPlayerReady(PLAYER player)
{
	int i;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].player == player)
		{
			gameManager.players[i].ready = PLAYER_IS_READY;
			break;
		}
	}

	printf("%s is ready\n", PlayerEnumToString(player));
}

struct GameManager GetGameManager()
{
	return gameManager;
}

int ArePlayersReady()
{
	int i;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].ready != PLAYER_IS_READY)
			return ALL_PLAYERS_NOT_READY;
	}

	return ALL_PLAYERS_READY;
}
