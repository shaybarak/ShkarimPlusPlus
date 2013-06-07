#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer {
public:
	virtual			~Observer() {}
	virtual void	Update(Subject* ChngSubject) = 0;
protected:
	Observer() {}
	Subject* sbj;
};

#endif
