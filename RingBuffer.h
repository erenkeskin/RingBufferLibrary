/*********************************************************************************************************
 *
 * See the http://www.fourwalledcubicle.com/files/LightweightRingBuff.h for the license information.
 * Thank you for the guidance İhsan Kehribar - https://github.com/kehribar
 *
 ********************************************************************************************************/

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
#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stdint.h>

/* Defines: */
/** Size of each ring buffer, in data elements - must be between 1 and 255. */
#define BUFFER_SIZE            		255

/* Type Defines: */
/** Type define for a new ring buffer object. Buffers should be initialized via a call to
 *  \ref RingBuffer_InitBuffer() before use.
 */
typedef struct
{
	uint8_t * In; 					// Current storage location in the circular buffer.
	uint8_t * Out; 					// Current retrieval location in the circular buffer.
	uint8_t * Start; 				// Pointer to the start of the buffer's underlying storage array.
	uint8_t * End; 					// Pointer to the end of the buffer's underlying storage array.
	uint16_t Size; 					// Size of the buffer's underlying storage array.
	uint16_t Count; 				// Number of bytes currently stored in the buffer.
} RingBuffer_Struct ;

/* Function Parameters */
void 		RingBuffer_InitBuffer	(RingBuffer_Struct * Buffer, uint8_t * const DataPtr, const uint16_t Size);
uint16_t 	RingBuffer_GetCount 	(RingBuffer_Struct * const Buffer);
uint16_t 	RingBuffer_GetFreeCount (RingBuffer_Struct * const Buffer);
uint8_t 	RingBuffer_IsEmpty		(RingBuffer_Struct * const Buffer);
uint8_t 	RingBuffer_IsFull		(RingBuffer_Struct * const Buffer);
void 		RingBuffer_Insert		(RingBuffer_Struct * Buffer, const uint8_t Data);
uint8_t 	RingBuffer_Remove		(RingBuffer_Struct * Buffer);
uint8_t 	RingBuffer_Peek			(RingBuffer_Struct * const Buffer);

#endif /* RINGBUFFER_H */