#include "Events.h"
#include "GameManager.h"
#include "Communications.h"

void SendPlayerRegistered(char playerId)
{
	unsigned char eventData[1];
	printf("Sending PLAYER_REGISTERED event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	eventData[0] = playerId;
	//PublishEvent(playerId, PLAYER_REGISTRED, eventData);
}

void SendAllPlayersFound(char playerId)
{
	printf("Sending ALL_PLAYERS_FOUND event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	//BroadcastToPlayers(ALL_PLAYERS_FOUND, "");
}

void SendAllPlayersReady(char playerId)
{
	printf("Sending ALL_PLAYERS_READY event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	//BroadcastToPlayers(ALL_PLAYERS_READY, "");
}

void SendGameOver(char playerId)
{
	printf("Sending GAME_OVER event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
	DrawGameOverScreen(PlayerIdToPlayer(playerId));
	//BroadcastToPlayers(GAME_OVER, "");
}

void SendPlayerReady(char playerId)
{
	unsigned char eventData[1];

	printf("Sending PLAYER_READY event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	eventData[0] = playerId;
	//BroadcastToPlayers(PLAYER_READY, eventData);
}

void SendGameStart(char playerId)
{
	printf("Sending GAME_START event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	//BroadcastToPlayers(GAME_START, "");
}

void SendAttackResult(char playerId, unsigned char eventData[])
{
	printf("Sending ATTACK_RESULT event triggered by %s with result %d on location %d %d\n", PlayerEnumToString(PlayerIdToPlayer(playerId)), eventData[1], eventData[2], eventData[3]);

	//BroadcastToPlayers(ATTACK_RESULT, eventData);
}

void SendTurnOver(char playerId)
{
	unsigned char eventData[1];

	printf("Sending TURN_OVER event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
	eventData[0] = playerId;
	//BroadcastToPlayers(TURN_OVER, eventData);
}
