#include <iostream>
#include <string>
#include "Container_t.h"
#include "Array_t.h"
#include "Dlist_t.h"

using namespace std;

// Populate container for test
void populate(Container_t<int>* container) {
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7) {
			continue;
		}
		container->insert(*new int(i));
	}
	container->append(*new int(4), 3);
	container->prepend(*new int(7), 7);
	// Container contents should now be [0..9]
}

// Tests Container_t methods
bool Container_t_test(Container_t<int>* container) {
	populate(container);

	if (container->count() != 10) {
		cerr << "Failed count test!" << endl;
		return false;
	}

	if (*(container->find(7)) != 7) {
		cerr << "Failed find test!" << endl;
		return false;
	}
	int* removed = container->remove(7);
	if (*removed != 7) {
		cerr << "Failed remove test!" << endl;
		return false;
	}
	delete removed;

	if (container->count() != 9) {
		cerr << "Failed count after removal test!" << endl;
		return false;
	}

	return true;
}

// Tests specific Array_t methods
bool Array_t_test(Array_t<int>* arrayT) {

	//insert 0,5,...,45
	for (int i = 0; i < 10; i++) {
		arrayT->insert(*new int(5 * i));
	}

	//check insertion with subscript operator
	for (int i = 0; i < 10; i++) {
		if ((*arrayT)[i] != (5*i)) {
			cerr << "Incorrect value on intCountArray[" << i 
				<< "] expected " << 5*i << " got " << (*arrayT)[i] << endl;
			return false;
		}
	}

	//check "=" operator
	Array_t<int> intContArrayAssigned;
	intContArrayAssigned = *arrayT;
	if (arrayT->count() != intContArrayAssigned.count()) {
		cerr << "Incorrect operator= functionallity! exected count=" << arrayT->count() 
			<< "found count=" << intContArrayAssigned.count();
		return false;
	}
	for (int i = 0; i < 10; i++) {
		if ((*arrayT)[i] != intContArrayAssigned[i]) {
			cerr << "Incorrect operator= functionallity! expected value on intCountArray[" << i 
				<< "] expected " << 5*i << " got " << (*arrayT)[i] << endl;
		}
	}
	
	intContArrayAssigned = *arrayT;
	if (arrayT->count() != intContArrayAssigned.count()) {
			cerr << "Incorrect operator= functionallity! exected count=" << arrayT->count() 
				<< "found count=" << intContArrayAssigned.count();
		return false;

	}
	for (int i = 0; i < 10; i++) {
		if ((*arrayT)[i] != intContArrayAssigned[i]) {
			cerr << "Incorrect value on intCountArray[" << i 
				<< "] expected " << 5*i << " got " << (*arrayT)[i] << endl;
			return false;
		}
	}

	return true;
}

// Tests specific Dlist_t methods
bool Dlist_t_test(Dlist_t<int>* dlist) {
	populate(dlist);

	// Check basic iteration
	if (*(dlist->reset()) != 0) {
		cerr << "Failed iterator reset test!" << endl;
		return false;
	}
	for (int i = 1; i < 10; i++) {
		if (*(dlist->next()) != i) {
			cerr << "Failed forward iteration test!" << endl;
			return false;
		}
	}
	for (int i = 8; i >= 0; i--) {
		if (*(dlist->prev()) != i) {
			cerr << "Failed backward iteration test!" << endl;
			return false;
		}
	}

	// Check that find moves cursor to location of element found
	int* found = dlist->find(5);
	if (*(dlist->next()) != 6) {
		cerr << "Failed iterator after find test!" << endl;
		return false;
	}

	// Check assignment
	Dlist_t<int> other;
	other = *dlist;
	if (*(dlist->reset()) != *(other.reset())) {
		cerr << "Reset mismatch in copy!" << endl;
		return false;
	}
	int* cursor;
	while ((cursor = dlist->next()) != NULL) {
		if (*cursor != *(other.next())) {
			cerr << "Mismatch in iteration over copy!" << endl;
			return false;
		}
	}

	return true;
}

int main() {
	Array_t<int>* testArray = new Array_t<int>();
	if (!Container_t_test(testArray)) {
		cerr << "Error in Container_t test for Array_t!" << endl;
		testArray->removeAndDeleteAll();
		delete testArray;
		return 1;
	}
	testArray->removeAndDeleteAll();
	delete testArray;

	Dlist_t<int>* testDlist = new Dlist_t<int>();
	if (!Container_t_test(testDlist)) {
		cerr << "Error in Container_t test for Dlist_t!" << endl;
		testDlist->removeAndDeleteAll();
		delete testDlist;
		return 1;
	}
	testDlist->removeAndDeleteAll();
	delete testDlist;

	testArray = new Array_t<int>();
	if (!Array_t_test(testArray)) {
		cerr << "Error in Array_t test!" << endl;
		testArray->removeAndDeleteAll();
		delete testArray;
		return 1;
	}
	testArray->removeAndDeleteAll();
	delete testArray;

	testDlist = new Dlist_t<int>();
	if (!Dlist_t_test(testDlist)) {
		cerr << "Error in Dlist_t test!" << endl;
		return 1;
		testDlist->removeAndDeleteAll();
		delete testDlist;
	}
	testDlist->removeAndDeleteAll();
	delete testDlist;
	
	return 0;
}
