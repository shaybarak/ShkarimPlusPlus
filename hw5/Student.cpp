#include "Student.h"
#include "StudentImpl.h"
#include "Faculty.h"

Student::Student(const string& name, Faculty& faculty) {
	impl = StudentImplFactory::create(name, faculty.getType());
}

void Student::update(Subject* subject) {
	impl->announceUpdate();
}
