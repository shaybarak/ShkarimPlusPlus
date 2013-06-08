#include "StudentImpl.h"
#include "University.h"
#include "Faculty.h"
#include <iostream>
#include <assert.h>

using namespace std;

void StudentImpl::announceUpdate(Faculty* faculty) const {
	cout << getTypeStr() << " Student: " << name << " was notified of ";
	switch (faculty->getLastChangeType()) {
	
	case University::TUITION:
		cout << "tuition change to " << faculty->getTuition() << "." << endl;
		break;

	case University::LECTURE_CANCELLED:
		cout << "lecture cancellation." << endl;
		break;

	default:
		assert(false);
		break;
	}
}
