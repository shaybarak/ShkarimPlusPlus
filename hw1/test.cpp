#include "memPage_t.h"
#include "memPool_t.h"
#include <iostream>
#include <string>

using namespace std;

// A dumb data type used for testing purposes
class MyTestType {
public:
	MyTestType(int int1, int int2, double double1, double double2)
	  : int1(int1), int2(int2), double1(double1), double2(double2) {}

	bool operator== (MyTestType &right) {
	return (
		int1 == right.int1 &&
		int2 == right.int2 &&
		double1 == right.double1 &&
		double2 == right.double2);
	}
 
	bool operator!= (MyTestType &right) {
		return !(*this == right);
	}

	int int1, int2;
	double double1, double2;
};

// Automatic test for memPage_t
bool memPage_t_test() {
	// Validate init
	memPage_t myPage(1024);
	if (myPage.getCapacity() != 1024) {
		cerr << "Incorrect page capacity " << myPage.getCapacity() << "!" << endl;
		return false;
	}
	if (myPage.getSize() != 0) {
		cerr << "Incorrect page size " << myPage.getSize() << "!" << endl;
		return false;
	}
	if (myPage.getPos() != 0) {
		cerr << "Incorrect page position " << myPage.getPos() << "!" << endl;
		return false;
	}

	MyTestType instance1(1, 2, 1.2, 3.4);
	MyTestType instance2(5, 6, 5.6, 7.8);

	// Validate writes
	if (!myPage.write(&instance1, sizeof(instance1))) {
		cerr << "Write page #1 failed!" << endl;
		return false;
	}
	if (myPage.getPos() != sizeof(instance1)) {
		cerr << "Incorrect page position after write " << myPage.getPos() << "!" << endl;
		return false;
	}
	// Write out of bounds
	if (myPage.write(&instance1, sizeof(instance1), -3)) {
		cerr << "Write page #2 unexpectedly succeeded!" << endl;
		return false;
	}
	// Write out of bounds
	if (myPage.write(&instance1, sizeof(instance1), sizeof(instance1) + 5)) {
		cerr << "Write page #3 unexpectedly succeeded!" << endl;
		return false;
	}
	// Overwrite
	if (!myPage.write(&instance2, sizeof(instance2), 0)) {
		cerr << "Write page #4 failed!" << endl;
		return false;
	}

	// Validate reads
	if (!myPage.read(&instance1, sizeof(instance1), 0)) {
		cerr << "Read page #1 failed!" << endl;
		return false;
	}
	// Wrote instance2 and read into instance1 so expect equality
	if (instance1 != instance2) {
		cerr << "Expected page equality!" << endl;
		return false;
	}
	// Read out of bounds
	if (myPage.read(&instance1, sizeof(instance1), -3)) {
		cerr << "Read page #2 unexpectedly succeeded!" << endl;
		return false;
	}
	// Write out of bounds
	if (myPage.read(&instance1, sizeof(instance1), sizeof(instance1) + 5)) {
		cerr << "Read page #3 unexpectedly succeeded!" << endl;
		return false;
	}

	return true;
}

// Automatic test for memPool_t
bool memPool_t_test() {
	// Validate init
	memPool_t myPool(1024, 4);
	if (myPool.getCapacity() != 1024 * 4) {
		cerr << "Incorrect pool capacity " << myPool.getCapacity() << endl;
		return false;
	}
	if (myPool.getSize() != 0) {
		cerr << "Incorrect pool size " << myPool.getSize() << "!" << endl;
		return false;
	}
	if (myPool.getPos() != 0) {
		cerr << "Incorrect pool position " << myPool.getPos() << "!" << endl;
		return false;
	}

	MyTestType instance1(1, 2, 1.2, 3.4);
	MyTestType instance2(5, 6, 5.6, 7.8);

	// Validate writes
	if (!myPool.write(&instance1, sizeof(instance1))) {
		cerr << "Write pool #1 failed!" << endl;
		return false;
	}
	if (myPool.getPos() != sizeof(instance1)) {
		cerr << "Incorrect pool position " << myPool.getPos() << "!" << endl;
		return false;
	}
	// Write out of bounds
	if (myPool.write(&instance1, sizeof(instance1), -3)) {
		cerr << "Write pool #2 unexpectedly succeeded!" << endl;
		return false;
	}
	// Write out of bounds
	if (myPool.write(&instance1, sizeof(instance1), sizeof(instance1) + 5)) {
		cerr << "Write pool #3 unexpectedly succeeded!" << endl;
		return false;
	}
	// Overwrite
	if (!myPool.write(&instance2, sizeof(instance2), 0)) {
		cerr << "Write pool #4 failed!" << endl;
		return false;
	}

	// Validate reads
	if (!myPool.read(&instance1, sizeof(instance1), 0)) {
		cerr << "Read pool #1 failed!" << endl;
		return false;
	}
	// Wrote instance2 and read into instance1 so expect equality
	if (instance1 != instance2) {
		cerr << "Expected pools equality!" << endl;
		return false;
	}

	// Write out of bounds
	if (myPool.read(&instance1, sizeof(instance1), sizeof(instance1) + 5)) {
		cerr << "Read pool #2 unexpectedly succeeded!" << endl;
		return false;
	}

	// Write across pages
	while (myPool.getPos() < 1200) {
		if (!myPool.write(&instance1, sizeof(instance1))) {
			cerr << "Looped write failed at position " << myPool.getPos() << "!" << endl;
			return false;
		}
	}

	// Write and read objects that span page boundaries
	if (!myPool.setPos(1023)) {
		cerr << "Setting pool position #1 failed!" << endl;
		return false;
	}
	if (!myPool.write(&instance1, sizeof(instance1))) {
		cerr << "Write pool across page bounaries failed at position " << myPool.getPos() << "!" << endl;
		return false;
	}
	if (!myPool.setPos(1023)) {
		cerr << "Setting pool position #2 failed!" << endl;
		return false;
	}
	if (!myPool.read(&instance2, sizeof(instance2))) {
		cerr << "Read pool across page bounaries failed at position " << myPool.getPos() << "!" << endl;
		return false;
	}
	if (instance1 != instance2) {
		cerr << "Expected equality!" << endl;
		return false;
	}

	//write and read from pool with pages of different length
	memPool_t myPoolVar(2, 4);
	MyTestType instance3(11, 12, 11.2, 13.4);
	MyTestType instance4(15, 16, 15.6, 17.8);
	MyTestType instance5(0, 0, 0, 0);
	MyTestType instance6(1, 1, 1, 1);
	//write to pool
	if (!myPoolVar.write(&instance3, sizeof(instance3))) {
		cerr << "Write instance3 to myPoolVar failed!" << endl;
		return false;
	}
	myPoolVar.setNewPageCapacity(23);
	if (!myPoolVar.write(&instance4, sizeof(instance4))) {
		cerr << "Write instance4 to myPoolVar failed!" << endl;
		return false;
	}

	if (myPoolVar.getPageCount() != 14) {
		cerr << "myPoolVar wrong number of pages, expected 14, found " << myPoolVar.getPageCount() << endl;
		return false;
	}

	if (!myPoolVar.setPos(0)) {
		cerr << "Setting myPoolVar position to 0 failed!" << endl;
		return false;
	}
	if (!myPoolVar.read(&instance5, sizeof(instance5))) {
		cerr << "Read #1 from myPoolVar failed!" << endl;
		return false;
	}

	if (!myPoolVar.read(&instance6, sizeof(instance5))) {
		cerr << "Read #2 from myPoolVar failed!" << endl;
		return false;
	}

	if (instance3 != instance5) {
		cerr << "Expected instance3 and instance5 equality!" << endl;
		return false;
	}

	if (instance4 != instance6) {
		cerr << "Expected instance4 and instance6 equality!" << endl;
		return false;
	}


	return true;
}

// Interactive test for memPage_t
bool memPool_t_interactive() {
	cout << "Enter positive capacity for pool pages: ";
	size_t pageCapacity;
	cin >> pageCapacity;
	if (pageCapacity == 0) {
		cerr << "Invalid page capacity!" << endl;
		return false;
	}
	cout << "Enter initial pages count: ";
	size_t initialPageCount;
	cin >> initialPageCount;
	memPool_t pool(pageCapacity, initialPageCount);
	cout << "Initialized pool with current capacity of " << pool.getCapacity() << endl;
	
	cout << "Your input will be written into the pool as a stream of ASCII characters." << endl;
	cout << "Enter your input below, hit ENTER to finish:" << endl;
	string input;
	
	cin.ignore();
	getline(cin, input);
	for (string::iterator it = input.begin(); it != input.end(); it++) {
		if (!pool.write(&(*it), sizeof(char))) {
			cerr << "Error writing to pool!" << endl;
			return false;
		}
	}

	cout << "Your input has been written to the pool." << endl;
	cout << "Reading it back produced the following:" << endl;
	size_t pos = 0;
	if (!pool.setPos(pos)) {
		cerr << "Error setting pool position!" << endl;
	}
	char output;
	while (pos < pool.getSize()) {
		if (!pool.read(&output, sizeof(output))) {
			cerr << "Error reading from pool!" << endl;
		}
		cout << output;
		pos++;
	}
	cout << endl;
	cout << "Your input was of size " << pool.getSize() << " spanning " << pool.getPageCount() << " pages." << endl;
	cout << "Total pool capacity is now " << pool.getCapacity() << endl;
	return true;
}

int main() {
	if (!memPage_t_test()) {
		cerr << "Error in memPage_t test!" << endl;
		return 1;
	}
	cout << "Automatic tests for memPage_t completed successfully." << endl;
	if (!memPool_t_test()) {
		cerr << "Error in memPool_t test!" << endl;
		return 1;
	}
	cout << "Automatic tests for memPool_t completed successfully." << endl;
	if (!memPool_t_interactive()) {
		cerr << "Error in interactive test!" << endl;
		return 1;
	}
	cout << "Interactive test for memPool_t completed successfully." << endl;
	return 0;
}
