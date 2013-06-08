#pragma once

#include "Faculty.h"

class FacultyFactory {
public:
	static Faculty* create(University::FacultyType type);

private:
	~FacultyFactory();
	FacultyFactory();
};