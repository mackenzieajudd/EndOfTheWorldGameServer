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

	char_buffer = alt_up_char_buffer_open_dev(VIDEO_CHARACTER_BUFFER_WITH_DMA_0_AVALON_CHAR_BUFFER_SLAVE_NAME);
	alt_up_char_buffer_init(char_buffer);
	alt_up_char_buffer_clear(char_buffer);
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
