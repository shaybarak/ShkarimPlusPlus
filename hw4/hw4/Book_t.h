#include <string>
#include <list>
#include "IDs.h"

using namespace std;

class Book_t {
public:
	Book_t(const string& name, const string& author, const ISBN& isbn, unsigned int copies)
		: name(name), author(author), isbn(isbn), availableCopies(0) {}

	/** Basic queries. */
	const string& getName() const { return name; }
	const string& getAuthor() const { return author; }
	const string& getIsbn() const { return isbn; }
	unsigned int getAvailableCopies() const { return availableCopies; }
	const list<const BorrowerId>& getLenders() const { return lenders; }
	const list<const BorrowerId>& getWaitingList() const { return waitingList; }

	/** Derived queries. */
	// Is there at least one free copy of this book
	bool isAvailable() const { return availableCopies > 0; }
	// Returns the next borrower in this book's waiting list or INVALID_BORROWER_ID
	BorrowerId getFirstInLine() const;

	/** Mutators. */
	// Lends book to borrower; throws if no free copies remain
	void lendTo(BorrowerId borrower);
	// Adds borrower to waiting list; throws if there is at least one free copy
	void reserveFor(BorrowerId borrower);
	// Registers that a borrower returned a single copy of the book; throws if borrower not registered as lender
	void returnFrom(BorrowerId borrower);

private:
	const string name;
	const string author;
	const ISBN isbn;
	const unsigned int availableCopies;
	list<const BorrowerId> lenders;
	list<const BorrowerId> waitingList;
};
