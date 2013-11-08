#include "Events.h"
#include "GameManager.h"

void SendPlayerRegistered(char playerId)
{
	printf("Sending PLAYER_REGISTERED event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
}

void SendAllPlayersFound(char playerId)
{
	printf("Sending ALL_PLAYERS_FOUND event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
}

void SendAllPlayersReady(char playerId)
{
	printf("Sending ALL_PLAYERS_READY event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
}

void SendGameOver(char playerId)
{
	printf("Sending GAME_OVER event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
}

void SendPlayerReady(char playerId)
{
	printf("Sending PLAYER_READY event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
}

void SendGameStart(char playerId)
{
	printf("Sending GAME_START event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
}

void SendAttackResult(char playerId, unsigned char eventData[])
{
	printf("Sending ATTACK_RESULT event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
}
