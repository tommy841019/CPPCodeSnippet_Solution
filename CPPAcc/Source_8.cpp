#include <vector>
#include <algorithm>

using std::vector;
using std::swap;



template<class T>  // template header, type parameter T
T median(vector<T> v)
{
	typedef typename vector<T>::size_type vec_sz;  // typename: tell vector<T>::size_type is the name of a type

	vec_sz size = v.size();
	if (size == 0)
		throw domain_error("empty");

	sort(v.begin(), v.end());

	vec_sz mid = size / 2;
	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}



// sequential read-only access
template<class In, class X> 
In find(In begin, In end, const X& x)  // In : input iterator
{
	while (begin != end && *begin != x)
		++begin;
	return begin;
}



// recursive
template<class In, class X>
In find(In begin, In end, const X& x)
{
	if (begin == end || *begin == x)
		return begin;
	++begin;
	return find(begin, end, x);
}



// sequential write-only access
template<class In, class Out>
Out copy(In begin, In end, Out dest)  // Out : output iterator
{
	while (begin != end)
		*dest++ = *begin++;
	return dest;
}



// sequential read-write access
template<class For, class X>
void replace(For begin, For end, const X& x, const X& y)  // For : forward iterator
{
	while (begin != end)
	{
		if (*begin == x)
			*begin = y;
		++begin;
	}
}



// reversible access
template<class Bi> void reverse(Bi begin, Bi end)  // Bi : bidirectional iterator
{
	while (begin != end)
	{
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
}



// Random access
template<class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)  // Ran : random-access iterator
{
	while (begin < end)
	{
		Ran mid = begin + (end - begin) / 2;

		if (x < *mid)
			end = mid;
		else if (x > *mid)
			begin = mid;
		else return true;
	}
	return false;
}