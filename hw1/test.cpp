#include "memPage_t.h"
#include "memPool_t.h"

class MyTestType {
public:
	MyTestType(int int1, int int2, double double1, double double2)
	  : int1(int1), int2(int2), double1(double1), double2(double2) {}

	bool operator== (MyTestType &left, MyTestType &right) {
    return (
    	left.int1 == right.int1 &&
    	left.int2 == right.int2 &&
    	left.double1 == right.double1 &&
    	left.double2 == right.double2);
	}
 
	bool operator!= (MyTestType &left, MyTestType &right) {
    	return !(left == right);
	}

	int int1, int2;
	double double1, double2;
};

bool memPage_t_test() {
	// Validate init
	memPage_t myPage(1024);
	if (myPage.getCapacity() != 1024) {
		printf("Incorrect capacity %d!\n", myPage.getCapacity());
		return false;
	}
	if (myPage.getSize() != 0) {
		printf("Incorrect size %d!\n", myPage.getSize());
		return false;
	}
	if (myPage.getPos() != 0) {
		printf("Incorrect position %d!\n", myPage.getPos());
		return false;
	}

	MyTestType instance1(1, 2, 1.2, 3.4);
	MyTestType instance2(5, 6, 5.6, 7.8);

	// Validate writes
	if (!myPage.write(&instance1, sizeof(instance1))) {
		printf("Write #1 failed!\n");
		return false;
	}
	if (myPage.getPos() != sizeof(instance1)) {
		printf("Incorrect position %d!\n", myPage.getPos());
		return false;
	}
	// Write out of bounds
	if (myPage.write(&instance1, sizeof(instance1), -3)) {
		printf("Write #2 unexpectedly succeeded!\n");
		return false;
	}
	// Write out of bounds
	if (myPage.write(&instance1, sizeof(instance1), sizeof(instance1) + 5)) {
		printf("Write #3 unexpectedly succeeded!\n");
		return false;
	}
	// Overwrite
	if (!myPage.write(&instance2, sizeof(instance2), 0)) {
		printf("Write #4 failed!\n");
		return false;
	}

	// Validate reads
	if (!myPage.read(&instance1, sizeof(instance1), 0)) {
		printf("Read #1 failed!\n");
		return false;
	}
	// Wrote instance2 and read into instance1 so expect equality
	if (instance1 != instance2) {
		printf("Expected equality!\n");
		return false;
	}
	// Read out of bounds
	if (myPage.read(&instance1, sizeof(instance1), -3)) {
		printf("Read #2 unexpectedly succeeded!\n");
		return false;
	}
	// Write out of bounds
	if (myPage.read(&instance1, sizeof(instance1), sizeof(instance1) + 5)) {
		printf("Read #3 unexpectedly succeeded!\n");
		return false;
	}

	return true;
}

bool memPool_t_test() {
	// Validate init
	memPool_t myPool(1024, 4);
	if (myPool.getCapacity() != 1024 * 4) {
		printf("Incorrect capacity %d!\n", myPool.getCapacity());
		return false;
	}
	if (myPool.getSize() != 0) {
		printf("Incorrect size %d!\n", myPool.getSize());
		return false;
	}
	if (myPool.getPos() != 0) {
		printf("Incorrect position %d!\n", myPool.getPos());
		return false;
	}

	MyTestType instance1(1, 2, 1.2, 3.4);
	MyTestType instance2(5, 6, 5.6, 7.8);

	// Validate writes
	if (!myPool.write(&instance1, sizeof(instance1))) {
		printf("Write #1 failed!\n");
		return false;
	}
	if (myPool.getPos() != sizeof(instance1)) {
		printf("Incorrect position %d!\n", myPool.getPos());
		return false;
	}
	// Write out of bounds
	if (myPool.write(&instance1, sizeof(instance1), -3)) {
		printf("Write #2 unexpectedly succeeded!\n");
		return false;
	}
	// Write out of bounds
	if (myPool.write(&instance1, sizeof(instance1), sizeof(instance1) + 5)) {
		printf("Write #3 unexpectedly succeeded!\n");
		return false;
	}
	// Overwrite
	if (!myPool.write(&instance2, sizeof(instance2), 0)) {
		printf("Write #4 failed!\n");
		return false;
	}

	// Validate reads
	if (!myPool.read(&instance1, sizeof(instance1), 0)) {
		printf("Read #1 failed!\n");
		return false;
	}
	// Wrote instance2 and read into instance1 so expect equality
	if (instance1 != instance2) {
		printf("Expected equality!\n");
		return false;
	}
	// Read out of bounds
	if (myPool.read(&instance1, sizeof(instance1), -3)) {
		printf("Read #2 unexpectedly succeeded!\n");
		return false;
	}
	// Write out of bounds
	if (myPool.read(&instance1, sizeof(instance1), sizeof(instance1) + 5)) {
		printf("Read #3 unexpectedly succeeded!\n");
		return false;
	}

	// Write across pages
	while (myPool.getPos() < 1200) {
		if (!myPool.write(&instance1, sizeof(instance1))) {
			printf("Looped write failed at pos=%d!\n", myPool.getPos());
			return false;
		}
	}

	// Write and read objects that span page boundaries
	if (!myPool.setPos(1023)) {
		printf("Setting position #1 failed!\n");
		return false;
	}
	if (!myPool.write(&instance1, sizeof(instance1))) {
		printf("Write across page bounaries failed at pos=%d\n", myPool.getPos());
		return false;
	}
	if (!myPool.setPos(1023)) {
		printf("Setting position #2 failed!\n");
		return false;
	}
	if (!myPool.read(&instance2, sizeof(instance2))) {
		printf("Read across page bounaries failed at pos=%d\n", myPool.getPos());
		return false;
	}
	if (instance1 != instance2) {
		printf("Expected equality!\n");
		return false;
	}

	return true;
}

int main() {
	if (!memPage_t_test()) {
		return 1;
	}
	if (!memPool_t_test()) {
		return 1;
	}
	return 0;
}
