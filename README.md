Ring Buffer (Circular Buffer) Library
===================

Hi, in this library, you can manage your buffer.

> **NOTE:** If you want to use this library in Embedded System Projecs, you must check these functions and change some places where interrupt settings:
> - RingBuffer_GetCount()
> - RingBuffer_Insert
> - RingBuffer_Remove

----------

Ring Buffer
-------------

Ring buffer has many names. You might have heard of a circular buffer, circular queue, or cyclic buffer. All of them mean the same thing. It is basically a linear data structure in which the end points to the beginning of the structure. It’s easy to reason about it as a circular array without the end.

As you can imagine, a ring buffer is mostly used as a queue. It has read and write positions which are used by the consumer and the producer, respectively. When the read or write index reaches the end of the underlying array, it is set back to 0. This activity is usually called “wrapping around,” and it requires a bit more explanation. ([dzone](https://stackedit.io/))

1 - [https://www.techopedia.com/definition/18301/ring-buffer](https://www.techopedia.com/definition/18301/ring-buffer)
2 - [https://en.wikipedia.org/wiki/Circular_buffer](https://en.wikipedia.org/wiki/Circular_buffer)
3 - [https://embedjournal.com/implementing-circular-buffer-embedded-c/](https://embedjournal.com/implementing-circular-buffer-embedded-c/)


Documents
-------------

> **Functions:**
> - RingBuffer_InitBuffer()
> - RingBuffer_GetCount()
> - RingBuffer_GetFreeCount()
> - RingBuffer_IsEmpty()
> - RingBuffer_IsFull()
> - RingBuffer_Insert()
> - RingBuffer_Remove()
> - RingBuffer_Peek()

Contact
-------------
Email: herenkeskin@gmail.com
Twitter: @herenkeskin
Website: http://herenkeskin.com
