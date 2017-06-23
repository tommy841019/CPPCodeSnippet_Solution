/*

Item 1: View C++ as a federation of languages.
	Four parts: C, Object-Oriented C++, Template C++, The STL
	Rules for effective C++ programming vary, depending on the part of C++ you are using.

Item 2: Prefer consts, enums, and inlines to #defines.
	For simple constants, prefer const objects or enums to #defines.
	For function-like macros, prefer inline functions to #defines.

Item 3: Use const whenever possible.
	char greeting[] = "Hello";			
	char *p = greeting;					// non-const pointer, non-const data
	
	const char *p = greeting;			// non-const pointer, const data
	char * const p = greeting;			// const pointer, non-const data
	const char * const p = greeting;	// const pointer, const data

	If the word const appears to the left of the asterisk, what’s pointed to is constant; 
	if the word const appears to the right of the asterisk, the pointer itself is constant;
	if const appears on both sides, both are constant

	const Member Functions
	identify which member functions may be invoked on const objects

*/