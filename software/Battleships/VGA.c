#include "VGA.h"

const int PIXEL_BUFFER_BASE = 0x00080000;
const int BACK_PIXEL_BUFFER_BASE = 0x000C0000;
alt_up_pixel_buffer_dma_dev* pixel_buffer;
alt_up_char_buffer_dev* char_buffer;
int bufferFlag = 0;

void InitialiseVGA()
{
	pixel_buffer = alt_up_pixel_buffer_dma_open_dev(VIDEO_PIXEL_BUFFER_DMA_0_NAME);
	alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer, BACK_PIXEL_BUFFER_BASE);
	char_buffer = alt_up_char_buffer_open_dev("/dev/video_character_buffer_with_dma_0");
	alt_up_char_buffer_init(char_buffer);
	alt_up_char_buffer_clear(char_buffer);

	DrawStartScreen();
}

void BlackOutScreen()
{
	int i;

	for(i = 0; i < 320; i++)
	{
		alt_up_pixel_buffer_dma_draw_vline(pixel_buffer, i, 0, 239, 0x0000, 1);
	}
}

void DrawStartScreen()
{
	BlackOutScreen();
	SwapBuffers();

	alt_up_char_buffer_clear(char_buffer);
	alt_up_char_buffer_string(char_buffer, "T h e  E n d  O f  T h e  W o r l d", 23, 15);
	alt_up_char_buffer_string(char_buffer, "Waiting for players...", 28, 40);
}

void WritePlayerJoined(PLAYER player)
{
	char p1Message[30];
	char p2Message[30];

	int i;


	int playerOneNameLength = PlayerToPlayerNameLength(PLAYER_1);
	int playerTwoNameLength = PlayerToPlayerNameLength(PLAYER_2);

	char* playerNameRaw1 = PlayerToPlayerName(PLAYER_1);
	char* playerNameRaw2 = PlayerToPlayerName(PLAYER_2);

	char playerName1[playerOneNameLength];
	char playerName2[playerTwoNameLength];

	printf("%d", playerOneNameLength);


	for(i = 0; i < playerOneNameLength; i++)
	{
		playerName1[i] = playerNameRaw1[i];
	}

	/*
	for(i = 0; i < playerTwoNameLength; i++)
	{
		playerName2[i] = playerNameRaw2[i];
	}
	*/


	sprintf(p1Message, "%s has joined", PlayerEnumToString(PLAYER_1));
	sprintf(p2Message, "%s has joined", PlayerEnumToString(PLAYER_2));

	if(player == PLAYER_1)
	{
		alt_up_char_buffer_string(char_buffer, p1Message, 29, 46);
	}
	else if(player == PLAYER_2)
	{
		alt_up_char_buffer_string(char_buffer, p2Message, 29, 49);
	}
}

void WritePlayerReady(PLAYER player)
{
	int i;

	char p1Message[30];
	char p2Message[30];

	/*
	int playerOneNameLength = PlayerToPlayerNameLength(PLAYER_1);
	int playerTwoNameLength = PlayerToPlayerNameLength(PLAYER_2);

	char* playerNameRaw1 = PlayerToPlayerName(PLAYER_1);
	char* playerNameRaw2 = PlayerToPlayerName(PLAYER_2);

	char playerName1[playerOneNameLength];
	char playerName2[playerTwoNameLength];

	for(i = 0; i < playerOneNameLength; i++)
	{
		playerName1[i] = playerNameRaw1[i];
	}

	for(i = 0; i < playerTwoNameLength; i++)
	{
		playerName2[i] = playerNameRaw2[i];
	}
	*/

	sprintf(p1Message, "%s is ready!", PlayerEnumToString(PLAYER_1));
	sprintf(p2Message, "%s is ready!", PlayerEnumToString(PLAYER_2));

	if(player == PLAYER_1)
	{
		alt_up_char_buffer_string(char_buffer, p1Message, 29, 46);
	}
	else if(player == PLAYER_2)
	{
		alt_up_char_buffer_string(char_buffer, p2Message, 29, 49);
	}
}

void DrawWaitingForReadyScreen()
{
	BlackOutScreen();
	SwapBuffers();

	alt_up_char_buffer_clear(char_buffer);
	alt_up_char_buffer_string(char_buffer, "A l l  P l a y e r s  F o u n d", 23, 15);
	alt_up_char_buffer_string(char_buffer, "Waiting for players to place houses...", 21, 30);
	alt_up_char_buffer_string(char_buffer, "Press <READY> on your game device!", 22, 34);
}

void DrawGameStatsScreen()
{
	BlackOutScreen();

	WriteGameStatsText();

	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 160, 20, 160, 240, 0xFFFF, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 0, 20, 320, 20, 0xFFFF, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 70, 20, 70, 0, 0xFFFF, 1);
	alt_up_pixel_buffer_dma_draw_line(pixel_buffer, 250, 0, 250, 20, 0xFFFF, 1);

	UpdateScore();

	SwapBuffers();
}

void WriteGameStatsText()
{
	int i;

	char p1Message[30];
	char p2Message[30];

	/*
	int playerOneNameLength = PlayerToPlayerNameLength(PLAYER_1);
	int playerTwoNameLength = PlayerToPlayerNameLength(PLAYER_2);
	char* playerNameRaw1 = PlayerToPlayerName(PLAYER_1);
	char* playerNameRaw2 = PlayerToPlayerName(PLAYER_2);


	char playerName1[playerOneNameLength];
	char playerName2[playerTwoNameLength];

	for(i = 0; i < playerOneNameLength; i++)
	{
		playerName1[i] = playerNameRaw1[i];
	}

	for(i = 0; i < playerTwoNameLength; i++)
	{
		playerName2[i] = playerNameRaw2[i];
	}
	*/

	sprintf(p1Message, "%s", PlayerEnumToString(PLAYER_1));
	sprintf(p2Message, "%s", PlayerEnumToString(PLAYER_2));

	alt_up_char_buffer_clear(char_buffer);
	alt_up_char_buffer_string(char_buffer, "T h e  E n d  O f  T h e  W o r l d", 23, 2);
	alt_up_char_buffer_string(char_buffer, p1Message, 5, 2);
	alt_up_char_buffer_string(char_buffer, p2Message, 67, 2);
}

void UpdateScore()
{
	struct GameManager manager = GetGameManager();

	struct GamePlayer player1;
	struct GamePlayer player2;

	int player1RemainingHealth = 0;
	int player2RemainingHealth = 0;

	char remainingHealth1[30];
	char remainingHealth2[30];

	int i;

	for(i = 0; i < 2; i++)
	{
		if(manager.players[i].player == PLAYER_1)
		{
			player1 = manager.players[i];
		}
		else if(manager.players[i].player == PLAYER_2)
		{
			player2 = manager.players[i];
		}
	}

	player1RemainingHealth = GetScore(player1.board);
	player2RemainingHealth = GetScore(player2.board);

	sprintf(remainingHealth1, "Health: %d", player1RemainingHealth);
	sprintf(remainingHealth2, "Health: %d", player2RemainingHealth);

	WriteGameStatsText();
	alt_up_char_buffer_string(char_buffer, remainingHealth1, 15, 30);
	alt_up_char_buffer_string(char_buffer, remainingHealth2, 52, 30);
}

void DrawGameOverScreen(PLAYER player)
{
	char playerWon[30];

	/*
	int i;

	int playerNameLength = PlayerToPlayerNameLength(player);
	char* playerNameRaw = PlayerToPlayerName(player);
	char playerName[playerNameLength];

	for(i = 0; i < playerNameLength; i++)
	{
		playerName[i] = playerNameRaw[i];
	}
	*/

	BlackOutScreen();
	alt_up_char_buffer_clear(char_buffer);

	sprintf(playerWon, "%s wins!", PlayerEnumToString(player));

	alt_up_char_buffer_string(char_buffer, "G a m e  O v e r", 33, 15);
	alt_up_char_buffer_string(char_buffer, playerWon, 34, 40);

	SwapBuffers();
}

void SwapBuffers()
{
	alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);
	while(alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer));

	if(bufferFlag == 0)
	{
		alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer, BACK_PIXEL_BUFFER_BASE);
		bufferFlag = 1;
	}
	else
	{
		alt_up_pixel_buffer_dma_change_back_buffer_address(pixel_buffer, PIXEL_BUFFER_BASE);
		bufferFlag = 0;
	}
}
