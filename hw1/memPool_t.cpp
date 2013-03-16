#include "memPool_t.h"
#include <algorithm>

using namespace std;

memPool_t::memPool_t(size_t pageCapacity, size_t initialPageCapacity) : pageCapacity(pageCapacity) {
	pages.reserve(initialPageCapacity);
	for (size_t i = 0; i < initialPageCapacity; i++) {
		pages.push_back(new memPage_t(pageCapacity));
	}
}

memPool_t::~memPool_t() {
	// Memory pool owns the pages so it must delete them on destruction
	for (vector<memPage_t*>::iterator iter = pages.begin(); iter < pages.end(); iter++) {
		delete *iter;
	}
}

void memPool_t::read(void* out, size_t len, unsigned int pos) {
	// TODO handle OOB reads
	// if ((pos > size) || (pos + len > capacity)) {
	//     kaki
	// }
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
}

void memPool_t::write(const void* in, size_t len, unsigned int pos) {
	// TODO handle OOB writes
	// if ((pos > size) || (pos + len > capacity)) {
	//     kaki
	// }
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
}
