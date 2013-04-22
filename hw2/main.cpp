#include <iostream>
#include "Array_t.h"
#include "Dlist_t.h"
using namespace std;

int main() {

	bool cont	= true;			// trigger to stop loop
	unsigned int c;
	bool isArray;

	Container_t<int>* container;

	cout << "Choose container type:" << endl
	     << "	1: Array_t<int>" << endl
	     << "	2: Dlist_t<int>" << endl;
	cin >> c;

	switch (c) {
		case 1:
			container = new Array_t<int>();
			isArray = true;
			break;
		case 2:
			container = new Dlist_t<int>();
			isArray = false;
			break;
		default:
			cerr << "Unexpected input " << c << endl;
			return;
	}

	while (cont) {
		cout << "	0: count"	 			<< endl
			 << "	1: find" 				<< endl
			 << "	2: insert" 				<< endl
			 << "	3: append" 				<< endl
			 << "	4: prepend" 			<< endl
			 << "	5: remove" 				<< endl
			 << "	6: removeAndDelete" 	<< endl
			 << "	7: removeAll"			<< endl
			 << "	8: removeAndDeleteAll"	<< endl
			 << "	9: type-specific"		<< endl
			 << "Enter your choice: ";
		cin >> c;

		switch (c) {
			case 0:
				test.insert();	// add parameters if needed
				break;
			case 1:
				test.find();	// add parameters if needed
				break;
			case 2:
				test.remove();	// add parameters if needed
				break;
			case 3:
				test.print();	// add parameters if needed
				break;
			case 4:
				test.write();	// add parameters if needed
				break;
			case 5:
				test.size();	// add parameters if needed
				break;
			
			case 9:
				if (isArray) {
					cout << "Retrieve at subscript: ";
					cin >> c;
					cout << (*(Array_t<int>*)container)[c] << endl;
				} else {
					cout << "	0: reset"	<< endl
					     << "	1: next"	<< endl
						 << "	2: prev"	<< endl
						 << "Enter your choice: ";
					cin >> c;
					
					switch (c) {
						case 0:
							cout << *(((Dlist_t<int>*)container)->reset()) << endl;
							break;

						case 1:
							cout << *(((Dlist_t<int>*)container)->next()) << endl;
							break;
						
						case 2:
							cout << *(((Dlist_t<int>*)container)->prev()) << endl;
							break;
						
						case default:
							cont = false;
							break;
					}
				}
				break;

			default:
				cont = false;
				break;
		}
	}

	return 0;
}
