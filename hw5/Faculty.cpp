#include "Faculty.h"
#include "University.h"

Faculty::Faculty() {
	University::getInstance().attach(this);
}

University::MessageType Faculty::getLastChangeType() const {
	return University::getInstance().getLastChangeType();
}

unsigned int Faculty::getTuition() const {
	return University::getInstance().getTuition();
}
