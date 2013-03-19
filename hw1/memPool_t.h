#ifndef MEMPOOL_T
#define MEMPOOL_T

#include <vector>
#include "memPage_t.h"

using namespace std;

class memPool_t {
public:

	// Constructs with a given page capacity and initial number of allocated pages
	memPool_t(size_t newPageCapacity, size_t initialPageCount = 1);
	~memPool_t();

	// Queries
	unsigned int getPos() const { return pos; }
	size_t getSize() const { return size; }
	size_t getPageCount() const { return pages.size(); }
	size_t getCapacity() const { return poolCapacity; }
	bool isEmpty() const { return getSize() == 0; }
	bool isFull() const { return getSize() == getCapacity(); }
	
	// Mutators
	bool setPos(size_t newPos);
	bool setNewPageCapacity(size_t newNewPageCapacity);

	// Access
	bool read(void* out, size_t len) { return read(out, len, pos); }
	bool read(void* out, size_t len, size_t usrPos);

	bool write(const void* in, size_t len) { return write(in, len, pos); }
	bool write(const void* in, size_t len, size_t usrPos);

private:

	// Disallow copy constructor
	memPool_t(const memPool_t& that);

	// Adds new page to the pool
	void addNewPage();

	// Translates an allocated pool position to in-page position
	// Returns the page's index in the pool
	size_t findPage(size_t* pos);

	// Capacity for new pages
	size_t newPageCapacity;
	// Total capacity of all pages in the pool
	size_t poolCapacity;
	// Backing store of pages
	vector<memPage_t*> pages;
	// Actual size (spanning over all pages)
	size_t size;
	// Cursor
	size_t pos;
};

#endif
