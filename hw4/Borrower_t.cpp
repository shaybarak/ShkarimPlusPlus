#include "Borrower_t.h"
#include <algorithm>
#include <ostream>
#include <map>

bool Borrower_t::has(ISBN isbn) const {
	for (list<const ISBN>::const_iterator it = borrowedBooks.begin(); it != borrowedBooks.end(); it++) {
		if (*it == isbn) {
			return true;
		}
	}
	return false;
}

void Borrower_t::borrowBook(ISBN isbn) {
	borrowedBooks.push_back(isbn);
}

void Borrower_t::returnBook(ISBN isbn) {
	list<const ISBN>::iterator it;
	it = find(borrowedBooks.begin(), borrowedBooks.end(), isbn);
	if (it == borrowedBooks.end()) {
		throw "Cannot return a book from a borrower who did not rent it!";
	}
	borrowedBooks.erase(it);
}

ostream& Borrower_t::report(ostream& os) const {
	os << "Name: " << getName() << endl
	   << "ID: " << getBorrowerId() << endl;
	if (!borrowedBooks.empty()) {
		os << "Books:" << endl;
	}
	for (list<const ISBN>::const_iterator it = borrowedBooks.begin(); it != borrowedBooks.end(); it++) {
		os << "\t" << *it << endl;
	}
	return os;
}

// First BorrowerId value to provision
BorrowerId Borrower_t::nextBorrowerId = 1;
