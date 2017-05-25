//  Organizing programs and data
//  functions and data structures
//  call by value

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <string>
#include <iomanip>

using std::istream;
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::streamsize;
using std::setprecision;



struct Student_inifo {
	string name;
	double midterm, final;
	vector<double> homework;
};  //  ; is required



istream& read(istream& is, Student_inifo& s)
{
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
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



double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("empty vec");

	return grade(midterm, final, median(hw));
}



double grade(double midterm, double final, double homework)
{
	return 0.2*midterm + 0.4*final + 0.4*homework;
}