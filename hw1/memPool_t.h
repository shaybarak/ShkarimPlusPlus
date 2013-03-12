#ifndef MEMPOOL_T
#define MEMPOOL_T

#include <vector>
#include "memPage_t.h"

using namespace std;

class memPool_t {
public:

	// Constructs with a given page size and initial number of allocated pages
	memPool_t(size_t page_size, size_t initial_page_capacity = 1);

	// Queries
	unsigned int get_pos() const { return pos; }
	size_t get_size() const;
	size_t get_page_count() const { return pages.size(); }
	size_t get_capacity() const { return get_page_count() * page_size; }
	bool is_empty() const { return get_size() == 0; }
	bool is_full() const { return get_size() == get_capacity(); }
	
	// Mutators
	void set_pos(size_t new_pos) { pos = new_pos; }  // TODO handle OOB index

	// Access
	void read(void* out, size_t len, size_t pos = pos) const;
	void write(void* const in, size_t len, size_t pos = pos);

private:

	// Disallow copy constructor
	memPool_t(const memPool_t& that);

	size_t page_size;
	vector<memPage_t&> pages;
	size_t pos;
};

#endif
