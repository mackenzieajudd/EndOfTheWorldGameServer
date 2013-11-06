#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "Players.h"
#include "Events.h"
#include <stdio.h>
#include "GameManager.h"

#define COMMAND_TYPE_SIZE 1
#define REQUEST_ID_SIZE 1
#define QUIT_SIZE 0
#define READY_SIZE 0

#define All_PLAYERS_FOUND 1
#define ALL_PLAYERS_TAKEN 2

typedef enum
{
	REQUEST_ID,
	QUIT,
	READY
}COMMAND;

void HandleRequestId(unsigned char commandData[]);
void HandleQuit(PLAYER player);
void HandleReady(PLAYER player);

#endif
