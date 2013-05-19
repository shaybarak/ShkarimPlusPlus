#include "Book_t.h"
#include "Borrower_t.h"
#include "IDs.h"
#include <map>

using namespace std;

class Library_t {
public:
    ~Library_t();

	/** Mutators. */
	// Adds a book to the library (takes ownership); throws if the book is already registered
	void addBook(Book_t* book);
	// Removes a book from the library; throws if there are borrowed copies of the book
	void removeBook(ISBN isbn);
	// Adds a borrower to the library (takes ownership); throws if the borrower is already registered
	void addBorrower(Borrower_t* borrower);
	// Removes a borrower from the library; throws if there are borrowed books by the borrower
	void removeBorrower(BorrowerId isbn);

	/** Borrower operations. */
	// Registers a borrower's intent to borrow a book.
	// Satisfies request immediately if the book is available, else puts borrower on waiting list.
	// Throws if either borrower or book are not found.
	void registerBorrow(BorrowerId borrower, ISBN book);
	// Registers a borrower's intent to return a book.
	// The book is returned to the library or moved to the next borrower in the book's reservation list.
	// Throws if either borrower or book are not found.
	void registerReturn(BorrowerId borrower, ISBN book);

	/** Reports. */
	ostream& reportBooks(ostream& os);
	ostream& reportBorrowers(ostream& os);

private:
	map<ISBN, Book_t*> books;
	map<BorrowerId, Borrower_t*> borrowers;
};
