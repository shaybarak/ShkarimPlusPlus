#include "memPool_t.h"
#include <algorithm>

using namespace std;

memPool_t::memPool_t(size_t pageCapacity, size_t initialPoolCapacity) : pageCapacity(pageCapacity), size(0), pos(0) {
	pages.reserve(initialPoolCapacity);
	for (size_t i = 0; i < initialPoolCapacity; i++) {
		pages.push_back(new memPage_t(pageCapacity));
	}
}

memPool_t::~memPool_t() {
	// Memory pool owns the pages so it must delete them on destruction
	for (vector<memPage_t*>::iterator iter = pages.begin(); iter < pages.end(); iter++) {
		delete *iter;
	}
}

bool memPool_t::setPos(size_t newPos)  {
	if (newPos > getSize()) {
		return false;
	}
	pos = newPos;
	return true;
}

bool memPool_t::read(void* out, size_t len, unsigned int usrPos) {
	//cannot read beyond end of memory
	if (usrPos + len > size) {
		return false;
	}
	pos = usrPos;
	// Find page boundaries
	size_t begin_page = pos / pageCapacity;
	size_t end_page = (pos + len - 1) / pageCapacity;
	for (size_t page = begin_page; page <= end_page; page++) {
		// Read from page
		size_t to_read = min(len, pageCapacity - (pos % pageCapacity));
		pages[page]->read(out, to_read, pos % pageCapacity);
		pos += to_read;
		len -= to_read;
		out = (char*)((char*)out + to_read);
	}
	return true;
}

bool memPool_t::write(const void* in, size_t len, unsigned int usrPos) {

	//cannot start write beyond size
	if (usrPos > size) {
		return false;
	}
	pos = usrPos;
	size_t begin_page = pos / pageCapacity;
	size_t end_page = (pos + len - 1) / pageCapacity;
	for (size_t page = begin_page; page <= end_page; page++) {
		// Extend pool if necessary
		if (page >= pages.size()) {
			pages.push_back(new memPage_t(pageCapacity));
		}
		// Write to page
		size_t toWrite = min(len, pageCapacity - (pos % pageCapacity));
		pages[page]->write(in, toWrite, pos % pageCapacity);
		pos += toWrite;
		len -= toWrite;
		in = (char*)((char*)in + toWrite);
	}
	size = max(size, pos);
	return true;
}
