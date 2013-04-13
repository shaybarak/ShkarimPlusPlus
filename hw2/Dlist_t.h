#pragma once

#include "Container_t.h"
#include <stdio.h>

template <class T> class Dlist_t : public Container_t<T> {
public:

	Dlist_t() : Container_t(), head(NULL), tail(NULL) {}

	Dlist_t(const Dlist_t<T>& rhs) {
		operator=(rhs);
	}

	~Array_t() { removeAll(); }

	Dlist_t<T>& operator=(Dlist_t<T>& rhs) {
		removeAll();
		node* cursor = rhs.head;
		// Copy all elements
		while (cursor != NULL) {
			insert(cursor->element);
			cursor = cursor->next;
		}
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
	}

	virtual void append(const T& element, size_t index) {
		if (index >= size) {
			// TODO exception
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
	}

	virtual void prepend(const T& element, size_t index) {
		if (index >= size) {
			// TODO exception
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
	}

	virtual T* remove(const T& element) {
		// Find
		node* cursor = findNode(element);
		if (cursor == NULL) {
			return NULL;
		}
		// Update head or tail if necessary
		if (head == cursor) {
			head = cursor->next;
		}
		if (tail == cursor) {
			tail = cursor->prev;
		}
		// Unlink and delete
		if (cursor->prev != NULL) {
			cursor->prev->next = cursor;
		}
		if (cursor->next != NULL) {
			cursor->next->prev = cursor;
		}
		T* found = cursor->element;
		delete cursor;
		size -= 1;
		return found;
	}

	virtual void removeAll() {
		while (head != NULL) {
			node* next = head->next;
			delete head;
			head = next;
		}
		head = tail = NULL;
		size = 0;
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
	}

private:
	typedef struct node {
		T* element;
		struct node* prev;
		struct node* next;
	} node;

	private node* findNode(const T& element) {
		node* cursor = head;
		while (cursor != NULL) {
			if (*cursor->element == element) {
				return cursor;
			}
		}
		return NULL;
	}

	node* head;
	node* tail;
};
