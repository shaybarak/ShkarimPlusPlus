#include "memPage_t.h"

void memPage_t::read(void* out, size_t len, unsigned int pos = pos) const {
	// TODO handle OOB reads
	for (size_t i = 0; i < len; i++) {
		*((char*)out)++ = store[pos++];
	}
	// Update cursor
	this->pos = pos;
}

void memPage_t::write(void* const in, size_t len, unsigned int pos = pos) {
	// TODO handle OOB writes
	for (size_t i = 0; i < len; i++) {
		store[pos++] = *((char*)in)++;
	}
	// Update cursor
	this->pos = pos;
}
