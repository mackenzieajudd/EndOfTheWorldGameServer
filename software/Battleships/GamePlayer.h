#ifndef GAMEPLAYER_H_
#define GAMEPLAYER_H_

#include "Board.h"
#include "Players.h"

#define PLAYER_IS_READY 1

struct GamePlayer
{
	int valid;

	int ready;

	struct Board board;
	PLAYER player;
	char id;
};

void InitialiseGamePlayer(struct GamePlayer* gameplayer);
struct GamePlayer GetInitialisedGamePlayer();
struct GamePlayer GetNewGamePlayer(PLAYER newPlayer, char newPlayerId);
int IsPlayerReady(struct GamePlayer gamePlayer);

#endif
