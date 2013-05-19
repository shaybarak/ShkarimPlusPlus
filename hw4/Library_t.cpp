#include "Library_t.h"

using namespace std;

Library_t::~Library_t() {
	// Since we take ownership of books and borrowers, delete these objects
	for (map<ISBN, Book_t*>::iterator it = books.begin(); it != books.end(); it++) {
		delete it->second;
	}
	for (map<BorrowerId, Borrower_t*>::iterator it = borrowers.begin(); it != borrowers.end(); it++) {
		delete it->second;
	}
}

void Library_t::addBook(Book_t* book) {
	// On insertion, check if the book was already registered
	if (books.insert(make_pair(book->getIsbn(), book)).second) {
		throw "Book already registered!";
	}
}

void Library_t::removeBook(ISBN isbn) {
	map<ISBN, Book_t*>::iterator it = books.find(isbn);
	if (it == books.end()) {
		throw "Book not found!";
	}
	if (!(it->second->getLenders().empty())) {
		throw "Cannot remove book if there is at least one borrowed copy!";
	}
	delete it->second;
	books.erase(it);
}

void Library_t::addBorrower(Borrower_t* borrower) {
	// On insertion, check if the book was already registered
	if (borrowers.insert(make_pair(borrower->getBorrowerId(), borrower)).second) {
		throw "Borrower already registered!";
	}
}

void Library_t::removeBorrower(BorrowerId borrowerId) {
	map<BorrowerId, Borrower_t*>::iterator it = borrowers.find(borrowerId);
	if (it == borrowers.end()) {
		throw "Borrower not found!";
	}
	if (!(it->second->getBorrowedBooks().empty())) {
		throw "Cannot remove borrower if they have at least one borrowed book!";
	}
	delete it->second;
	borrowers.erase(it);
}

void Library_t::registerBorrow(BorrowerId borrowerId, ISBN isbn) {
	map<BorrowerId, Borrower_t*>::iterator borrowerIt = borrowers.find(borrowerId);
	if (borrowerIt == borrowers.end()) {
		throw "Borrower not found!";
	}
	Borrower_t* borrower = borrowerIt->second;
	map<ISBN, Book_t*>::iterator bookIt = books.find(isbn);
	if (bookIt == books.end()) {
		throw "Book not found!";
	}
	Book_t* book = bookIt->second;
	if (book->isAvailable()) {
		// If book is available, lend it immediately
		book->lendTo(borrowerId);
		borrower->borrowBook(isbn);
	} else {
		book->reserveFor(borrowerId);
	}
}

void Library_t::registerReturn(BorrowerId borrowerId, ISBN isbn) {
	map<BorrowerId, Borrower_t*>::iterator borrowerIt = borrowers.find(borrowerId);
	if (borrowerIt == borrowers.end()) {
		throw "Borrower not found!";
	}
	Borrower_t* borrower = borrowerIt->second;
	map<ISBN, Book_t*>::iterator bookIt = books.find(isbn);
	if (bookIt == books.end()) {
		throw "Book not found!";
	}
	Book_t* book = bookIt->second;
	// Verify that borrower has book
	if (!borrower->has(isbn)) {
		throw "Borrower does not have the specified book!";
	}
	borrower->returnBook(isbn);
	book->returnFrom(borrowerId);
	BorrowerId nextBorrowerId = book->getFirstInLine();
	if (nextBorrowerId != INVALID_BORROWER_ID) {
		// Give the newly-returned copy to the first borrower in line
		borrowerIt = borrowers.find(nextBorrowerId);
		if (borrowerIt == borrowers.end()) {
			throw "Next borrower not found!";
		}
		Borrower_t* nextBorrower = borrowerIt->second;
		nextBorrower->borrowBook(isbn);
		book->lendTo(nextBorrowerId);
	}
}

ostream& Library_t::reportBooks(ostream& os) const {
	os << "Books report:" << endl
	   << "=============" << endl;
	Book_t* book;
	for (map<ISBN, Book_t*>::const_iterator it = books.begin(); it != books.end(); it++) {
		it->second->report(os);
		os << endl;
	}
	return os;
}

ostream& Library_t::reportBorrowers(ostream& os) const {
	os << "Borrowers report:" << endl;
	os << "=================" << endl;
	Borrower_t* borrower;
	for (map<BorrowerId, Borrower_t*>::const_iterator it = borrowers.begin(); it != borrowers.end(); it++) {
		it->second->report(os);
	}
	return os;
}
