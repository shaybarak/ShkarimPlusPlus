#pragma once
#include "IDs.h"
#include <string>
#include <list>
#include <queue>
#include <iostream>

using namespace std;

class Book_t {
public:
	Book_t(const string& name, const string& author, const ISBN& isbn, unsigned int copies)
		: name(name), author(author), isbn(isbn), availableCopies(copies) {}

	/** Basic queries. */
	const string& getName() const { return name; }
	const string& getAuthor() const { return author; }
	const ISBN& getIsbn() const { return isbn; }
	unsigned int getAvailableCopies() const { return availableCopies; }
	const list<const BorrowerId>& getLenders() const { return lenders; }
	const queue<const BorrowerId>& getWaitingQueue() const { return waitingQueue; }

	/** Derived queries. */
	// Is there at least one free copy of this book
	bool isAvailable() const { return availableCopies > 0; }

	/** Mutators. */
	// Lends book to borrower; throws if no free copies remain
	void lendTo(BorrowerId borrower);
	// Adds borrower to waiting list; throws if there is at least one free copy
	void reserveFor(BorrowerId borrower);
	// Registers that a borrower returned a single copy of the book; throws if borrower not registered as lender
	void returnFrom(BorrowerId borrower);
	// Pops and returns the next borrower in this book's waiting list or INVALID_BORROWER_ID
	BorrowerId getFirstInLine();
	
	/** Text representation. */
	ostream& report(ostream& os) const;

private:
	const string name;
	const string author;
	const ISBN isbn;
	unsigned int availableCopies;
	list<const BorrowerId> lenders;
	queue<const BorrowerId> waitingQueue;
};
