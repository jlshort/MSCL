/*****************************************************************************
Copyright(c) 2015 LORD Corporation. All rights reserved.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the included
LICENSE.txt file for a copy of the full GNU General Public License.
*****************************************************************************/
#pragma once

#include "ByteStream.h"
#include "mscl/Types.h"
#include <string>

namespace mscl
{
	//Title: DataBuffer
	//	Used to easily read a container of bytes

	//Class: BufferWriter
	//	Class used to interface with a DataBuffer and append data to it
	class BufferWriter
	{
	public:
		//Constructor: BufferWriter
		//	Constructor to create a BufferWriter object
		BufferWriter(uint8* buffer, std::size_t size, std::size_t* offset);

	private:
		//Variable: m_buffer
		//	The buffer to write to, at the specific position to start writing data
		uint8* m_buffer;

		//Variable: m_size
		//	The size available to write
		std::size_t m_size;

		//Variable: m_writeOffset
		//	A pointer to the current position to start writing in the buffer
		std::size_t* m_writeOffset;

	public:
		//Function: buffer
		//	Gets the buffer to write to
		//
		//Returns:
		//	The buffer to write to, as a byte reference
		uint8* buffer();

		//Function: size
		//	Gets the size of the buffer available to write
		//
		//Returns:
		//	The size of the buffer available to write
		std::size_t size();

		//Function: commit
		//	Commits a number of bytes that were added to the buffer by moving the current offset.
		//
		//	This function must be called after bytes are added to the buffer, or else they will be ignored as if they were never added.
		//
		//Parameters:
		//	numBytesAdded - The number of bytes added to the buffer
		void commit(std::size_t numBytesAdded);
	};

	//Class: DataBuffer
	//	A buffer of bytes extending from the ByteStream class that is used
	//	for holding bytes read in from the connection 
	//
	//See Also:
	//	<ByteStream>
	class DataBuffer
	{
		friend class ReadBufferSavePoint;//give ReadBufferSavePoint access to our private variables

	private:
		//Variable: m_data
		//	The underlying ByteStream that holds the data
		ByteStream m_data;

		//Variable: m_appendPosition
		//	The current position to use when appending data to the buffer
		std::size_t m_appendPosition;

		//Variable: m_readPosition
		//	The current position in the buffer for reading data
		std::size_t m_readPosition;

	private:
		DataBuffer();//	Disabled default constructor

	public:
		//Constructor: DataBuffer 
		//	Constructor to create a DataBuffer object
		//
		//Parameters:
		//	size - The start and final size of the DataBuffer
		explicit DataBuffer(uint32 size);

		//Constructor: DataBuffer
		//	Constructor to create a DataBuffer object given existing data as <Bytes>
		//
		//Parameters:
		//	data - a <Bytes> array containing existing data
		explicit DataBuffer(const Bytes& data);

		//Constructor: DataBuffer
		//	Constructor to create a DataBuffer given an existing <ByteStream>
		//
		//Parameters:
		//	data - a <ByteStream> containing existing data
		explicit DataBuffer(const ByteStream& data);

		//Destructor: ~DataBuffer
		//	Default destructor for the DataBuffer object
		virtual ~DataBuffer();

	public:

		//Function: peekByte
		//	Gets the next byte from the buffer without moving the read position
		//
		//Returns:
		//	The next byte in the buffer, based on its current position
		//
		//Exceptions:
		//	- std::out_of_range: The index requested is out of range
		uint8 peekByte();

		//Function: read_int8
		//	Reads the next 1-byte signed integer from the buffer
		//
		//Returns:
		//	The next int8 in the buffer, based on its current position
		//
		//Exceptions:
		//	- std::out_of_range: The index requested is out of range
		int8 read_int8();

		//Function: read_uint8
		//	Reads the next 1-byte unsigned integer from the buffer
		//
		//Returns:
		//	The next uint8 in the buffer, based on its current position
		//
		//Exceptions:
		//	- std::out_of_range: The index requested is out of range
		uint8 read_uint8();

		//Function: read_int16
		//	Reads the next 2-byte signed integer from the buffer
		//
		//Returns: 
		//	The next int16 in the buffer, based on its current position
		//
		//Exceptions:
		//	- std::out_of_range: The index requested is out of range
		int16 read_int16();

		//Function: read_uint16
		//	Reads the next 2-byte unsigned integer from the buffer
		//
		//Returns: 
		//	The next uint16 in the buffer, based on its current position
		//
		//Exceptions:
		//	- std::out_of_range: The index requested is out of range
		uint16 read_uint16();

		//Function: read_uint32
		//	Reads the next 4-byte unsigned integer from the buffer
		//
		//Returns:
		//	The next uint32 in the buffer, based on its current position
		//
		//Exceptions:
		//	- std::out_of_range: The index requested is out of range
		uint32 read_uint32();

		//Function: read_float
		//	Reads the next 4-byte float from the buffer
		//
		//Returns:
		//	The next float in the buffer, based on its current position
		//
		//Exceptions:
		//	- std::out_of_range: The index requested is out of range
		float read_float();

		//Function: read_double
		//	Reads the next 8-byte double from the buffer
		//
		//Returns:
		//	The next double in the buffer, based on its current position
		//
		//Exceptions:
		//	- std::out_of_range: The index requested is out of range
		double read_double();

		//Function: read_string
		//	Reads a string of the specified length from the buffer
		//
		//Parameters:
		//	length - The length (number of characters) of the string to read
		//
		//Returns:
		//	The string of the specified length, starting from the current position in the buffer
		//
		//Exceptions:
		//	- std::out_of_range: The index + length requested is out of range
		std::string read_string(std::size_t length);

		//Function: size
		//	Gets the amount of bytes in the DataBuffer
		//
		//Returns:
		//	The amount of bytes in the DataBuffer
		std::size_t size() const;

		//Function: bytesRemanining
		//	Gets the remaining bytes available to read (append position - read position)
		//
		//Returns:
		//	The remaining number of bytes available to read
		std::size_t bytesRemaining() const;

		//Function: moreToRead
		//	Gets whether or not there are more bytes to be read in the DataBuffer
		//
		//Returns:
		//	true if m_moreToRead is true, false otherwise
		bool moreToRead() const;
		
		//Function: shiftExtraToStart
		//	Copies any unparsed data in the DataBuffer to the front of the buffer. 
		//	Also resets the readPosition and moves the appendPosition to immediately after the data that was moved.
		void shiftExtraToStart();

		//Function: getBufferWriter
		//	Creates a <BufferWriter> object based on this DataBuffer.
		//
		//Returns:
		//	A BufferWriter object used to add data to this DataBuffer
		BufferWriter getBufferWriter();

		//Function: resetBuffer
		//	Resets the append and read positions in the buffer back to 0.
		void resetBuffer();
	};

	//Class: ReadBufferSavePoint
	//	Acts as a save point so that bytes can be read out of a <DataBuffer> and the read point reverted
	//
	//See Also:
	//	<DataBuffer>
	class ReadBufferSavePoint
	{
	public:
		//Constructor: ReadBufferSavePoint
		//	Creates a ReadBufferSavePoint based on the <DataBuffer> passed in
		//
		//Parameters:
		//	data - the data that will be updated or reverted
		ReadBufferSavePoint(DataBuffer* data);

		//Destructor: ReadBufferSavePoint
		//	Destroying a ReadBufferSavePoint object, reverting any uncommited data
		~ReadBufferSavePoint();

	private:
		//Variable: m_data
		//	The <DataBuffer> of data to be accessed
		DataBuffer* m_data;

		//Variable: m_savePosition
		//	The current save position in the <DataBuffer>
		std::size_t m_savePosition;

	public:
		//Function: revert
		//	reverts the read position of the <DataBuffer> back to its saved position
		void revert();

		//Function: commit
		//	commits all the currently read data so that it will not be reverted
		void commit();
	};
}