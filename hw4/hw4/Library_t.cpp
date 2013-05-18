#include "Library_t.h"

using namespace std;

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
	map<BorrowerId, Borrower_t*>::iterator it = borrowers.find(borrowerId);
	if (it == borrowers.end()) {
		throw "Borrower not found!";
	}
	// TODO
}

void Library_t::registerReturn(BorrowerId borrowerId, ISBN isbn) {
	map<BorrowerId, Borrower_t*>::iterator it = borrowers.find(borrowerId);
	if (it == borrowers.end()) {
		throw "Borrower not found!";
	}
	// TODO
}
