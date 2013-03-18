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

size_t memPool_t::findPage(size_t pos) {
	int posLeft = pos;
	size_t pageNum = -1;
	while (posLeft >= 0) {
		pageNum++;
		posLeft -= pages[pageNum]->getCapacity();		
	}
	return pageNum;
}

bool memPool_t::read(void* out, size_t len, unsigned int usrPos) {
	// Cannot read out of bounds
	if (usrPos + len > size) {
		return false;
	}
	pos = usrPos;
	// Find page boundaries
	size_t beginPage = findPage(pos);
	size_t endPage = findPage(pos + len - 1);
	for (size_t pageNum = beginPage; pageNum <= endPage; pageNum++) {
		// Read from page
		size_t to_read = min(len, pages[pageNum]->getCapacity() - (pos % pages[pageNum]->getCapacity()));
		pages[pageNum]->read(out, to_read, pos % pages[pageNum]->getCapacity());
		pos += to_read;
		len -= to_read;
		out = (char*)((char*)out + to_read);
	}
	return true;
}

bool memPool_t::write(const void* in, size_t len, unsigned int usrPos) {
	// Cannot allow holes in memory
	if (usrPos > size) {
		return false;
	}
	pos = usrPos;

	if (pos == getCapacity()) {
		addNewPage();
	}
	size_t pageNum = findPage(pos);
	while (len > 0) {
		if (pageNum >= pages.size()) {
			addNewPage();
		}
		// Write to page
		size_t toWrite = min(len, pages[pageNum]->getCapacity() - (pos % pages[pageNum]->getCapacity()));
		pages[pageNum]->write(in, toWrite, pos % pages[pageNum]->getCapacity());
		pos += toWrite;
		len -= toWrite;
		in = (char*)((char*)in + toWrite);
		pageNum++;
	}
	size = max(size, pos);
	return true;
}
