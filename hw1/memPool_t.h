#ifndef MEMPOOL_T
#define MEMPOOL_T

#include <vector>
#include "memPage_t.h"

using namespace std;

class memPool_t {
public:

	//Constructs with given page size and empty pages
	memPool_t(unsigned int page_size, unsigned int empty_pages = 1);

	unsigned int get_pos() const { return pos; }


private:

	// Disallow copy constructor
	memPool_t(const memPool_t& that);

	unsigned int page_size;
	vector<memPage_t> pages;
	unsigned int pos;
};

#endif
