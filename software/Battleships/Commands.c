#include "Commands.h"

void HandleRequestId(unsigned char commandData[])
{
	PLAYER newPlayer;

	printf("Handling REQUEST_ID command\n");

	//Request a new PLAYER
	int requestNewPlayerResult = GetNewPlayer(&newPlayer);

	if(requestNewPlayerResult != ALL_PLAYERS_TAKEN)
	{
		AddNewPlayer(newPlayer);
		SendDistributeId(newPlayer, commandData);
		if(requestNewPlayerResult == All_PLAYERS_FOUND)
			SendAllPlayersFound(newPlayer);
	}
	else
		printf("A new PLAYER was requested but none are available\n");
}

void HandleQuit(PLAYER player)
{
	printf("Handling QUIT command from %s\n", PlayerEnumToString(player));
	SendGameOver(player);
}

void HandleReady(PLAYER player)
{
	printf("Handling READY command from %s\n", PlayerEnumToString(player));
	SetPlayerReady(player);
	SendPlayerReady(player);
	if(ArePlayersReady() == 1) //All Players Ready
		SendAllPlayersReady(player);
}
