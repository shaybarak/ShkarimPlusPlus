#include <string>
#include <list>
#include "IDs.h"

using namespace std;

class Borrower_t {
public:
	Borrower_t(const string& name)
	: name(name), borrowerId(newBorrowerId()){}

	/** Basic queries. */
	const BorrowerId getBorrowerId() const { return borrowerId; }
	const string& getName() const { return name; }
	const list<const ISBN>& getBorrowedBooks() const { return borrowedBooks; }

	/** Mutators. */
	// borrow a book
	void borrowBook(ISBN isbn);
	// Return a book
	void returnBook(ISBN isbn);

private:
	static BorrowerId newBorrowerId() { return nextBorrowerId++; }
	static BorrowerId nextBorrowerId;

	const string name;
	BorrowerId borrowerId;
	list<const ISBN> borrowedBooks;
};
