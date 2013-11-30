#include "GameManager.h"
#include "Communications.h"
#include "Board.h"

struct GameManager gameManager;

void wait(float seconds)
{
	alt_timestamp_start();
	while((float)(alt_timestamp())/(float)(alt_timestamp_freq()) < seconds);
}

void InitialiseGame()
{
	int i;

	for(i = 0; i < 2; i++)
		gameManager.players[i] = GetInitialisedGamePlayer();

	printf("Game Initialised\n");
}

void AddNewPlayer(PLAYER newPlayer, char newPlayerId, char* playerName, int nameSize)
{
	int i;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].valid == 0)
		{
			gameManager.players[i] = GetNewGamePlayer(newPlayer, newPlayerId, playerName, nameSize);
			break;
		}
	}

	printf("%s was added to the game\n", PlayerEnumToString(PlayerIdToPlayer(newPlayerId)));
}

void SetPlayerReady(char playerId)
{
	int i;

	for(i = 0; i < NUMBER_OF_PLAYERS; i++)
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

	return ALL_GAME_PLAYERS_READY;
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

char* PlayerToPlayerName(PLAYER player)
{
	int i;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].player == player)
			return gameManager.players[i].name;
	}

	return "";
}

int PlayerToPlayerNameLength(PLAYER player)
{
	int i;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].player == player)
			return gameManager.players[i].nameSize;
	}

	return "";
}

void BroadcastToPlayers(EVENT event,  unsigned char eventData[], int eventSizeInBytes)
{
	int i;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].valid == 1)
		{
			PublishEvent(gameManager.players[i].id, event, eventData, eventSizeInBytes);
			printf("Broadcasting event %d to %s\n", event, PlayerEnumToString(PlayerIdToPlayer(gameManager.players[i].id)));
			wait(.15);
		}
	}
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

void PrepareBoard(char playerId, unsigned char boardData[])
{
	int i;
	int j;
	int k;
	int placeCounter = 0;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].id == playerId)
		{
			for(j = 0; j < BOARD_HEIGHT; j++)
			{
				for(k = 0; k < BOARD_WIDTH; k++)
				{
					gameManager.players[i].board.board[k][j] = boardData[placeCounter];
					placeCounter++;
				}
			}
		}
	}
}

void BasicAttackPlayer(char attackingPlayerId, char x1, char y1, char x2, char y2)
{
	int i;

	for(i = 0; i < 2; i++)
	{
		if(gameManager.players[i].id != attackingPlayerId)
			CalculateBasicDamages(&(gameManager.players[i]), x1, y1, x2, y2);
	}
}

void CheckForGameEnd()
{
	if(GetScore(gameManager.players[0].board) == 0)
	{
		SendGameOver(gameManager.players[1].id);
	}
	else if(GetScore(gameManager.players[1].board) == 0)
	{
		SendGameOver(gameManager.players[0].id);
	}
}
