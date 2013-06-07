#include "Student.h"

Student::Student(const string& name, const string& faculty) {
	studentImpl = StudentFactory.create(name, faculty);
}
