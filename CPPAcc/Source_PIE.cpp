/*
	The Basic Steps
		1. Make sure you understand the problem
		2. When you understand the question, try a simple example
		3. Focus on the algorithm and data structures you will use to solve the problem
			“I’m wondering whether I can store the values in an array and then sort them, but I don’t think that will work because I can’t quickly look up elements in an array by value.”
		4. After you figure out your algorithm and how you can implement it, explain your solution to the interviewer
		5. While you code, explain what you’re doing
			“Here, I’m initializing the array to all zeroes.”
		6. Ask questions when necessary
			“I can’t remember — what format string do I use to print out a localized date?”
		7. After you write the code for a problem, immediately verify that the code works by tracing through it with an example
		8. Make sure you check your code for all error and special cases, especially boundary conditions
		9. Give Time and Space complexity
			“This implementation has linear running time, which is the best possible because I need to check all the input values. The dynamic memory allocation will slow it down a little, as will the overhead of using recursion.”



	Getting stuck on a problem is expected and an important part of the interviewing process			
		Go back to an example
		Try a different data structure
		Consider the less-commonly used or more-advanced aspects of a language



	Big-O analysis
		input size is assumed to be an unknown value n
		Best case / Average case / Worst case
		Ask the interviewer which scenario he is most interested in
		Procedure:
			1. Figure out what the input is and what n represents
			2. Express the number of operations the algorithm performs in terms of n
			3. Eliminate all but the highest-order terms
			4. Remove all constant factors
		O(1) < O(logn) < O(n) < (O(nlogn)) < O(n^c) < O(c^n) < O(n!)


	
	Linked List
		Singly Linked List - Most frequent in interviews
			// A singly linked list in C++
			class IntElement {
				public:
				IntElement( int value ): next( NULL ), data( value ) {}
				~tElement() {}
				IntElement *getNext() const { return next; }
				int value() const { return data; }
				void setNext( IntElement *elem ) { next = elem; }
				void setValue( int value ) { data = value; }
				private:
				IntElement *next;
				int data;
			};

			// A templated C++ singly linked list
			template <class T>
			class ListElement {
				public:
				ListElement( const T &value ): next( NULL ), data( value ) {}
				~ListElement() {}
				ListElement *getNext() const { return next; }
				const T& value() const { return data; }
				void setNext( ListElement *elem ) { next = elem; }
				void setValue( const T &value ) { data = value; }
				private:
				ListElement *next;
				T data;
			};

			// A templated Java singly linked list
			public class ListElement<T> {
				public ListElement( T value ) { data = value; }
				public ListElement<T> next() { return next; }
				public T value() { return data; }
				public void setNext( ListElement<T> elem ) { next = elem; }
				public void setValue( T value ) { data = value; }
				private ListElement<T> next;
				private T data;
			}

		Doubly Linked Lists - rare
		Circular Linked Lists - rare

		Basic Operations
			Tracking the head element
				Add an element in the front
					// Java
					public ListElement<Integer> insertInFront( ListElement<Integer> list, int data ){
						ListElement<Integer> l = new ListElement<Integer>( data );
						l.setNext( list );
						return l;
					}
					// C
					bool insertInFront( IntElement **head, int data ){
						IntElement *newElem = malloc( sizeof(IntElement) );
						if(!newElem) return false;
						newElem->data = data;
						newElem->next = *head;
						*head = newElem;
						return true;
					}

				Traversing a List: you must always check that you haven’t reached the end of the list

				Inserting and Deleting Elements
					Special care must be taken when the element to be deleted is the head of the list
					Deletion and insertion require a pointer or reference to the element immediately preceding the deletion or insertion location
					Deletion and Insertion of an element always requires at least two pointer variables



*/