#ifndef MEMPAGE_T
#define MEMPAGE_T

class memPage_t {
public:
	
	// Constructs with a given maximum capacity
	memPage_t(unsigned int capacity) :
		capacity(capacity), size(0), store(new char[capacity]), pos(0) {}
	~memPage_t() { delete[] store; }

	// Queries
	unsigned int get_pos() const { return pos; }
	bool is_empty() const { return size == 0; }
	bool is_full() const { return size == capacity; }
	unsigned int get_size() const { return size; }
	unsigned int get_capacity() const { return capacity; }

	// Mutators
	void set_pos(unsigned int new_pos) { pos = new_pos; }  // TODO handle OOB index

	// Access
	void read(void* out, size_t len, unsigned int pos = pos) const;
	void write(void* const in, size_t len, unsigned int pos = pos);

private:
	// Disallow copy constructor
	memPage_t(const memPage_t& that);

	// Max capacity
	unsigned int capacity;
	// Actual size
	unsigned int size;
	// Backing store
	char* store;
	// Cursor
	unsigned int pos;
};

#endif
