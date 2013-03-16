#include "memPage_t.h"
#include "memPool_t.h"

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
