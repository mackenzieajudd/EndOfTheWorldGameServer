#include "GameManager.h"

struct GameManager gameManager;

void InitialiseGame()
{
	int i;

	for(i = 0; i < 2; i++)
		gameManager.players[i] = GetInitialisedGamePlayer();

	printf("Game Initialised\n");
}

void AddNewPlayer(PLAYER newPlayer, char newPlayerId)
{
	int i;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].valid == 0)
		{
			gameManager.players[i] = GetNewGamePlayer(newPlayer, newPlayerId);
			break;
		}
	}

	printf("%s was added to the game\n", PlayerEnumToString(PlayerIdToPlayer(newPlayerId)));
}

void SetPlayerReady(char playerId)
{
	int i;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].id == playerId)
		{
			gameManager.players[i].ready = PLAYER_IS_READY;
			break;
		}
	}

	printf("%s is ready\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
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

PLAYER PlayerIdToPlayer(char playerId)
{
	int i;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].id == playerId)
			return gameManager.players[i].player;
	}

	return NONE;
}

void AddHouse(char playerId, struct House house)
{
	int i;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].id == playerId)
			AddHouseToBoard(&gameManager.players[i].board, house);
	}
}
