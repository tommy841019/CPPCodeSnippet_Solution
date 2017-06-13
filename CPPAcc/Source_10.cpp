#include <iostream>
#include <vector>
#include <cstring>  // for strlen()
#include <string>



int next(int n)
{
	return n + 1;
}

// function returns a pointer to function
typedef int(*pnext)(int n); // define a pointer type of next() 
pnext get_next_ptr() {};  // this fundtion return a pointer to next()

// Default parameters won’t work for functions called through function pointers
// Default parameters are resolved at compile-time



std::string letter_grade(double grade)
{
	static const double numbers[] = {75, 50, 25, 0};
	static const char* const letters[] = {"A", "B", "C", "F"};
	static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

	for (size_t i = 0; i < ngrades; ++i)
	{
		if (grade >= numbers[i])
			return letters[i];
	}
	return "?\?\?";
}



// int main(int argc, char** argv)   argc:number of pointers in argv    argv: an array of char pointers



int* get_int(int n)  // return a pointer to an int object, caller need to free the memory
{
	return new int(n);
}



int source_10()
{
	// & * address operator
	int x;
	int *q = &x;  //  *q is type of int
	int* p = &x;  //  p is type of int*

	int(*fp)(int) = &next; // create a function pointer that take int as para and return an int
	int(*fp)(int) = next;  //  & is not required when assign pointer to function since only call and get address are valid operations

	int a = (*fp)(2);  // deref a function pointer to call
	int b = fp(3);     // deref is not required since only call and get address are valid operations

	// Arrays
	double coords[3];  // define an arry of double containing 3 elements
	*coords = 1.5;  // array name is a pointer to the 1st element in array

	const size_t NDim = 3;  // use type size_t in <cstddef> when deal with array size
	double coords[NDim];

	std::vector<double> v;
	copy(coords, coords + NDim, back_inserter(v));  // use first and last position of an array as iterator

	std::vector<double> v(coords, coords + NDim);   // directly construct a vector from array

	const int month_lengths[] = { 1,2,3,4,5 };  // initialize an array with values, without size

	// String literal: an array of const char with '\0'(null) at the end
	const char hello[] = {'H','i','\0'};
	std::string hello = "Hi";
	int size = strlen(hello);


	// static allocation, can return &x, it will valid until program exit
	static int x;
	// dynamic allocation using new and delete
	int* p = new int(4);  // new return a pointer to the new object
	delete p;  // delete object pointed by p

	// dynamic allocation of array
	int* q = new int[100];
	delete[] q;  // [] tell compiler to delete entire array, not the 1st element
}



