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
 *   github:     @erenkeskin
 *   website:    http://herenkeskin.com
 *
 *   Ring Buffer (Circular Buffer) basic remix version for any users.
 *   Version 1.0 - 08.08.2018
 *
 ********************************************************************************************************/
#include "RingBuffer.h"

/*********************************************************************************************************
 *
 *  Initializes a ring buffer ready for use. Buffers must be initialized via this function
 *  before any operations are called upon them. Already initialized buffers may be reset
 *  by re-initializing them using this function.
 *
 ********************************************************************************************************/
void RingBuffer_InitBuffer(RingBuffer_Struct * Buffer, uint8_t * const DataPtr, const uint16_t Size)
{
    Buffer->In     = DataPtr;
    Buffer->Out    = DataPtr;
    Buffer->Start  = &DataPtr[0];
    Buffer->End    = &DataPtr[Size];
    Buffer->Size   = Size;
    Buffer->Count  = 0;
}

/*********************************************************************************************************
 *
 *  Retrieves the minimum number of bytes stored in a particular buffer.
 *
 *  \note The value returned by this function is guaranteed to only be the minimum number of bytes
 *        stored in the given buffer; this value may change as other threads write new data and so
 *        the returned number should be used only to determine how many successive reads may safely
 *        be performed on the buffer.
 *
 ********************************************************************************************************/
uint16_t RingBuffer_GetCount(RingBuffer_Struct * const Buffer)
{
    uint16_t Count;

    // Disable Interrupt
    Count = Buffer->Count;
    // Enable Interrupt

    return Count;
}

/*********************************************************************************************************
 *
 *  Retrieves the free number of bytes stored in a particular buffer.
 *
 ********************************************************************************************************/
uint16_t RingBuffer_GetFreeCount(RingBuffer_Struct * const Buffer)
{
    return (Buffer->Size - RingBuffer_GetCount(Buffer));
}

/*********************************************************************************************************
 *
 *  If the specified ring buffer contains any data. This should
 *  be tested before removing data from the buffer, to ensure that the buffer does not
 *  underflow.
 *
 *  If the data is to be removed in a loop, store the total number of bytes stored in the
 *  buffer (via a call to the \ref RingBuffer_GetCount() function) in a temporary variable
 *  to reduce the time spent in atomicity locks.
 *
 *  \return Boolean true if the buffer contains no free space, false otherwise
 *
 ********************************************************************************************************/
uint8_t RingBuffer_IsEmpty(RingBuffer_Struct * const Buffer)
{
    return (RingBuffer_GetCount(Buffer) == 0);
}

/*********************************************************************************************************
 *
 *  If the specified ring buffer contains any free space. This should
 *  be tested before storing data to the buffer, to ensure that no data is lost due to a
 *  buffer overrun.
 *
 *  \return Boolean true if the buffer contains no free space, false otherwise
 *
 ********************************************************************************************************/
uint8_t RingBuffer_IsFull(RingBuffer_Struct * const Buffer)
{
    return (RingBuffer_GetCount(Buffer) == Buffer->Size);
}

/*********************************************************************************************************
 *
 *  Inserts an element into the ring buffer.
 *
 *  \note Only one execution thread (main program thread or an ISR) may insert into a single buffer
 *        otherwise data corruption may occur. Insertion and removal may occur from different execution
 *        threads.
 *
 ********************************************************************************************************/
void RingBuffer_Insert(RingBuffer_Struct * Buffer, const uint8_t Data)
{
    *Buffer->In = Data;

    if (++Buffer->In == Buffer->End)
    {
        Buffer->In = Buffer->Start;
    }

    // Disable Interrupt
    Buffer->Count++;
    // Enable Interrupt
}

/*********************************************************************************************************
 *
 *  Removes an element from the ring buffer.
 *
 *  \note Only one execution thread (main program thread or an ISR) may remove from a single buffer
 *        otherwise data corruption may occur. Insertion and removal may occur from different execution
 *        threads.
 *
 *  \return Next data element stored in the buffer
 *
 ********************************************************************************************************/
uint8_t RingBuffer_Remove(RingBuffer_Struct * Buffer)
{
    uint8_t Data = *Buffer->Out;

    if (++Buffer->Out == Buffer->End)
    {
        Buffer->Out = Buffer->Start;
    }

    // Disable Interrupt
    Buffer->Count--;
    // Enable Interrupt

    return Data;
}

/*********************************************************************************************************
 *
 *  Peek an element from the ring buffer.
 *
 *  \return Out data element stored in the buffer
 *
 ********************************************************************************************************/
uint8_t RingBuffer_Peek(RingBuffer_Struct * const Buffer)
{
    return *Buffer->Out;
}