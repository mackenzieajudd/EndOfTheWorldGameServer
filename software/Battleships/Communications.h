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

void PublishEvent(EVENT event, PLAYER player, unsigned char eventData[]);

void CheckForCommand();
void ReceiveCommand();
void HandleCommand(COMMAND command, PLAYER player, unsigned char commandData[]);

#endif
