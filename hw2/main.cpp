#include <iostream>
#include "Container_t.h"
#include "Array_t.h"
#include "Dlist_t.h"
using namespace std;

int main() {

	bool cont	= true;			// trigger to stop loop
	unsigned int c;
	bool isArray;
	int element;
	int* newElement;
	int position;

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
			return 1;
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
				cout << "Container contains " << container->count() << " elements" << endl;
				break;
			case 1:
				cout << "Element " << element << " is " << (container->find(element) == NULL ? "found" : "not found") 
					<< " in container" << endl;
				break;
			case 2:
				newElement = new int();
				cout << "Enter element to insert: " << endl;
				cin >> (*newElement);
				container->insert(*newElement);
				cout << "Inserted element " << (*newElement) << endl;
				break;
			case 3:
				newElement = new int();
				cout << "Enter element to insert: " << endl;
				cin >> (*newElement);
				cout << "Enter position to append: " << endl;
				cin >> position;
				container->append(*newElement, position);
				cout << "Appended element " << (*newElement) << "after position " << position << endl;
				break;
			case 4:
				newElement = new int();
				cout << "Enter element to insert: " << endl;
				cin >> (*newElement);
				cout << "Enter position to preppend: " << endl;
				cin >> position;
				container->prepend(*newElement, position);
				cout << "Preppended element " << (*newElement) << "before position " << position << endl;
				break;
			case 5:
				cout << "Enter element to remove: " << endl;
				cin >> element;
				cout << "Element " << element
					<< (container->remove(element) != NULL ? " was removed" : " was not found") << endl;
				break;			
			case 6:
				cout << "Enter element to remove and delete: " << endl;
				cin >> element;
				container->removeAndDelete(element);
				cout << "Element " << element << " was removed and deleted" << endl;
				break;
			case 7:
				container->removeAll();
				cout << "All elements on container were removed" << endl;
				break;			
			case 8:
				container->removeAndDeleteAll();
				cout << "All elements on container were removed and deleted" << endl;
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
						
						default:
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
