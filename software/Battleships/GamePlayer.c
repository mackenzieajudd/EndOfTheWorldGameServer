#include "GamePlayer.h"

void InitialiseGamePlayer(struct GamePlayer* gamePlayer)
{
	(*gamePlayer).valid = 0;

	(*gamePlayer).ready = 0;
	(*gamePlayer).player = NONE;
	(*gamePlayer).board = GetInitialisedBoard();
}

struct GamePlayer GetInitialisedGamePlayer()
{
	struct GamePlayer gamePlayer;

	InitialiseGamePlayer(&gamePlayer);

	return gamePlayer;
}

struct GamePlayer GetNewGamePlayer(PLAYER newPlayer)
{
	struct GamePlayer newGamePlayer = GetInitialisedGamePlayer();

	newGamePlayer.valid = 1;
	newGamePlayer.player = newPlayer;

	return newGamePlayer;
}

int IsPlayerReady(struct GamePlayer gamePlayer)
{
	return gamePlayer.ready;
}
