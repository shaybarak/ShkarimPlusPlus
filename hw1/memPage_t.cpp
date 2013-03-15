#include "memPage_t.h"
#include <algorithm>

using namespace std;

void memPage_t::read(void* out, size_t len, unsigned int pos) {
	// TODO handle OOB reads
	// if ((pos > size) || (pos + len > capacity)) {
	//     kaki
	// }
	for (size_t i = 0; i < len; i++) {
		*((char*)out)++ = store[pos++];
	}
	// Update cursor
	this->pos = pos;
}

void memPage_t::write(const void* in, size_t len, unsigned int pos) {
	// TODO handle OOB writes
	// if ((pos > size) || (pos + len > capacity)) {
	//     kaki
	// }
	for (size_t i = 0; i < len; i++) {
		store[pos++] = *((char*)in)++;
	}
	// Update cursor and size
	this->pos = pos;
	size = max(size, pos);
}
