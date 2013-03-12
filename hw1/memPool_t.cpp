#include "memPool_t.h"

memPool_t::memPool_t(unsigned int page_size, unsigned int empty_pages) : page_size(page_size) {
	pages.resize(empty_pages);
}


	