#pragma once
#include <exception>
#include <algorithm>

#define TEST

template <class T>
class Array
{
public:
	//Constructors-----------------------------------------------------------
	Array();
	Array(size_t size);
	Array(const Array<T>& other);

	//Destructor-------------------------------------------------------------
	~Array();

	//Methods----------------------------------------------------------------
	//Changes actual size of array
	void resize(size_t size);

	size_t getSize() const { return size; }
	size_t getCapacity() const { return capacity; }

	void pushBack(T element) {
		if (size == capacity) {
			expandCapacity(capacity * 2);
		}
		data[size++] = element;
	}

	void clear();

	//Operators--------------------------------------------------------------
	T& operator[](size_t index) {
		if (index >= size) {
			throw OutOfRangeException("Index >= size");
		}
		return data[index];
	}

	const T& operator[](size_t index) const {
		if (index >= size) {
			throw OutOfRangeException("Index >= size");
		}
		return data[index];
	}

	T operator=(const Array<T>& other);

	bool operator==(const Array<T>& other);

private:
	T* data;
	size_t size; //current size of array
	size_t capacity; //size of allocated memory

	const size_t START_SIZE = 0;
	const size_t START_CAPACITY = 1;

	void expandCapacity(size_t newCapaity);

public:
	class OutOfRangeException : public std::exception
	{
	public:
		OutOfRangeException(const char* message) : std::exception(message)
		{ }
	};
};




template<class T>
inline Array<T>::Array() {
	capacity = START_CAPACITY;
	size = START_SIZE;
	data = new T[START_CAPACITY];
}

template<class T>
inline Array<T>::Array(size_t size) {
	capacity = size;
	this->size = size;
	data = new T[size];
}

template<class T>
inline Array<T>::Array(const Array<T>& other) {
	//Size of allocated memory is enough to copy all elements from other to this	
	if (this->capacity >= other.size) {
		std::copy(other.data, other.data + other.size, data);
		size = other.size;
		return;
	}

	//If it's necessary to expand this
	delete[] this->data;
	this->data = new T[other.size];
	for (size_t i = ; i < other.size; ++i) {
		this->data[i] = other.data[i];
	}
	this->size = other.size;
	this->capacity = other.size;
}



template <class T>
inline Array<T>::~Array() {
	delete[] data;
}

template<class T>
inline void Array<T>::resize(size_t size) {
	//Size of allocated memory is enough to expand current size of array
	//or to narrow it
	if (size <= this->capacity) {
		this->size = size;
		return;
	}

	//Copy old array
	T* newData = new T[size];
	std::copy(data, data + this->size, newData);

	delete[] data;
	this->size = size;
	this->capacity = size;
	data = newData;
}

template<class T>
inline void Array<T>::clear() {
	delete[] data;
	capacity = START_CAPACITY;
	size = START_SIZE;
	data = new T[START_CAPACITY];
}

template<class T>
inline T Array<T>::operator=(const Array<T>& other) {
	if (this == *other) {
		return this;
	}

	//Size of allocated memory is enough to copy all elements from other to this	
	if (this->capacity >= other.size) {
		std::copy(other.data, other.data + other.size, data);
		this->size = other.size;
		return this;
	}

	//If it's necessary to expand this
	delete[] this->data;
	this->data = new T[other.size];
	for (size_t i = ; i < other.size; ++i) {
		this->data[i] = other.data[i];
	}
	this->size = other.size;
	this->capacity = other.size;

	return this;
}

template<class T>
inline bool Array<T>::operator==(const Array<T>& other) {
	if (size != other.size) {
		return false;
	}
	for (int i = 0; i < size; ++i) {
		if (data[i] != other.data[i]) {
			return false;
		}
	}
	return true;
}

template<class T>
inline void Array<T>::expandCapacity(size_t newCapaity) {
	T* newData = new T[newCapaity];
	std::copy(data, data + size, newData);
	delete[] data;
	data = newData;
	capacity = newCapaity;
}


