#ifndef BOARD_H_
#define BOARD_H_

#include "House.h"

#define NUMBER_OF_HOUSES 10
#define BOARD_WIDTH 5
#define BOARD_HEIGHT 5
#define INITIALIZATION_CHARACTER '0'
#define UNOCCUPIED_SPACE 'A'
#define OCCUPIED_SPACE 'B'

struct Board
{
	int valid;

	struct House houses[NUMBER_OF_HOUSES];
	char board[BOARD_WIDTH][BOARD_HEIGHT];
};

void InitialiseBoard(struct Board* board);
struct Board GetInitialisedBoard();
void AddHouseToBoard(struct Board* board, struct House house);
int GetScore(struct Board board);

#endif
