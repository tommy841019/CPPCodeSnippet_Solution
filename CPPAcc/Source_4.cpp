//  Organizing programs and data
//  functions and data structures
//  call by value

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <string>
#include <iomanip>  // <> is used to include system header
#include "grade.h"  // "" is used to include user defined header file
#include "Student_info.h"

using std::istream;
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::streamsize;
using std::setprecision;
using std::max;


/* Moved to Student_info.cpp
struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
};  //  ; is required



istream& read_hw(istream& in, vector<double>& hw)
{
	if (in)
	{
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}

	return in;
}



istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}



bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}
*/


/* Moved to median.cpp
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("empty vec");

	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
*/



/* Moved to grade.cpp
double grade(double midterm, double final, double homework)
{
	return 0.2*midterm + 0.4*final + 0.4*homework;
}



double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("empty vec");

	return grade(midterm, final, median(hw));
}



double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}
*/



int Source_4_AllClass()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;  // has to be string::size_type inorder to compare with string.size() in max(), cannot be int

	while (read(cin, record))
	{
		maxlen = max(record.name.size(), maxlen);  // both are string::size() type
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);  // compare() is predicate to help sort on Student_info struct

	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i)
	{
		cout << students[i].name
			<< string(maxlen - students[i].name.size() + 1, ' ');

		try
		{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3)
				<< final_grade
				<< setprecision(prec);
		}
		catch (domain_error e)
		{
			cout << e.what();  // exception details
		}

		cout << endl;
	}

	return 0;
}



int source_4()
{
	cout << "input name:";
	string name;
	cin >> name;

	cout << "Hi! " << name << endl;

	cout << "input midterm and final: ";
	double midterm, final;
	cin >> midterm >> final;

	cout << "input homework: ";

	vector<double> homework;
	read_hw(cin, homework);

	try
	{
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "grade is: " << setprecision(3) << final_grade << setprecision(prec) << endl;
	}
	catch (domain_error)
	{
		cout << endl << "empty grades";
		return 1;
	}

	return 0;
}