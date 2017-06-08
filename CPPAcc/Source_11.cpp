template <class T> class Vec {  // define a template class, take a single type parameter

public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;

	Vec() { create(); }
	explicit Vec(size_type n, const T& val = T()) { create(n, val); }  // explicit: this constructor has to be called explicitly

	size_type size() const { return limit - data; }  //  limit - data returns ptrdiff_t type, is converted to size_type or size_t
	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }

private:
	T* data;
	T* limit;

};