#include <ios> // streamsize
#include <iomanip> // setprecision
#include <iostream>
#include <string>
#include <algorithm> // sort(start, end)
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::setprecision;
using std::string;
using std::sort;
using std::vector;


int source_3()
{
	cout << "input name: ";
	string name;
	cin >> name;
	cout << "Hi, " << name << "!" << endl;

	cout << "input midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "input homework grades,"
		"then enter:";
	vector<double> homework;
	double x;
	while(cin >> x)
		homework.push_back(x);  // add element to the end of vector

	typedef vector<double>::size_type vec_sz; // define a synonym
	vec_sz size = homework.size();
	if(size == 0)
	{
		cout << "try again" << endl;
		return 1;
	}
		
	sort(homework.begin(), homework.end());  // part of algorithm

	vec_sz mid = size/2;
	double median = size%2 == 0?(homework[mid]+homework[mid-1])/2 : homework[mid];

	streamsize prec = cout.precision();
	cout << "grade is: " << setprecision(3) << 0.2 * midterm+0.4 * final + 0.4*median << setprecision(prec) << endl;

	return 0;
}

// if signed integer and unsigned in expression, singed integer will be converted to unsigned 