#ifndef MEMPAGE_T
#define MEMPAGE_T

class memPage_t {
public:
	
	// Constructs with a given maximum capacity
	memPage_t(size_t capacity) :
		capacity(capacity), size(0), store(new char[capacity]), pos(0) {}
	~memPage_t() { delete[] store; }

	// Queries
	unsigned int get_pos() const { return pos; }
	size_t get_size() const { return size; }
	size_t get_capacity() const { return capacity; }
	bool is_empty() const { return get_size() == 0; }
	bool is_full() const { return get_size() == get_capacity(); }
	
	// Mutators
	void set_pos(unsigned int new_pos) { pos = new_pos; }  // TODO handle OOB index

	// Access
	void read(void* out, size_t len, size_t pos = pos) const;
	void write(void* const in, size_t len, size_t pos = pos);

private:

	// Disallow copy constructor
	memPage_t(const memPage_t& that);

	// Max capacity
	size_t capacity;
	// Actual size
	size_t size;
	// Backing store
	char* store;
	// Cursor
	size_t pos;
};

#endif
