#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "Players.h"
#include "Events.h"
#include <stdio.h>

#define COMMAND_TYPE_SIZE 1
#define REQUEST_ID_SIZE 1
#define QUIT_SIZE 0
#define READY_SIZE 0

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
