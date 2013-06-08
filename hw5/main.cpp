#include "University.h"
#include "Faculty.h"
#include "FacultyFactory.h"
#include "Student.h"
#include <iostream>

static const unsigned int DEFAULT_TUITION = 10000;
University University::instance(DEFAULT_TUITION);

int main() {
	//flow:
	//1. get university singletone
	//2. Create faculties.
	//3. Create students, with the correct faculties. 
	//	StudentsImpl will be created using StudentImplFactory called in constructor of Student. The type will be derived from the faculty.
	//	This is good, since cannot register student to faculty whom it's type does not exist.
	
	bool cont = false;
	unsigned int choice;
	string name;
	Student* newStudent;

	//initiate world
	University& university = University::getInstance();
	Faculty* fOHFaculty = FacultyFactory::create(University::FOH);
	Faculty* eSFFaculty = FacultyFactory::create(University::ESF);
	
	cout << "Welcome to university faculty messages management administration student system" << endl;
	cout << "Choose what you want to do" << endl;
	
	while (cont) {
		cout << " 0: Add FOH Student"				<< endl
			 << " 1: Add ESF Studenty"				<< endl
			 << " 2: Cancel ESF tommorrow lectures"	<< endl
			 << " 3: Chenge Tuition"				<< endl
			 << "Enter your choice: ";
		cin >> choice;
		
		try {
			switch (choice) {
				case 0:
					cout << "Name: ";
					cin.ignore();
					getline(cin, name);
					newStudent = new Student(name, fOHFaculty);
					cout << "Student created" << endl;
					break;				
				
				default:
					cont = false;
			}
		} catch (char* message) {
			cerr << "Error: " << message << endl;
		}
	}



}
