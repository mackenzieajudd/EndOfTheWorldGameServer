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
	REQUEST_ID = 'A',
	QUIT,
	READY,
	PLACE_HOUSE,
	PLAYER_ATTACK,
	MESSAGE,
	RESET
}COMMAND;

void HandleRequestId(char newPlayerId, unsigned char commandData[], int commandSize);
void HandleQuit(char playerId);
void HandleReady(char playerId, unsigned char commandData[], int commandSize);
void HandlePlaceHouse(char playerId, unsigned char commandData[], int commandSize);
void HandleAttack(char playerId, unsigned char commandData[], int commandSize);
void HandleMessage(char playerId, unsigned char commandData[]);
void HandleReset(char playerId);

#endif
