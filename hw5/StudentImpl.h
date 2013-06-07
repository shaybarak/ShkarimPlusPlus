#pragma once

#include "Student.h"
#include <string>

using namespace std;

class StudentFactory;
class Faculty;

class StudentImpl {
public:
	void announceUpdate(const string& name) const;
};
