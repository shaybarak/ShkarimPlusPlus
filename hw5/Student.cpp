#include "Student.h"
#include "Faculty.h"

Student::Student(const string& name, Faculty& faculty) {
	impl = StudentImplFactory::create(name, faculty.getType());
}
