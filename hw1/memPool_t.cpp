#include "memPool_t.h"
#include <algorithm>

using namespace std;

memPool_t::memPool_t(size_t page_size, size_t initial_page_capacity) : page_size(page_size) {
	pages.reserve(initial_page_capacity);
	for (size_t i = 0; i < initial_page_capacity; i++) {
		pages.push_back(new memPage_t(page_size));
	}
}

memPool_t::~memPool_t() {
	// Memory pool owns the pages so it must delete them on destruction
	for (vector<memPage_t*>::iterator iter = pages.begin(); iter < pages.end(); iter++) {
		delete *iter;
	}
}

void memPool_t::read(void* out, size_t len, unsigned int pos = pos) const {
	// TODO handle OOB reads
	// if ((pos > size) || (pos + len > capacity)) {
	//     kaki
	// }
	// Find page boundaries
	size_t begin_page = pos / page_size;
	size_t end_page = (pos + len - 1) / page_size;
	for (size_t page = begin_page; page <= end_page; page++) {
		// Read from page
		size_t to_read = min(len, page_size - (pos % page_size));
		pages[page]->read(out, to_read, pos % page_size);
		pos += to_read;
		len -= to_read;
		out = ((char*)out) + to_read;
	}
}

void memPool_t::write(void* const in, size_t len, unsigned int pos = pos) {
	// TODO handle OOB writes
	// if ((pos > size) || (pos + len > capacity)) {
	//     kaki
	// }
	size_t begin_page = pos / page_size;
	size_t end_page = (pos + len - 1) / page_size;
	for (size_t page = begin_page; page <= end_page; page++) {
		// Write to page
		size_t to_write = min(len, page_size - (pos % page_size));
		pages[page]->read(out, to_write, pos % page_size);
		pos += to_write;
		len -= to_write;
		out = ((char*)out) + to_write;
	}
	size = max(size, pos);
}
