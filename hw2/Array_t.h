#pragma once

template <class T> class Array_t : public Container_t<T> {
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
			//TODO illegeal indices -> expcetion, neew explanations
		}
		if (size == capacity) {
			extend();
		}
		for (int i = size; i > index + 1; i--) {
			arr[i] = arr[i-1];
		}
		arr[index] = element;
	}
	
	virtual void prepend(const T& element, size_t index) {
		if (index >= size) {
			//TODO illegeal indices -> expcetion, neew explanations
		}
		if (index == capacity) {
			extend();
		}
		for (int i = size; i > index; i--) {
			arr[i] = arr[i-1];
		}
		arr[index] = element;
	}

	virtual T* remove(const T& element) {
		int removeIndex = 0;
		for (; removeIndex < size; removeIndex++) {
			if (arr[removeIndex] = element) {
				break;
			}
		}
		if (removeIndex == size) {
			return null;
		}
		for (int i = removeIndex; i < size - 1; i--) {
			arr[i] = arr[i+1];
		}

	}

	virtual void removeAll() {
		delete[] arr;
		size = 0;
		capacity = 0;
	}

	virtual void removeAndDeleteAll() {
		for (int i = 0; i < size; i++) {
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
			arr[i] = rhs.add[i];
		}
		return this;
	}

	T* operator[] (size_t index) {
		if (index >= size) {
			//throw new 
		}
		return arr[i];
	}

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

};