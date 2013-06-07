#include "FOHFaculty.h"
#include "University.h"

bool FOHFaculty::isRelevant(University::MessageType messageType) const {
	// Pass these types of messages to the students
	return messageType == University::TUITION;
}
