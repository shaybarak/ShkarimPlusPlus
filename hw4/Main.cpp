#include "Library_t.h"
#include "Book_t.h"
#include "Borrower_t.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Library library;
    bool cont = true;    		// trigger to stop loop
    unsigned int choice;
    
    cout << "Sssshhhh!! Welcome to the library." << endl;
    cout << "Please remain quiet for the duration of your visit." << endl;
    
    while (cont) {
    	cout << "	0: Add book"    		    << endl
			 << "	1: Remove book"	            << endl
			 << "	2: Add borrower"            << endl
			 << "	3: Remove borrower"         << endl
			 << "	4: Register a borrow"       << endl
             << "   5: Register a return"       << endl
             << "   6: Print books report"      << endl
             << "   7: Print borrowers report"  << endl
			 << "Enter your choice: ";
		cin >> choice;
        
        try {
            switch (choice) {
                case 0:
                    string name;
                    cout << "Name: ";
                    cin > name;
                    string author;
                    cout << "Author: ";
                    cin >> author;
                    string isbn;
                    cout << "ISBN: ";
                    cin >> isbn;
                    unsigned int copies;
                    cout << "Copies: ";
                    cin >> copies;
                    Book_t* book = new Book_t(name, author, isbn, copies);
                    library.addBook(book);
                    cout << "Book added." << endl;
                    break;
                
                case 1:
                    string isbn;
                    cout << "ISBN: ";
                    cin >> isbn;
                    library.removeBook(isbn);
                    cout << "Removed." << endl;
                    break;
                    
                case 2:
                    string name;
                    cout << "Name: ";
                    cin >> name;
                    Borrower_t* borrower = new Borrower_t(name);
                    cout << "Created new borrower with ID "
                         << borrower->getBorrowerId() << endl;
                    library.addBorrower(borrower);
                    cout << "Borrower added." << endl;
                    break;
                    
                case 3:
                    string borrowerId;
                    cout << "Borrower ID: ";
                    cin >> borrowerId;
                    library.removeBorrower(borrowerId);
                    cout << "Borrower removed." << endl;
                    break;
                    
                case 4:
                    string borrowerId;
                    cout << "Borrower ID: ";
                    cin >> borrowerId;
                    string isbn;
                    cout << "ISBN: ";
                    cin >> isbn;
                    library.registerBorrow(borrowerId, isbn);
                    cout << "Registered borrow." << endl;
                    break;
                    
                case 5:
                    string borrowerId;
                    cout << "Borrower ID: ";
                    cin >> borrowerId;
                    string isbn;
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
            }
        } catch (char* message) {
            cerr << "Error: " << message << endl;
        }
    }
}
