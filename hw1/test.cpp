#include "memPage_t.h"
#include "memPool_t.h"
#include <iostream.h>

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
		cerr << "Incorrect page position after write " << myPage.getPos << "!" << endl;
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
		cerr << "Read page #2 unexpectedly succeeded!" << endl
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

	return true;
}

// Interactive test for memPage_t
void memPool_t_interactive() {

}

int main() {
	if (!memPage_t_test()) {
		printf("Error in memPage_t test!\n");
		return 1;
	}
	if (!memPool_t_test()) {
		printf("Error in memPool_t test!\n");
		return 1;
	}
	memPool_t_interactive();
	return 0;
}
