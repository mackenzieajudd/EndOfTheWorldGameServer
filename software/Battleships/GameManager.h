#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "GamePlayer.h"
#include "Events.h"
#include <stdio.h>
#include "HAL/inc/sys/alt_timestamp.h"

#define NUMBER_OF_PLAYERS 2
#define ALL_GAME_PLAYERS_READY 1
#define ALL_PLAYERS_NOT_READY 0
#define MESSAGE_OFFSET 65

struct GameManager
{
	struct GamePlayer players[2];
};

void InitialiseGame();

void AddNewPlayer(PLAYER newPlayer, char newPlayerId, char* playerName, int nameSize);

struct GameManager GetGameManager();

void SetPlayerReady(char playerId);
int ArePlayersReady();

PLAYER PlayerIdToPlayer(char playerId);
char* PlayerToPlayerName(PLAYER player);
int PlayerToPlayerNameLength(PLAYER player);

void AddHouse(char playerId, struct House house);

void BroadcastToPlayers(EVENT event,  unsigned char eventData[], int eventSizeInBytes);

void wait(float seconds);

void CheckForGameEnd();

void BasicAttackPlayer(char attackingPlayerId, char x1, char y1, char x2, char y2);

#endif
