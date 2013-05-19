#include "Book_t.h"
#include "IDs.h"
#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

void Book_t::lendTo(BorrowerId borrower) {
	if (!isAvailable()) {
		throw "Cannot lend an unavailable book!";
	}
	lenders.push_back(borrower);
	availableCopies--;
}

void Book_t::reserveFor(BorrowerId borrower) {
	if (isAvailable()) {
		throw "Cannot reserve a book if it's available for immediate rental!";
	}
	waitingQueue.push_back(borrower);
}

void Book_t::returnFrom(BorrowerId borrower) {
	list<const BorrowerId>::iterator it;
	it = find(lenders.begin(), lenders.end(), borrower);
	if (it == lenders.end()) {
		throw "Cannot return a book from a borrower who did not rent it!";
	}
	lenders.erase(it);
	availableCopies++;
}

BorrowerId Book_t::getFirstInLine() {
	if (waitingQueue.empty()) {
		return INVALID_BORROWER_ID;
	}
	BorrowerId next = waitingQueue.front();
	waitingQueue.pop_front();
	return next;
}

ostream& Book_t::report(ostream& os) const {
	os << "Name: " << getName() << endl
	   << "Author: " << getAuthor() << endl
	   << "ISBN: " << getIsbn() << endl
	   << "Available copies: " << getAvailableCopies() << endl;
	if (!lenders.empty()) {
		os << "Lenders:" << endl;
	}
	for (list<const BorrowerId>::const_iterator it = lenders.begin(); it != lenders.end(); it++) {
		os << "\t" << *it << endl;
	}
	if (!waitingQueue.empty()) {
		os << "Waiting queue:" << endl;
	}
	for (list<const BorrowerId>::const_iterator it = waitingQueue.begin(); it != waitingQueue.end(); it++) {
		os << "\t" << *it << endl;
	}
}
