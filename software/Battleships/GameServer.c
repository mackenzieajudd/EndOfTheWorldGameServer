#include <stdio.h>
#include "Communications.h"
#include "VGA.h"
#include "GameManager.h"

int main()
{
	InitialiseCommunications();
	InitialiseVGA();
	InitialiseGame();

	wait(3);

	//Testing
	//For Testing with DE2 loop back
	//Don't actually use PublishEvent like this
	//These are actually commands
	//-----------------------------------------

	PublishEvent('A', REQUEST_ID, "N");
	wait(3);
	CheckForCommand();
	PublishEvent('B', REQUEST_ID, "N");
	wait(3);
	CheckForCommand();
	PublishEvent('B', READY, "BBBBBBBBBBAAAAAAAAAAAAAAA");
	wait(3);
	CheckForCommand();
	PublishEvent('A', READY, "AAAAAAAAAAAAAAABBBBBAAAAA");
	wait(3);
	CheckForCommand();
	unsigned char mockAttack[5];
	mockAttack[0] = BASIC_ATTACK;
	mockAttack[1] = 65;
	mockAttack[2] = 65;
	mockAttack[3] = 65;
	mockAttack[4] = 65;
	PublishEvent('A', PLAYER_ATTACK, mockAttack);
	wait(3);
	CheckForCommand();
	mockAttack[1] = 65;
	mockAttack[2] = 68;
	mockAttack[3] = 66;
	mockAttack[4] = 68;
	PublishEvent('B', PLAYER_ATTACK, mockAttack);
	wait(3);
	CheckForCommand();
	mockAttack[1] = 66;
	mockAttack[2] = 65;
	mockAttack[3] = 69;
	mockAttack[4] = 65;
	PublishEvent('A', PLAYER_ATTACK, mockAttack);
	wait(3);
	CheckForCommand();
	mockAttack[1] = 67;
	mockAttack[2] = 68;
	mockAttack[3] = 68;
	mockAttack[4] = 68;
	PublishEvent('B', PLAYER_ATTACK, mockAttack);
	wait(3);
	CheckForCommand();
	mockAttack[1] = 65;
	mockAttack[2] = 66;
	mockAttack[3] = 68;
	mockAttack[4] = 66;
	PublishEvent('A', PLAYER_ATTACK, mockAttack);
	wait(3);
	CheckForCommand();
	mockAttack[1] = 69;
	mockAttack[2] = 68;
	mockAttack[3] = 69;
	mockAttack[4] = 68;
	PublishEvent('B', PLAYER_ATTACK, mockAttack);
	wait(3);
	CheckForCommand();


	while(1 == 1)
	{
		CheckForCommand();
		wait(.1);
	}

	return 0;
}
