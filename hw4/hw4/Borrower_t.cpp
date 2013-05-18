#include "Borrower_t.h"
#include <algorithm>

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

// First BorrowerId value to provision
BorrowerId Borrower_t::nextBorrowerId = 1;
