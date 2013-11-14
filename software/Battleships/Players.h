#ifndef PLAYERS_H_
#define PLAYERS_H_

typedef enum
{
	NONE = 65,
	PLAYER_1,
	PLAYER_2
}PLAYER;


int GetNewPlayer(PLAYER* player);

const char*  PlayerEnumToString(PLAYER player);

#endif
