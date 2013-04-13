#pragma once

template <T> class Array_t {
public:

	Array_t() : Container_t(), arr(new T*[INITIAL_CAPACITY]), capacity(INITIAL_CAPACITY) {}

	~Array_t() {
		removeAll();
	}

	virtual T* find(const T& element) const {
		for (size_t i = 0; i < size; i++) {
			if (*arr[i] == element) {
				return arr[i];
			}
		}
		return null;
	}
	
	virtual void insert(const T& element) {
		if (size == capacity) { 
			extend();  
		}
		arr[size] = &element;
		size++;
	}

	virtual void append(const T& element, size_t index) {
		if (index >= size) {
			//TODO illegeal indices
		}
		
		//appent to last value
		if ((index == size - 1) && (size < capacity - 1)) {
			arr[index] = element;
		} else if ((index == size - 1) && (size == capacity - 1)) {
			extend();
			arr[index] = element;
		} else if (size == capacity - 1) {
			for (int i = size - 1; i >= index; ) {
			}
		}
		

	}
	virtual void prepend(const T& element, size_t index) = 0;

	virtual T* remove(const T& element) = 0;
	void removeAndDelete(const T& element) { delete remove(element); }

	virtual void removeAll() = 0;
	virtual void removeAndDeleteAll() = 0;

private:

	void extend() {
		T* newArr = new T*[capacity + EXTRA_CAPACITY];
		for (size_t i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		capacity += EXTRA_CAPACITY;
	}

	T* arr[];
	static const size_t INITIAL_CAPACITY = 4;
	static const size_t EXTRA_CAPACITY = 4;
	size_t capacity;

}