#include "Events.h"

void SendDistributeId(PLAYER player, unsigned char eventData[])
{
	printf("Sending DISTRIBUTE_ID event triggered by %s\n", PlayerEnumToString(player));
}

void SendAllPlayersFound(PLAYER player)
{
	printf("Sending ALL_PLAYERS_FOUND event triggered by %s\n", PlayerEnumToString(player));
}

void SendAllPlayersReady(PLAYER player)
{
	printf("Sending ALL_PLAYERS_READY event triggered by %s\n", PlayerEnumToString(player));
}

void SendGameOver(PLAYER player)
{
	printf("Sending GAME_OVER event triggered by %s\n", PlayerEnumToString(player));
}

void SendPlayerReady(PLAYER player)
{
	printf("Sending PLAYER_READY event triggered by %s\n", PlayerEnumToString(player));
}

void SendGameStart(PLAYER player)
{
	printf("Sending GAME_START event triggered by %s\n", PlayerEnumToString(player));
}
