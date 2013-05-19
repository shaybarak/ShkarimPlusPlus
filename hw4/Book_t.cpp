#include "Book_t.h"
#include "IDs.h"
#include <algorithm>
#include <iostream>

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
	waitingList.push_back(borrower);
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
	if (waitingList.empty()) {
		return INVALID_BORROWER_ID;
	}
	BorrowerId next = waitingList.front();
	waitingList.pop_front();
	return next;
}

ostream& Book_t::report(ostream& os) {
	os << "Name: " << getName() << endl
	   << "Author: " << getAuthor() << endl
	   << "ISBN: " << getIsbn() << endl
	   << "Available copies: " << getAvailableCopies() << endl;
}
