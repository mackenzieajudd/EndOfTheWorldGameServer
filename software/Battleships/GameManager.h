#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "GamePlayer.h"
#include <stdio.h>

#define NUMBER_OF_PLAYERS 2;
#define ALL_PLAYERS_READY 1;
#define ALL_PLAYERS_NOT_READY 0;

struct GameManager
{
	struct GamePlayer players[2];
};

void InitialiseGame();
void AddNewPlayer(PLAYER newPlayer);
struct GameManager GetGameManager();
void SetPlayerReady(PLAYER player);
int ArePlayersReady();

#endif
