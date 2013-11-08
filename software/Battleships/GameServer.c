#include <stdio.h>
#include "HAL/inc/sys/alt_timestamp.h"
#include "Communications.h"
#include "VGA.h"
#include "GameManager.h"

void wait(float seconds)
{
	alt_timestamp_start();
	while((float)(alt_timestamp())/(float)(alt_timestamp_freq()) < seconds);
}

int main()
{
	InitialiseCommunications();
	//InitialiseVGA();
	InitialiseGame();

	//For Testing with DE2 loop back
	//Don't actually use PublishEvent like this
	//These are actually commands
	//-----------------------------------------
	PublishEvent('A', REQUEST_ID, "N");
	PublishEvent('B', REQUEST_ID, "N");
	PublishEvent('C', REQUEST_ID, "N");
	PublishEvent('A', READY, "N");
	PublishEvent('B', READY, "N");
	PublishEvent('A', QUIT, "N");
	//-----------------------------------------

	while(1 == 1)
	{
		CheckForCommand();
		wait(.1);
	}

	return 0;
}
