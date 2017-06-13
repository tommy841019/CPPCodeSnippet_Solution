// compiler synthesizes default recursive version of default operations: copy constructor, assignment operator, destructor
// alwasy give a default constructor

// rule of three: copy constructor, destructor, assignment operator
// T::T();
// rule of three
// T::~T();
// T::T(const T&);
// T::operator=(const T&);

#include <memory> // for allocator<T> memory management



template <class T> class Vec {  // define a template class, take a single type parameter

public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

	// copy constructor
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	Vec() { create(); }
	explicit Vec(size_type n, const T& val = T()) { create(n, val); }  // explicit: this constructor has to be called explicitly

	~Vec() { uncreate(); }

	size_type size() const { return limit - data; }  //  limit - data returns ptrdiff_t type, is converted to size_type or size_t

	// handle indexing
	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }  // return a const T& to ensure read-only, ok to overload on const

	// handle assignment
	// assignment vs initialization
	// assignment: call = operator, delete old value, assign new value
	// initialization: call constructor, create new object
	Vec& operator=(const Vec& v);

	iterator begin() { return data; }
	const_iterator begin() { return data; }

	iterator end() { return limit; }
	const_iterator end() { return limit; }

	void push_back(const T& val) {
		if (avail == limit)
			grow();
		unchecked_append(val);
	}

private:
	iterator data;
	iterator avail;
	iterator limit;

	allocator<T> alloc;

	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	void uncreate();
	void grow();
	void unchecked_append(const T&);
};


// defining a template member function
template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
	// handle self assignment
	if (&rhs != this) {  // this is referencing the object the member function is operating on
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}



template <class T> void Vec<T>::create() {
	data = avail = limit = 0;
}


template <class T> void Vec<T>::create(size_type )