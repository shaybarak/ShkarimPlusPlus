#ifndef ARRAY_T_H
#define ARRAY_T_H

#include <stdio.h>
#include <stdlib.h>
#include "Container_t.h"

template <class T>
class Array_t : public Container_t<T> {
public:

	Array_t() : Container_t<T>(), arr(new T*[INITIAL_CAPACITY]), capacity(INITIAL_CAPACITY) {}

	Array_t(const Array_t<T>& rhs) {
		operator=(rhs);
	}

	virtual T* find(const T& element) const {
		for (size_t i = 0; i < size; i++) {
			if (*arr[i] == element) {
				return arr[i];
			}
		}
		return NULL;
	}
	
	virtual void insert(T& element) {
		if (size == capacity) { 
			extend();  
		}
		arr[size++] = new T(element);
	}

	virtual void append(T& element, size_t index) {
		if (index >= size) {
			throw "Index out of bounds!";
		}
		if (size == capacity) {
			extend();
		}
		for (unsigned int i = size; i > index + 1; i--) {
			arr[i] = arr[i-1];
		}
		arr[index] = &element;
	}
	
	virtual void prepend(T& element, size_t index) {
		if (index >= size) {
			throw "Index out of bounds!";
		}
		if (index == capacity) {
			extend();
		}
		for (unsigned int i = size; i > index; i--) {
			arr[i] = arr[i-1];
		}
		arr[index] = &element;
	}

	virtual T* remove(const T& element) {
		unsigned int removeIndex = 0;
		for (; removeIndex < size; removeIndex++) {
			if (*arr[removeIndex] == element) {
				break;
			}
		}
		if (removeIndex == size) {
			return NULL;
		}
		T* result = arr[removeIndex];
		for (unsigned int i = removeIndex; i < size - 1; i--) {
			arr[i] = arr[i+1];
		}
		size--;
		return result;
	}

	virtual void removeAll() {
		delete[] arr;
		size = 0;
		capacity = 0;
	}

	virtual void removeAndDeleteAll() {
		for (unsigned int i = 0; i < size; i++) {
			delete arr[i];
		}
		removeAll();
	}

	Array_t& operator= (const Array_t<T>& rhs) {
		removeAll();
		arr = new T*[rhs.capacity];
		size = rhs.size;
		capacity = rhs.capacity;
		for (int i = 0; i < size; i++) {
			insert(rhs[i]);
		}
		return this;
	}

	T* operator[] (size_t index) {
		if (index >= size) {
			throw "Index out of bounds!";
		}
		return arr[index];
	}

private:

	void extend() {
		T** newArr = new T*[capacity + EXTRA_CAPACITY];
		for (size_t i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		capacity += EXTRA_CAPACITY;
	}

	T** arr;
	static const size_t INITIAL_CAPACITY = 4;
	static const size_t EXTRA_CAPACITY = 4;
	size_t capacity;
};

#endif
