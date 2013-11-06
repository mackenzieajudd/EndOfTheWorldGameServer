#include <stdio.h>
#include "HAL/inc/sys/alt_timestamp.h"
#include "Communications.h"
#include "VGA.h"
#include "GameManager.h"

int main()
{
	InitialiseCommunications();
	//InitialiseVGA();
	InitialiseGame();

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
	{
		CheckForCommand();
		printf("1:%s\n", PlayerEnumToString(GetGameManager().players[0].player));
		printf("2:%s\n", PlayerEnumToString(GetGameManager().players[1].player));
	}

	return 0;
}
