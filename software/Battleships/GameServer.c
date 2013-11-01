#include <stdio.h>
#include "HAL/inc/sys/alt_timestamp.h"
#include "Communications.h"
#include "VGA.h"

int main()
{
	InitializeCommunications();
	InitializeVGA();

	//For Testing with DE2 loop back
	//Don't actually use PublishEvent like this
	//These are actually commands
	//-----------------------------------------
	PublishEvent(REQUEST_ID, PLAYER_2, "N");
	PublishEvent(REQUEST_ID, PLAYER_2, "N");
	PublishEvent(REQUEST_ID, PLAYER_2, "N");
	PublishEvent(READY, PLAYER_2, "N");
	PublishEvent(READY, PLAYER_1, "N");
	PublishEvent(QUIT, PLAYER_2, "N");
	//-----------------------------------------

	while(1 == 1)
		WaitOnCommand();

	return 0;
}
