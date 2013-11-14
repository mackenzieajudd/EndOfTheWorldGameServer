#include <stdio.h>
#include "Communications.h"
#include "VGA.h"
#include "GameManager.h"


void DummyTests()
{
	//For Testing with DE2 loop back
	//Don't actually use PublishEvent like this
	//These are actually commands
	//-----------------------------------------
	PublishEvent('A', REQUEST_ID, "N");
	PublishEvent('B', REQUEST_ID, "N");
	PublishEvent('C', REQUEST_ID, "N");
	PublishEvent('A', READY, "NNNNNNNNNNNNNNNNNNNNNNNNN");
	PublishEvent('B', READY, "NNNNNNNNNNNNNNNNNNNNNNNNN");
	unsigned char mockHouse[5];
	mockHouse[0] = 'A';
	mockHouse[1] = 20;
	mockHouse[2] = 20;
	mockHouse[3] = 22;
	mockHouse[4] = 22;
	PublishEvent('A', PLACE_HOUSE, mockHouse);
	mockHouse[0] = 'B';
	mockHouse[1] = 28;
	mockHouse[2] = 28;
	mockHouse[3] = 30;
	mockHouse[4] = 30;
	PublishEvent('A', PLACE_HOUSE, mockHouse);
	mockHouse[0] = 'C';
	mockHouse[1] = 31;
	mockHouse[2] = 31;
	mockHouse[3] = 31;
	mockHouse[4] = 31;
	PublishEvent('A', PLACE_HOUSE, mockHouse);
	unsigned char mockAttack[5];
	mockAttack[0] = BASIC_ATTACK;
	mockAttack[1] = 20;
	mockAttack[2] = 20;
	mockAttack[3] = 30;
	mockAttack[4] = 30;
	PublishEvent('B', PLAYER_ATTACK, mockAttack);
	mockAttack[1] = 31;
	mockAttack[2] = 31;
	mockAttack[3] = 31;
	mockAttack[4] = 31;
	PublishEvent('B', PLAYER_ATTACK, mockAttack);
	PublishEvent('A', QUIT, "N");
	//-----------------------------------------
}
