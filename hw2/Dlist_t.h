#ifndef DLIST_T_H
#define DLIST_T_H

#include <stdio.h>
#include <stdlib.h>
#include "Container_t.h"

template <class T>
class Dlist_t : protected Container_t<T> {
public:

	Dlist_t() : Container_t<T>(), head(NULL), tail(NULL), cursor(NULL) {}

	Dlist_t(const Dlist_t<T>& rhs) {
		operator=(rhs);
	}

	~Dlist_t() { removeAll(); }

	Dlist_t<T>& operator=(Dlist_t<T>& rhs) {
		removeAll();
		node* cursor = rhs.head;
		// Copy all elements
		while (cursor != NULL) {
			insert(cursor->element);
			cursor = cursor->next;
		}
		size = rhs.size;
		reset();
		return *this;
	}

	virtual T* find(const T& element) const {
		return findNode(element)->element;
	}
	
	virtual void insert(const T& element) {
		if (head == NULL) {
			// List is empty, need to initialize first
			head = new node;
			head->element = element;
			head->next = head->prev = NULL;
			tail = head;
		} else {
			node* newNode = new node;
			newNode->element = element;
			newNode->prev = tail;
			newNode->next = NULL;
			tail->next = newNode;
			tail = newNode;
		}
		size++;
		reset();
	}

	virtual void append(const T& element, size_t index) {
		if (index >= size) {
			throw "Index out of bounds!";
		}
		// Seek node by index
		node* cursor = head;
		for (int i = 1; i < index; i++) {
			cursor = cursor->next;
		}
		// Append
		node* newNode = new node;
		newNode->element = element;
		newNode->prev = cursor;
		newNode->next = cursor->next;
		newNode->prev->next = newNode;
		if (newNode->next == NULL) {
			// New tail
			tail = newNode;
		} else {
			newNode->next->prev = newNode;
		}
		size++;
		reset();
	}

	virtual void prepend(const T& element, size_t index) {
		if (index >= size) {
			throw "Index out of bounds!";
		}
		// Seek node by index
		node* cursor = head;
		for (int i = 1; i < index; i++) {
			cursor = cursor->next;
		}
		// Prepend
		node* newNode = new node;
		newNode->element = element;
		newNode->next = cursor;
		newNode->prev = cursor->prev;
		newNode->next->prev = newNode;
		if (newNode->prev == NULL) {
			// New head
			head = newNode;
		} else {
			newNode->prev->next = newNode;
		}
		size++;
		reset();
	}

	virtual T* remove(const T& element) {
		// Find
		node* found = findNode(element);
		if (found == NULL) {
			return NULL;
		}
		// Update head or tail if necessary
		if (head == found) {
			head = found->next;
		}
		if (tail == found) {
			tail = found->prev;
		}
		// Unlink and delete
		if (found->prev != NULL) {
			found->prev->next = found;
		}
		if (found->next != NULL) {
			found->next->prev = found;
		}
		T* toReturn = found->element;
		delete found;
		size--;
		reset();
		return toReturn;
	}

	virtual void removeAll() {
		while (head != NULL) {
			node* next = head->next;
			delete head;
			head = next;
		}
		head = tail = NULL;
		size = 0;
		reset();
	}

	virtual void removeAndDeleteAll() {
		while (head != NULL) {
			node* next = head->next;
			delete head->element;
			delete head;
			head = next;
		}
		head = tail = NULL;
		size = 0;
		reset();
	}

	T* reset() {
		cursor = head;
		return cursor == NULL ? NULL : cursor->element;
	}

	T* next() {
		if (cursor == NULL) {
			throw "Iterator out of bounds!";
		}
		cursor = cursor->next;
		return cursor == NULL ? NULL : cursor->element;
	}

	T* prev() {
		if (cursor == NULL) {
			throw "Iterator out of bounds!";
		}
		cursor = cursor->prev;
		return cursor == NULL ? NULL : cursor->element;
	}

private:
	typedef struct node {
		T* element;
		struct node* prev;
		struct node* next;
	} node;

	node* findNode(const T& element) {
		T* toCompare;
		reset();
		while ((toCompare = next()) != NULL) {
			if (*toCompare == element) {
				return toCompare;
			}
		}
		return NULL;
	}

	node* head;
	node* tail;
	node* cursor;
};

#endif
