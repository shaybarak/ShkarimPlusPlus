#pragma once

template <class T> class Dlist_t : public Container_t<T> {
public:

	Dlist_t() : Container_t(), head(null), tail(null) {}

	Dlist_t(const Dlist_t<T>& rhs) {
		operator=(rhs);
	}

	~Array_t() { removeAll(); }

	Dlist_t<T>& operator=(Dlist_t<T>& rhs) {
		removeAll();
		node* cursor = rhs.head;
		// Copy all elements
		while (cursor != null) {
			insert(cursor->element);
			cursor = cursor->next;
		}
		return *this;
	}

	virtual T* find(const T& element) const {
		return findNode(element)->element;
	}
	
	virtual void insert(const T& element) {
		if (head == null) {
			// List is empty, need to initialize first
			head = new node;
			head->element = element;
			head->next = head->prev = null;
			tail = head;
		} else {
			node* newNode = new node;
			newNode->element = element;
			newNode->prev = tail;
			newNode->next = null;
			tail->next = newNode;
			tail = newNode;
		}
	}

	virtual void append(const T& element, size_t index) {
		if (index >= size) {
			// TODO exception
		}
	}

	virtual void prepend(const T& element, size_t index) {
		if (index >= size) {
			// TODO exception
		}
	}

	virtual T* remove(const T& element) {
		// Find
		node* cursor = findNode(element);
		if (cursor == null) {
			return null;
		}
		// Update head or tail if necessary
		if (head == cursor) {
			head = cursor->next;
		}
		if (tail == cursor) {
			tail = cursor->prev;
		}
		// Unlink and delete
		if (cursor->prev != null) {
			cursor->prev->next = cursor;
		}
		if (cursor->next != null) {
			cursor->next->prev = cursor;
		}
		T* found = cursor->element;
		delete cursor;
		size -= 1;
		return found;
	}

	virtual void removeAll() {
		while (head != null) {
			node* next = head->next;
			delete head;
			head = next;
		}
		head = tail = null;
		size = 0;
	}

	virtual void removeAndDeleteAll() {
		while (head != null) {
			node* next = head->next;
			delete head->element;
			delete head;
			head = next;
		}
		head = tail = null;
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
		while (cursor != null) {
			if (*cursor->element == element) {
				return cursor;
			}
		}
		return null;
	}

	node* head;
	node* tail;
};
