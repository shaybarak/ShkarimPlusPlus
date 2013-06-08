#pragma once

#include "Student.h"
#include <string>

using namespace std;

class Faculty;
class StudentFactory;

class StudentImpl {
public:
	StudentImpl(const string& name) : name(name) {};
	void announceUpdate(Faculty* faculty) const;

protected:
	const string name;
};
