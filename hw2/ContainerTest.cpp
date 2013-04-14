#include <iostream>
#include <string>
#include "Container_t.h"
#include "Array_t.h"
#include "Dlist_t.h"

using namespace std;

bool Array_t_test() {
	Array_t<int>* intContArray = new Array_t<int>();
	for (int i = 0; i < 10; i++) {
		intContArray->insert(*new int(5 * i));
	}
	for (int i = 0; i < 10; i++) {
		if (*intContArray[i] != (5*i)) {
			cerr << "Incorrect value on intCountArray[" << i 
				<< "] expected " << 5*i << " got " << *intContArray[i] << endl;
			return false;
		}
	}
}

int main() {
	if (!memPage_t_test()) {
		cerr << "Error in memPage_t test!" << endl;
		return 1;
	}
}
