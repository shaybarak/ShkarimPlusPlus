#pragma once

#include "Faculty.h"

class FacultyFactory {
public:
	enum FacultyType {
		FOH,
		ESF,
	};

	static Faculty* create(FacultyType type);

private:
	~FacultyFactory();
	FacultyFactory();
};