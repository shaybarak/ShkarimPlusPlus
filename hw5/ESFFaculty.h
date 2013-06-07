#pragma once

#include "Faculty.h"

class ESFFaculty : public Faculty {
protected:
	// The ESF Faculty passes both tuition and lecture cancellation messages to students
	virtual bool isRelevant(University::MessageType messageType) const;
};
