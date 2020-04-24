
#ifndef _ENGINE_MEMORY_STREAM_H
#define	_ENGINE_MEMORY_STREAM_H

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "ServerEngine.h"
#include <vector>
#include <stdexcept>
#include <string>

class MemoryStreamException : public std::exception
{
public:
	MemoryStreamException(const std::string& _Message) :message_(_Message) {}
	virtual const char* what()const noexcept 
	{
		return message_.c_str();
	}
private:
	std::string message_;
};

class ENGINE_API MemoryStream {
public:
	MemoryStream();
	MemoryStream(const std::string& data);
	MemoryStream(const void* src, size_t size);
	~MemoryStream();

	//反序列化
	template <typename T>
	MemoryStream& operator >> (T& value)
	{
		value = read<T>();
		return *this;
	}
	template <typename T>
	T read()
	{
		if (readPos_ + sizeof(T) > writePos_)
		{
			throw MemoryStreamException("Not enough data");
		}	

		T value = *(T*)&data_[readPos_];
		readPos_ += sizeof(T);

		return value;
	}

	std::string readBinary(size_t sz);
	void readBinary(void* buffer, size_t sz,size_t bufferSize);
	std::string readString();

	std::string readAll();

	//序列化
	template <typename T> MemoryStream& operator << (const T& value)
	{
		append(value);
		return *this;
	}

	template <typename T>
	void append(const T& value) 
	{
		return appendBinary(&value, sizeof(T));
	}

	void appendBinary(const void* src, size_t size);
	void appendString(const std::string& str);

	//-----------------------------------------------------
	const void* data() const;
	size_t size() const;
	size_t capacity() const;

	size_t wPos() const;
	size_t rPos() const;

	size_t readSize() const;

	void clear(bool clearData = false);

	bool empty() const;

	void remove(size_t offset, size_t count);

	void removeFront(size_t count);

	void resetReadPos();
	
protected:
	std::vector<uint8_t> data_;
	size_t writePos_, readPos_,startPos_;
};

#endif