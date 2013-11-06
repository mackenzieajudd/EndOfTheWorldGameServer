#ifndef PLAYERS_H_
#define PLAYERS_H_

#define PLAYER_ID_SIZE 1

typedef enum
{
	NONE,
	PLAYER_1,
	PLAYER_2
}PLAYER;


int GetNewPlayer(PLAYER* player);

const char*  PlayerEnumToString(PLAYER player);

#endif
