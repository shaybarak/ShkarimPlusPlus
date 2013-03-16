#ifndef MEMPOOL_T
#define MEMPOOL_T

#include <vector>
#include "memPage_t.h"

using namespace std;

class memPool_t {
public:

	// Constructs with a given page size and initial number of allocated pages
	memPool_t(size_t pageSize, size_t initialPageCapacity = 1);
	~memPool_t();

	// Queries
	unsigned int getPos() const { return pos; }
	size_t getSize() const { return size; }
	size_t getPageCount() const { return pages.size(); }
	size_t getCapacity() const { return getPageCount() * pageSize; }
	bool isEmpty() const { return getSize() == 0; }
	bool isFull() const { return getSize() == getCapacity(); }
	
	// Mutators
	void setPos(size_t newPos) { pos = newPos; }  // TODO handle OOB index

	// Access
	void read(void* out, size_t len) { read(out, len, pos); }
	void read(void* out, size_t len, size_t pos);

	void write(const void* in, size_t len) { write(in, len, pos); }
	void write(const void* in, size_t len, size_t pos);

private:

	// Disallow copy constructor
	memPool_t(const memPool_t& that);

	// Max capacity per page
	size_t pageSize;
	// Backing store of pages
	vector<memPage_t*> pages;
	// Actual size (spanning over all pages)
	size_t size;
	// Cursor
	size_t pos;
};

#endif
