#ifndef MEMPAGE_T
#define MEMPAGE_T

class memPage_t {
public:
	
	// Constructs with a given maximum capacity
	memPage_t(size_t capacity) :
		capacity(capacity), size(0), store(new char[capacity]), pos(0) {}
	~memPage_t() { delete[] store; }

	// Queries
	unsigned int getPos() const { return pos; }
	size_t getSize() const { return size; }
	size_t getCapacity() const { return capacity; }
	bool isEmpty() const { return getSize() == 0; }
	bool isFull() const { return getSize() == getCapacity(); }

	// Mutators
	bool setPos(size_t newPos);

	// Access
	bool read(void* out, size_t len) { return read(out, len, pos); }
	bool read(void* out, size_t len, size_t pos);
	
	bool write(const void* const in, size_t len) { return write(in, len, pos); }
	bool write(const void* const in, size_t len, size_t pos);
	

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
