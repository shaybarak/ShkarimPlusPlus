#pragma once

#include "Faculty.h"

class FacultyFactory {
public:
	static Faculty* create(University* university, University::FacultyType type);

private:
	~FacultyFactory();
	FacultyFactory();
};