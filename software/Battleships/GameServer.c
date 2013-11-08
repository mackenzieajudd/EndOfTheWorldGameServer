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
	unsigned char mockHouse[5];
	mockHouse[0] = 'A';
	mockHouse[1] = 0;
	mockHouse[2] = 0;
	mockHouse[3] = 40;
	mockHouse[4] = 40;
	PublishEvent('A', PLACE_HOUSE, mockHouse);
	unsigned char mockAttack[5];
	mockAttack[0] = BASIC_ATTACK;
	mockAttack[1] = 20;
	mockAttack[2] = 20;
	mockAttack[3] = 40;
	mockAttack[4] = 40;
	PublishEvent('B', PLAYER_ATTACK, mockAttack);
	PublishEvent('A', QUIT, "N");
	//-----------------------------------------

	while(1 == 1)
	{
		CheckForCommand();
		wait(.1);
	}

	return 0;
}
