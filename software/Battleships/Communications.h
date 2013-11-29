#ifndef COMMUNICATIONS_H_
#define COMMUNICATIONS_H_

#include "altera_up_avalon_rs232.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Commands.h"
#include "Events.h"
#include "Players.h"

void InitialiseCommunications();

void PublishEvent(char playerId, EVENT event, unsigned char eventData[], int numBytesInEvent);

void CheckForCommand();
void ReceiveCommand();
void HandleCommand(char playerId, COMMAND command,  unsigned char commandData[], int commandSize);

#endif
