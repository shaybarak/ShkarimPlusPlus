#pragma once

#include <string>

using namespace std;

class StudentImpl;
class Faculty;

class StudentImplFactory {
public:
	static StudentImpl* create(const string& name, const Faculty& faculty);

private:
	// Disallow instantiation and copying
	StudentImplFactory();
	StudentImplFactory(const StudentImplFactory&);
	StudentImplFactory& operator=(const StudentImplFactory&);
};
