#include "memPage_t.h"
#include "memPool_t.h"

class MyTestType {
public:
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
	memPage_t myPage(1024);
}

bool memPool_t_test() {
	memPool_t myPool(1024);
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
