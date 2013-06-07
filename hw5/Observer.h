#pragma once

class Subject;

class Observer {
public:
	virtual			~Observer() {}
	virtual void	update(Subject* subject) = 0;
protected:
	Observer() {}
	Subject* sbj;
};
