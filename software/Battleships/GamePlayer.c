#include "GamePlayer.h"

void InitialiseGamePlayer(struct GamePlayer* gamePlayer)
{
	(*gamePlayer).valid = 0;

	(*gamePlayer).ready = 0;
	(*gamePlayer).name = 0;
	(*gamePlayer).nameSize = 0;
	(*gamePlayer).player = NONE;
	(*gamePlayer).id = '0';
	(*gamePlayer).board = GetInitialisedBoard();
}

struct GamePlayer GetInitialisedGamePlayer()
{
	struct GamePlayer gamePlayer;

	InitialiseGamePlayer(&gamePlayer);

	return gamePlayer;
}

struct GamePlayer GetNewGamePlayer(PLAYER newPlayer, char newPlayerId, char* playerName, int nameSize)
{
	struct GamePlayer newGamePlayer = GetInitialisedGamePlayer();

	newGamePlayer.valid = 1;
	newGamePlayer.player = newPlayer;
	newGamePlayer.id = newPlayerId;

	newGamePlayer.name = playerName;
	newGamePlayer.nameSize = nameSize;


	return newGamePlayer;
}

int IsPlayerReady(struct GamePlayer gamePlayer)
{
	return gamePlayer.ready;
}
