#include "StudentImpl.h"
#include "University.h"
#include <iostream>
#include <assert.h>

using namespace std;

void StudentImpl::announceUpdate(const string& name) const {
	cout << name << " was notified of ";
	switch (University::getInstance().getLastChangeType()) {
	
	case University::TUITION:
		cout << "tuition change to " << University::getInstance().getTuition() << "." << endl;
		break;

	case University::LECTURE_CANCELLED:
		cout << "lecture cancellation." << endl;

	default:
		assert(false);
		break;
	}
}
