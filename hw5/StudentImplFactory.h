#pragma once

#include <string>
#include "University.h"

using namespace std;

class StudentImpl;
class Faculty;

class StudentImplFactory {
public:
	static StudentImpl* create(const string& name, University::FacultyType facultyType);

private:
	// Disallow instantiation and copying
	StudentImplFactory();
	StudentImplFactory(const StudentImplFactory&);
	StudentImplFactory& operator=(const StudentImplFactory&);
};
