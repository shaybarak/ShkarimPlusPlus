#include "ESFFaculty.h"
#include "University.h"

bool ESFFaculty::isRelevant(University::MessageType messageType) const {
	// Pass these types of messages to the students
	return messageType == University::MessageType.TUITION ||
		   messageType == University::MessageType.LECTURE_CANCELLED;
}
