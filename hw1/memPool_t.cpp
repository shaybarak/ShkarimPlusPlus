#include "memPool_t.h"

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

size_t memPool_t::get_size() const {

}
