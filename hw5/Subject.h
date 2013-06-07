#pragma once

#include <vector>

class Observer;

using namespace std;

class Subject {
public:
	virtual ~Subject() {};

	virtual void attach(Observer*);
	virtual void detach(Observer*);
	virtual void notify();
protected:
	Subject() {}
private:
	vector<Observer*> m_observers; 
};
