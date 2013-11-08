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
	PLAYER_REGISTRED,
	ALL_PLAYERS_FOUND,
	ALL_PLAYERS_READY,
	GAME_OVER,
	PLAYER_READY,
	GAME_START
}EVENT;

void SendPlayerRegistered(char playerId);
void SendAllPlayersFound(char playerId);
void SendGameOver(char playerId);
void SendPlayerReady(char playerId);
void SendGameStart(char playerId);
void SendAllPlayersReady(char playerId);

#endif
