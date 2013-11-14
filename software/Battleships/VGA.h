#ifndef VGA_H_
#define VGA_H_

#include "drivers/inc/altera_up_avalon_video_pixel_buffer_dma.h"
#include "drivers/inc/altera_up_avalon_video_character_buffer_with_dma.h"
#include "Players.h"
#include "GameManager.h"

void InitialiseVGA();
void SwapBuffers();
void BlackOutScreen();
void DrawStartScreen();
void DrawWaitingForReadyScreen();
void DrawGameStatsScreen();
void WritePlayerJoined(PLAYER player);
void WritePlayerReady(PLAYER player);
void UpdateScore();
void WriteGameStatsText();

#endif
