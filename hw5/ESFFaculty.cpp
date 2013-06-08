#include "ESFFaculty.h"
#include "University.h"

bool ESFFaculty::isRelevant(University::MessageType messageType) const {
	// Pass these types of messages to the students
	return messageType == University::TUITION ||
		   messageType == University::LECTURE_CANCELLED;
}

University::FacultyType ESFFaculty::getType() const {
	return University::ESF;
}
