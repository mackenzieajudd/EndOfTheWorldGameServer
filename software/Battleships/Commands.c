#include "Commands.h"

void HandleRequestId(char newPlayerId)
{
	PLAYER newPlayer;

	printf("Handling REQUEST_ID command\n");

	//Request a new PLAYER
	int requestNewPlayerResult = GetNewPlayer(&newPlayer);

	if(requestNewPlayerResult != ALL_PLAYERS_TAKEN)
	{
		AddNewPlayer(newPlayer, newPlayerId);
		SendPlayerRegistered(newPlayerId);
		if(requestNewPlayerResult == All_PLAYERS_FOUND)
			SendAllPlayersFound(newPlayerId);
	}
	else
		printf("A new PLAYER was requested but none are available\n");
}

void HandleQuit(char playerId)
{
	printf("Handling QUIT command from %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
	SendGameOver(playerId);
}

void HandleReady(char playerId)
{
	printf("Handling READY command from %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
	SetPlayerReady(playerId);
	SendPlayerReady(playerId);
	if(ArePlayersReady() == 1) //All Players Ready
		SendAllPlayersReady(playerId);
}

void HandlePlaceHouse(char playerId, unsigned char commandData[])
{
	printf("Handling PLACE_HOUSE command from %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	struct House newHouse = GetInitialisedHouse();

	newHouse.id = commandData[0];
	newHouse.x1 = commandData[1];
	newHouse.y1 = commandData[2];
	newHouse.x2 = commandData[3];
	newHouse.y2 = commandData[4];

	AddHouse(playerId, newHouse);
}

void HandlePlayerAttack(char playerId, unsigned char commandData[])
{
	ATTACK attack = (ATTACK)commandData[0];
	int attackDataLength = strlen((const char*)commandData) - 1;
	int i;
	unsigned char attackData[attackDataLength];

	for(i = 0; i < attackDataLength; i++)
		attackData[i] = commandData[i + 1];

	switch(attack)
	{
		case BASIC_ATTACK:
			HandleBasicAttack(playerId, attackData);
			break;
		default:
			printf("Unrecognised attack %d from %s\n", attack, PlayerEnumToString(PlayerIdToPlayer(playerId)));
			break;
	}
}

void HandleMessage(char playerId, unsigned char commandData[])
{

}
