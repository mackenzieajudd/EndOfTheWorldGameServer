#include "Players.h"

int PLAYER_1_AVAILABLE = 1;
int PLAYER_2_AVAILABLE = 1;

int GetNewPlayer(PLAYER* player)
{
	if(PLAYER_1_AVAILABLE == 1)
	{
		*player = PLAYER_1;
		PLAYER_1_AVAILABLE--;
		return 0;
	}
	else if(PLAYER_2_AVAILABLE == 1)
	{
		*player = PLAYER_2;
		PLAYER_2_AVAILABLE--;
		return 0;
	}
	return 1;
}

const char*  PlayerEnumToString(PLAYER player)
{
	switch(player)
	{
		case PLAYER_1:
			return "PLAYER_1";
			break;
		case PLAYER_2:
				return "PLAYER_2";
				break;
	}

	return("That player hasn't been implemented in this function yet.");
}
