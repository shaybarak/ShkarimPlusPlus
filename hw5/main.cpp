#include "University.h"
#include "Faculty.h"
#include "FacultyFactory.h"
#include "Student.h"
#include <iostream>

static const unsigned int DEFAULT_TUITION = 10000;
University University::instance(DEFAULT_TUITION);

int main() {

	bool cont = true;
	unsigned int choice;
	unsigned int newTuition;
	string name;
	Student* newStudent;

	University& university = University::getInstance();
	Faculty* fOHFaculty = FacultyFactory::create(&university, University::FOH);
	Faculty* eSFFaculty = FacultyFactory::create(&university, University::ESF);
	
	cout << "Welcome to university faculty messages management administration student system" << endl;
	cout << "Choose what you want to do" << endl;
	
	while (cont) {
		cout << " 0: Add FOH Student"				<< endl
			 << " 1: Add ESF Student"				<< endl
			 << " 2: Cancel ESF tommorrow lectures"	<< endl
			 << " 3: Change Tuition"				<< endl
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
				case 1:
					cout << "Name: ";
					cin.ignore();
					getline(cin, name);
					newStudent = new Student(name, eSFFaculty);
					cout << "Student created" << endl;
					break;				
				case 2:
					cout << "Canceling tommorow ESF lecture" << endl;
					university.cancelTomorrowsLecture();

				case 3:
					cout << "New tuition: " << endl;
					cin >> newTuition;
					university.changeTuition(newTuition);
					break;
				
				default:
					cont = false;
			}
		} catch (char* message) {
			cerr << "Error: " << message << endl;
		}
	}



}
