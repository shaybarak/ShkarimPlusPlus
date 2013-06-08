#include "FacultyFactory.h"
#include "FOHFaculty.h"
#include "ESFFaculty.h"

Faculty* FacultyFactory::create(University::FacultyType type) {
	Faculty* faculty = NULL;
	switch (type) {
	case University::FOH:
		faculty = new FOHFaculty();
	case University::ESF:
		faculty = new ESFFaculty();
	}
	return faculty;
}