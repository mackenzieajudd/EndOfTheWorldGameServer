#include "Commands.h"

void HandleRequestId(unsigned char commandData[])
{
	PLAYER newPlayer;

	printf("Handling REQUEST_ID command\n");

	//Request a new PLAYER
	if(GetNewPlayer(&newPlayer) == 0)
		SendDistributeId(newPlayer, commandData);
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
	SendPlayerReady(player);
}
