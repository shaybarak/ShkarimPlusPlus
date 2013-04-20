#include <iostream>
#include <string>
#include "Container_t.h"
#include "Array_t.h"
#include "Dlist_t.h"

using namespace std;

// Tests Container_t methods
bool Container_t_test(Container_t<int>* container) {
	
}

// Tests specific Array_t methods
bool Array_t_test() {

	//insert 0,5,...,45
	Array_t<int>* intContArray = new Array_t<int>();
	for (int i = 0; i < 10; i++) {
		intContArray->insert(*new int(5 * i));
	}

	//check insertion with subscript operator
	for (int i = 0; i < 10; i++) {
		if (*(*intContArray)[i] != (5*i)) {
			cerr << "Incorrect value on intCountArray[" << i 
				<< "] expected " << 5*i << " got " << *(*intContArray)[i] << endl;
			return false;
		}
	}

	//check "=" operator
	Array_t<int> intContArrayAssigned;
	intContArrayAssigned = *intContArray;
	if (intContArray->count() != intContArrayAssigned.count()) {
		
	}
	for (int i = 0; i < 10; i++) {
		if ((*intContArray)[i] != intContArrayAssigned[i]) {
			cerr << "Incorrect value on intCountArray[" << i 
				<< "] expected " << 5*i << " got " << *(*intContArray)[i] << endl;
			return false;
		}
	}
	return true;
}

// Tests specific Dlist_t methods
bool Dlist_t_test() {
	Dlist_t<int>* dlist = new Dlist_t<int>();
	for (int i = 0; i < 10; i++) {
		dlist->insert(i);
	}

	// Check basic iteration
	if (*dlist->reset() != 0) {
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
	Dlist_t<int>* other = new Dlist_t<int>();
	*other = *dlist;
	if (*(dlist->reset()) != *(other->reset())) {
		cerr << "Reset mismatch in copy!" << endl;
		return false;
	}
	int* cursor;
	while ((cursor = dlist->next()) != NULL) {
		if (*cursor != *(other->next())) {
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
		return 1;
	}
	delete testArray;
	Dlist_t<int>* testDlist = new Dlist_t<int>();
	if (!Container_t_test(testDlist) {
		cerr << "Error in Container_t test for Dlist_t!" << endl;
		return 1;
	}
	delete testDlist;
	if (!Array_t_test()) {
		cerr << "Error in Array_t test!" << endl;
		return 1;
	}
	if (!Dlist_t_test()) {
		cerr << "Error in Dlist_t test!" << endl;
		return 1;
	}
	return 0;
}
