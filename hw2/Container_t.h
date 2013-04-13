#pragma once

template <T> class Container_t {
public:

	Container_t(): size(0) {}

	size_t count() const { return size; }
	virtual T* find(const T& element) const;
	
	virtual void insert(const T& element) = 0;
	virtual void append(const T& element, size_t index) = 0;
	virtual void prepend(const T& element, size_t index) = 0;

	virtual T* remove(const T& element) = 0;
	void removeAndDelete(const T& element) { delete remove(element); }

	virtual void removeAll() = 0;
	virtual void removeAndDeleteAll() = 0;

private:
	size_t size;

};
