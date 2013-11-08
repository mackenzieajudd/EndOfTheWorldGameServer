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
