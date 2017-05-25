#include <iostream>
#include <string>

using std::cin;  // using for compact
using std::cout;
using std::endl;
using std::string;

int source_2()
{
	cout << "input name:";

	string name;
	cin >> name;

	const string greeting = "hi " + name + "!";

	const int pad = 4;

	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 3;  // string::size_type unsigned type for string size

	cout << endl;

	for(int r = 0; r != rows; ++r)
	{
		string::size_type c = 0;

		while(c != cols)
		{
			if(r == pad + 1 && c == pad + 1)
			{
				cout << greeting;
				c += greeting.size();  // compond assignment
			}
			else
			{
				if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";

				++c;
			}		
		}

		cout << endl;
		
	}

	return 0;
}