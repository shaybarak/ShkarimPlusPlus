#ifndef CONTAINER_T_H
#define CONTAINER_T_H

#include <stdlib.h>

template <class T>
class Container_t {
public:

	Container_t() : size(0) {}
	~Container_t() { removeAll(); }

	size_t count() const { return size; }
	virtual T* find(const T& element) const = 0;
	
	virtual void insert(T& element) = 0;
	virtual void append(T& element, size_t index) = 0;
	virtual void prepend(T& element, size_t index) = 0;

	virtual T* remove(const T& element) = 0;
	void removeAndDelete(const T& element) { delete remove(element); }

	virtual void removeAll() = 0;
	virtual void removeAndDeleteAll() = 0;

protected:
	size_t size;

};

#endif
