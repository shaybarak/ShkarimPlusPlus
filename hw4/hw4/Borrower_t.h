#include <string>
#include <list>
#include "IDs.h"

using namespace std;

class Borrower_t {
public:
	Borrower_t(const string& name, const BorrowerId borrowerId)
	: name(name), borrowerId(borrowerId){}

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
	const string name;
	BorrowerId borrowerId;
	list<const ISBN> borrowedBooks;
};
