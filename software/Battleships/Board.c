#include"Board.h"

void InitialiseBoard(struct Board* board)
{
	int i;
	int j;

	(*board).valid = 0;

	for(i = 0; i < BOARD_WIDTH; i++)
	{
		for(j = 0; j < BOARD_HEIGHT; j++)
		{
			(*board).board[i][j] = INITIALIZATION_CHARACTER;
		}
	}

	for(i = 0; i < NUMBER_OF_HOUSES; i++)
	{
		(*board).houses[i] = GetInitialisedHouse();
	}
}

struct Board GetInitialisedBoard()
{
	struct Board board;

	InitialiseBoard(&board);

	return board;
}

void AddHouseToBoard(struct Board* board, struct House house)
{
	int i;

	for(i = 0; i < NUMBER_OF_HOUSES; i++)
	{
		if((*board).houses[i].valid == 0)
		{
			(*board).houses[i] = house;
			break;
		}
	}
}
