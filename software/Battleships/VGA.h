#ifndef VGA_H_
#define VGA_H_

#include "drivers/inc/altera_up_avalon_video_pixel_buffer_dma.h"
#include "drivers/inc/altera_up_avalon_video_character_buffer_with_dma.h"

void InitialiseVGA();
void SwapBuffers();

#endif
