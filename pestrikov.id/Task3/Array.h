#pragma once
#include <exception>
#include <algorithm>

template <class T>
class Array
{
public:
	//Constructors-----------------------------------------------------------
	Array();
	Array(int size);
	Array(const Array<T>& other);

	//Destructor-------------------------------------------------------------
	~Array();

	//Methods----------------------------------------------------------------
	//Changes actual size of array
	void resize(int size);

	int getSize() const { return size; }
	int getCapacity() const { return capacity; }

	void pushBack(T element);	

	void clear();

	//Operators--------------------------------------------------------------
	T& operator[](int index);	

	const T& operator[](int index) const;
	

	T& operator=(const Array<T>& other);

	bool operator==(const Array<T>& other);

private:
	T* data;
	int size; //current size of array
	int capacity; //size of allocated memory

	const int START_SIZE = 0;
	const int START_CAPACITY = 1;

	void expandCapacity(int newCapaity);

	void defaultInit();

public:
	class OutOfRangeException : public std::exception
	{
	public:
		OutOfRangeException(const char* message) : std::exception(message)
		{}

		OutOfRangeException() : std::exception()
		{}
	};

	class SizeLessThanZeroException : public std::exception
	{
	public: 
		SizeLessThanZeroException(const char* message) : std::exception(message)
		{}

		SizeLessThanZeroException() : std::exception()
		{}
	};
};


template<class T>
inline void Array<T>::defaultInit() {
	capacity = START_CAPACITY;
	size = START_SIZE;
	data = new T[START_CAPACITY];
}

template<class T>
inline Array<T>::Array() {
	defaultInit();
}

template<class T>
inline Array<T>::Array(int size) {
	if (size < 0) {
		throw SizeLessThanZeroException();
	}

	if (size == 0) {
		defaultInit();
	}
	else {
		capacity = size;
		this->size = size;
		data = new T[size];
	}
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
	data = nullptr;
	size = -1;
	capacity = -1;

}

template<class T>
inline void Array<T>::resize(int size) {
	if (size < 0) {
		throw SizeLessThanZeroException();
	}

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
inline void Array<T>::pushBack(T element) {
	if (size == capacity) {
		expandCapacity(capacity * 2);
	}
	data[size++] = element;
}

template<class T>
inline void Array<T>::clear() {
	delete[] data;
	capacity = START_CAPACITY;
	size = START_SIZE;
	data = new T[START_CAPACITY];
}

template<class T>
inline T & Array<T>::operator[](int index) {
	if (index >= size || index < 0) {
		throw OutOfRangeException("Index >= size");
	}
	return data[index];
}

template<class T>
inline const T & Array<T>::operator[](int index) const {
	if (index >= size || index < 0) {
		throw OutOfRangeException("Index >= size");
	}
	return data[index];
}


template<class T>
inline T& Array<T>::operator=(const Array<T>& other) {
	if (this == &other) {
		return *this;
	}

	//Size of allocated memory is enough to copy all elements from other to this	
	if (this->capacity >= other.size) {
		std::copy(other.data, other.data + other.size, data);
		this->size = other.size;
		return *this;
	}

	//If it's necessary to expand this
	delete[] this->data;
	std::copy(other.data, other.data + other.size, data);
	//std::copy is analog of this
	/*
	this->data = new T[other.size];
	for (size_t i = ; i < other.size; ++i) {
		this->data[i] = other.data[i];
	}
	*/

	this->size = other.size;
	this->capacity = other.size;

	return *this;
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
inline void Array<T>::expandCapacity(int newCapaity) {
	T* newData = new T[newCapaity];
	std::copy(data, data + size, newData);
	delete[] data;
	data = newData;
	capacity = newCapaity;
}


