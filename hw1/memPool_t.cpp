#include "memPool_t.h"
#include <algorithm>

using namespace std;

memPool_t::memPool_t(size_t newPageCapacity, size_t initalPageCount) : newPageCapacity(newPageCapacity), size(0), pos(0), poolCapacity(0) {
	pages.reserve(initalPageCount);
	for (size_t i = 0; i < initalPageCount; i++) {
		addNewPage();
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

bool memPool_t::setNewPageCapacity(size_t newNewPageCapacity) {
	if (newNewPageCapacity <= 0) {
		return false;
	}
	newPageCapacity = newNewPageCapacity;
	return true;
}

void memPool_t::addNewPage() {
	pages.push_back(new memPage_t(newPageCapacity));
	poolCapacity += newPageCapacity;
}

size_t memPool_t::findPage(size_t* pos) {
	size_t pageNum = 0;
	while (*pos >= pages[pageNum]->getCapacity()) {
		pageNum++;
		*pos -= pages[pageNum]->getCapacity();		
	}
	return pageNum;
}

bool memPool_t::read(void* out, size_t len, unsigned int usrPos) {
	// Cannot read out of bounds
	if (usrPos + len > size) {
		return false;
	}
	pos = usrPos;
	// Find offset within first page
	size_t offset = pos;
	size_t pageNum = findPage(&offset);
	// Iterate over pages spanning range
	while (len > 0) {
		size_t toRead = min(len, pages[pageNum]->getCapacity() - offset);
		if (!pages[pageNum]->read(out, toRead, offset)) {
			return false;
		}
		pos += toRead;
		len -= toRead;
		pageNum++;
		offset = 0;
	}
	return true;
}

bool memPool_t::write(const void* in, size_t len, unsigned int usrPos) {
	// Cannot allow holes in memory
	if (usrPos > size) {
		return false;
	}
	// Special handling for write to end of pool on page boundary
	if (usrPos == getCapacity()) {
		addNewPage();
	}
	pos = usrPos;
	// Find offset within first page
	size_t offset = pos;
	size_t pageNum = findPage(&offset);
	// Iterate over pages spanning range
	while (len > 0) {
		// Expand pool if necessary
		if (pageNum >= pages.size()) {
			addNewPage();
		}
		size_t toWrite = min(len, pages[pageNum]->getCapacity() - offset);
		if (!pages[pageNum]->write(in, toWrite, offset)) {
			return false;
		}
		pos += toWrite;
		size = max(size, pos);
		len -= toWrite;
		pageNum++;
		offset = 0;
	}
	return true;
}
