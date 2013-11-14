#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "Players.h"
#include "Events.h"
#include <stdio.h>
#include "GameManager.h"
#include "Attack.h"
#include "VGA.h"

#define COMMAND_TYPE_SIZE 1
#define REQUEST_ID_SIZE 1
#define QUIT_SIZE 0
#define READY_SIZE 0

#define All_PLAYERS_FOUND 1
#define ALL_PLAYERS_TAKEN 2

typedef enum
{
	REQUEST_ID = 65,
	QUIT,
	READY,
	PLACE_HOUSE,
	PLAYER_ATTACK,
	MESSAGE
}COMMAND;

void HandleRequestId(char newPlayerId);
void HandleQuit(char playerId);
void HandleReady(char playerId, unsigned char commandData[]);
void HandlePlaceHouse(char playerId, unsigned char commandData[]);
void HandleAttack(char playerId, unsigned char commandData[]);
void HandleMessage(char playerId, unsigned char commandData[]);

#endif
