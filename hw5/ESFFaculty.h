#pragma once

#include "Faculty.h"

class ESFFaculty : public Faculty {
protected:
	// The ESF Faculty passes both tuition and lecture cancellation messages to students
	bool isRelevant(University::MessageType messageType) const;
};
