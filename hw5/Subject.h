#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

using namespace std;

class Subject {
public:
	virtual ~Subject() {};

	virtual void Attach(Observer*);
	virtual void Detach(Observer*);
	virtual void Notify();
protected:
	Subject() {}
private:
	vector<Observer*> m_observers; 
};

#endif
