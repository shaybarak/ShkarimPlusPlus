#pragma once

#include "Student.h"
#include <string>

using namespace std;

class StudentFactory;

class StudentImpl {
public:
	StudentImpl(const string& name) : name(name) {};
	void announceUpdate(const string& name) const;

private:
	const string& name;
};
