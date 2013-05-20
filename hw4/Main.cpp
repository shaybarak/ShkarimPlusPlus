#include "Library_t.h"
#include "Book_t.h"
#include "Borrower_t.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Library_t library;
    bool cont = true;    		// trigger to stop loop
    unsigned int choice;
	string name, author, isbn;
	BorrowerId borrowerId;
	unsigned int copies;
	Book_t* book;
	Borrower_t* borrower;
    
    cout << "Sssshhhh!! Welcome to the library." << endl;
    cout << "Please remain quiet for the duration of your visit." << endl;
    
    while (cont) {
    	cout << "  0: Add book"    		    << endl
			 << "  1: Remove book"	            << endl
			 << "  2: Add borrower"            << endl
			 << "  3: Remove borrower"         << endl
			 << "  4: Register a borrow"       << endl
             << "  5: Register a return"       << endl
             << "  6: Print books report"      << endl
             << "  7: Print borrowers report"  << endl
			 << "Enter your choice: ";
		cin >> choice;
        
        try {
            switch (choice) {
                case 0:
                    cout << "Name: ";
                    cin >> name;
                    cout << "Author: ";
                    cin >> author;
                    cout << "ISBN: ";
                    cin >> isbn;
                    cout << "Copies: ";
                    cin >> copies;
                    book = new Book_t(name, author, isbn, copies);
                    library.addBook(book);
                    cout << "Book added." << endl;
                    break;
                
                case 1:
                    cout << "ISBN: ";
                    cin >> isbn;
                    library.removeBook(isbn);
                    cout << "Removed." << endl;
                    break;
                    
                case 2:
                    cout << "Name: ";
                    cin >> name;
                    borrower = new Borrower_t(name);
                    cout << "Created new borrower with ID "
                         << borrower->getBorrowerId() << endl;
                    library.addBorrower(borrower);
                    cout << "Borrower added." << endl;
                    break;
                    
                case 3:
                    cout << "Borrower ID: ";
                    cin >> borrowerId;
                    library.removeBorrower(borrowerId);
                    cout << "Borrower removed." << endl;
                    break;
                    
                case 4:
                    cout << "Borrower ID: ";
                    cin >> borrowerId;
                    cout << "ISBN: ";
                    cin >> isbn;
                    library.registerBorrow(borrowerId, isbn);
                    cout << "Registered borrow." << endl;
                    break;
                    
                case 5:
                    cout << "Borrower ID: ";
                    cin >> borrowerId;
                    cout << "ISBN: ";
                    cin >> isbn;
                    library.registerReturn(borrowerId, isbn);
                    cout << "Registered return." << endl;
                    break;
                    
                case 6:
                    library.reportBooks(cout);
                    break;
                    
                case 7:
                    library.reportBorrowers(cout);
                    break;

				default:
					cont = false;
            }
        } catch (char* message) {
            cerr << "Error: " << message << endl;
        }
    }
}
