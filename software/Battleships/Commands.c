#include "Commands.h"
#include "GameManager.h"

void HandleRequestId(char newPlayerId, unsigned char commandData[], int commandSize)
{
	PLAYER newPlayer;
	int i;

	printf("Handling REQUEST_ID command\n");

	//Allocate Memory for Command
	char* name = malloc(commandSize);

	for(i = 0; i < commandSize; i++)
	{
		name[i] = commandData[i];
	}

	//Request a new PLAYER
	int requestNewPlayerResult = GetNewPlayer(&newPlayer);

	if(requestNewPlayerResult != ALL_PLAYERS_TAKEN)
	{
		AddNewPlayer(newPlayer, newPlayerId, name, commandSize);
		SendPlayerRegistered(newPlayerId);
		WritePlayerJoined(newPlayer);
		if(requestNewPlayerResult == All_PLAYERS_FOUND)
		{
			DrawWaitingForReadyScreen();
			SendAllPlayersFound(newPlayerId);
		}
	}
	else
		printf("A new PLAYER was requested but none are available\n");
}

void HandleQuit(char playerId)
{
	printf("Handling QUIT command from %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
	SendGameOver(playerId);
}

void HandleReady(char playerId, unsigned char commandData[], int commandSize)
{
	printf("Handling READY command from %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
	SetPlayerReady(playerId);

	PrepareBoard(playerId, commandData);

	WritePlayerReady(PlayerIdToPlayer(playerId));

	SendPlayerReady(playerId);
	if(ArePlayersReady() == 1) //All Players Ready
	{
		DrawGameStatsScreen();
		SendAllPlayersReady(playerId);
	}
}

void HandlePlaceHouse(char playerId, unsigned char commandData[], int commandSize)
{
	printf("Handling PLACE_HOUSE command from %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	struct House newHouse = GetInitialisedHouse();

	newHouse.valid = 1;
	newHouse.id = commandData[0];
	newHouse.x1 = commandData[1];
	newHouse.y1 = commandData[2];
	newHouse.x2 = commandData[3];
	newHouse.y2 = commandData[4];

	printf("House %d positioned at %d %d %d %d\n", newHouse.id, newHouse.x1, newHouse.y1, newHouse.x2, newHouse.y2);

	AddHouse(playerId, newHouse);
}

void HandleAttack(char playerId, unsigned char commandData[], int commandSize)
{
	ATTACK attack = (ATTACK)commandData[0];
	int attackDataLength = commandSize - 1;
	int i;
	unsigned char attackData[attackDataLength];

	for(i = 0; i < attackDataLength; i++)
		attackData[i] = commandData[i + 1];

	switch(attack)
	{
		case BASIC_ATTACK:
			HandleBasicAttack(playerId, attackData);
			break;
		case SCATTER_ATTACK:
			HandleScatterAttack(playerId, attackData);
			break;
		default:
			printf("Unrecognised attack %d from %s\n", attack, PlayerEnumToString(PlayerIdToPlayer(playerId)));
			break;
	}

	UpdateScore();
	CheckForGameEnd();
	SendTurnOver(playerId);
}

void HandleMessage(char playerId, unsigned char commandData[])
{

}

void HandleReset(char playerId)
{
	InitialiseGame();
}
