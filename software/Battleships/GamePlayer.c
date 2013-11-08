#include "GamePlayer.h"

void InitialiseGamePlayer(struct GamePlayer* gamePlayer)
{
	(*gamePlayer).valid = 0;

	(*gamePlayer).ready = 0;
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

struct GamePlayer GetNewGamePlayer(PLAYER newPlayer, char newPlayerId)
{
	struct GamePlayer newGamePlayer = GetInitialisedGamePlayer();

	newGamePlayer.valid = 1;
	newGamePlayer.player = newPlayer;
	newGamePlayer.id = newPlayerId;

	return newGamePlayer;
}

int IsPlayerReady(struct GamePlayer gamePlayer)
{
	return gamePlayer.ready;
}
