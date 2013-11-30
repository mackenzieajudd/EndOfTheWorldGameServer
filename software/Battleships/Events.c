#include "Events.h"
#include "GameManager.h"
#include "Communications.h"

void SendPlayerRegistered(char playerId)
{
	unsigned char eventData[1];
	printf("Sending PLAYER_REGISTERED event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	eventData[0] = playerId + MESSAGE_OFFSET;
	PublishEvent(playerId, PLAYER_REGISTRED, eventData, 1);
}

void SendAllPlayersFound(char playerId)
{
	printf("Sending ALL_PLAYERS_FOUND event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	BroadcastToPlayers(ALL_PLAYERS_FOUND, NO_DATA, 0);
}

void SendAllPlayersReady(char playerId)
{
	unsigned char eventData[1];

	printf("Sending ALL_PLAYERS_READY event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	eventData[0] = playerId + MESSAGE_OFFSET;

	BroadcastToPlayers(ALL_PLAYERS_READY, eventData, 1);
}

void SendGameOver(char playerId)
{
	unsigned char eventData[1];

	printf("Sending GAME_OVER event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
	DrawGameOverScreen(PlayerIdToPlayer(playerId));

	eventData[0] = playerId + MESSAGE_OFFSET;

	BroadcastToPlayers(GAME_OVER, eventData, 1);
}

void SendPlayerReady(char playerId)
{
	unsigned char eventData[1];

	printf("Sending PLAYER_READY event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	eventData[0] = playerId + MESSAGE_OFFSET;

	BroadcastToPlayers(PLAYER_READY, eventData, 1);
}

void SendGameStart(char playerId)
{
	printf("Sending GAME_START event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));

	BroadcastToPlayers(GAME_START, NO_DATA, 0);
}

void SendAttackResult(char playerId, unsigned char eventData[])
{
	printf("Sending ATTACK_RESULT event triggered by %s with result %d on location %d %d\n", PlayerEnumToString(PlayerIdToPlayer(playerId)), eventData[1], eventData[2], eventData[3]);

	BroadcastToPlayers(ATTACK_RESULT, eventData, 4);
}

void SendTurnOver(char playerId)
{
	unsigned char eventData[1];

	printf("Sending TURN_OVER event triggered by %s\n", PlayerEnumToString(PlayerIdToPlayer(playerId)));
	eventData[0] = playerId + MESSAGE_OFFSET;
	BroadcastToPlayers(TURN_OVER, eventData, 1);
}
