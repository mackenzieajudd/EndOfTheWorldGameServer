#ifndef EVENTS_H_
#define EVENTS_H_

#include "Players.h"
#include <stdio.h>

#define EVENT_TYPE_SIZE 1
#define DISTRIBUTE_ID_SIZE 2
#define GAME_OVER_SIZE 0
#define PLAYER_READY_SIZE 0
#define GAME_START_SIZE 0

typedef enum
{
	DISTRIBUTE_ID,
	ALL_PLAYERS_FOUND,
	ALL_PLAYERS_READY,
	GAME_OVER,
	PLAYER_READY,
	GAME_START
}EVENT;

void SendDistributeId(PLAYER player, unsigned char eventData[]);
void SendAllPlayersFound(PLAYER player);
void SendGameOver(PLAYER player);
void SendPlayerReady(PLAYER player);
void SendGameStart(PLAYER player);
void SendAllPlayersReady(PLAYER player);

#endif
