#include "Library_t.h"
#include "Book_t.h"
#include "Borrower_t.h"
#include <iostream>

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
                    break;
                
                case 1:
                    break;
                    
                case 2:
                    break;
                    
                case 3:
                    break;
                    
                case 4:
                    break;
                    
                case 5:
                    break;
                    
                case 6:
                    break;
                    
                case 7:
                    break;
            }
        } catch (char* message) {
            cerr << "Error: " << message << endl;
        }
    }
}
