/*********************************************************************************************************
 *
 *   Hasan Eren Keskin
 *   Electrical and Electronics Engineer
 *   email:      herenkeskin@gmail.com
 *   github:     @erenkeskin95
 *   website:    http://herenkeskin.com
 *
 *   Ring Buffer (Circular Buffer) basic remix version for any users.
 *   Version 1.0 - 08.08.2018
 *
 ********************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "RingBuffer.h"

static RingBuffer_Struct txRbuff;
static RingBuffer_Struct rxRbuff;

static uint8_t txRbuff_data[255];
static uint8_t rxRbuff_data[255];

int main(void)
{ 

	uint8_t i = 0;
	uint8_t data[255] = "Hasan Eren Keskin";
	uint8_t * return_to_buffer;

	RingBuffer_InitBuffer(&rxRbuff, rxRbuff_data, sizeof(rxRbuff_data));

	printf("Initialized Buffer Data Count: %d\n", RingBuffer_GetCount(&rxRbuff));

	for(i = 0; i < strlen(data); i++)
	{
		if(!RingBuffer_IsFull(&rxRbuff))
		{
		    RingBuffer_Insert(&rxRbuff, data[i]);
		}
	}

	printf("Inserting Data Count: %d\n", RingBuffer_GetCount(&rxRbuff));

	return 0;

}
