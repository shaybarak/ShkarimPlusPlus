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
		cout << "	0: insert" 	<< endl
			 << "	1: find" 	<< endl
			 << "	2: remove" 	<< endl
			 << "	3: print" 	<< endl
			 << "	4: write" 	<< endl
			 << "	5: size" 	<< endl
			 << "Enter your choice : ";
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
			default : cont = false;
		}
	}

	return 0;
}
