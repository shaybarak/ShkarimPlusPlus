#include "memPage_t.h"
#include <algorithm>

using namespace std;

bool memPage_t::setPos(size_t newPos) { 
	if (newPos > getSize()) {
		return false;
	}
	pos = newPos; 
	return true;
}  

bool memPage_t::read(void* out, size_t len, unsigned int pos) {
	if ((pos > size) || (pos + len > capacity)) {
		return false;
	}
	for (size_t i = 0; i < len; i++) {
		((char*)out)[i] = store[pos++];
	}
	// Update cursor
	this->pos = pos;
	return true;
}

bool memPage_t::write(const void* const in, size_t len, unsigned int pos) {
	if ((pos > size) || (pos + len > capacity)) {
		return false;
	}
	for (size_t i = 0; i < len; i++) {
		store[pos++] = ((char*)in)[i];
	}
	// Update cursor and size
	this->pos = pos;
	size = max(size, pos);
	return true;
}
