#include "Student_info.h"
#include "grade.h"
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>



using std::vector;
using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;



bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}



// require extra space
vector<Student_info> extract_fails(vector<Student_info>& students)  // no const, can update
{
	vector<Student_info> pass, fail;

	for (vector<Student_info>::size_type i = 0; i!= students.size(); ++i)
	{
		if (fgrade(students[i]))
			fail.push_back(students[i]);
		else
			pass.push_back(students[i]);

		students = pass;
		return fail;
	}
}



// slow because element shifting after erase
vector<Student_info> extract_fail_inplace(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::size_type i = 0;

	while (i != students.size())  // need to read size every time 
	{
		if (fgrade(students[i]))
		{
			fail.push_back(students[i]);
			students.erase(students.begin() + i);
		}
		else
			i++;
	}

	return fail;
}



// container-type::const_iterator
// container-type::interator
// * dereference operator:  (*iter).name is same as iter->name
vector<Student_info> extract_fail_iterator(vector<Student_info>& student)
{
	vector<Student_info> fail;

	for (vector<Student_info>::iterator iter = student.begin(); iter != student.end(); ++iter)
	{
		if (fgrade(*iter))
		{
			fail.push_back(*iter);
			iter = student.erase(iter);  // positioned on the following element
		}
	}

	return fail;
}



// erase in a list will NOT invalidate other iterators, vector DOES
// use sort of list for better performance
list<Student_info> extract_fail_iterator(list<Student_info>& student)
{
	list<Student_info> fail;

	for (list<Student_info>::iterator iter = student.begin(); iter != student.end(); ++iter)
	{
		if (fgrade(*iter))
		{
			fail.push_back(*iter);
			iter = student.erase(iter);  // positioned on the following element
		}
	}

	return fail;
}



vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size())
	{
		while (i != s.size() && isspace(s[i]))  // from <cctype>
			++i;

		string_size j = i;

		while (j != s.size() && isspace(s[j]))
		{
			++j;

			if (i != j)
			{
				ret.push_back(s.substr(i, j-i));
				i = j;
			}
		}
	}

	return ret;
}



int split_test()
{
	string s;

	while (getline(cin, s)) 
	{
		vector<string> v = split(s);

		for (vector<string>::size_type i = 0; i != v.size(); ++i)
		{
			cout << v[i] << endl;
		}
	}

	return 0;
}



string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i)
	{
		maxlen = max(maxlen, v[i].size());
	}

	return maxlen;
}



vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen+4, '*');

	ret.push_back(border);

	for (vector<string>::size_type i = 0; i != v.size(); ++i)
	{
		ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
	}

	ret.push_back(border);
	return ret;
}



vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
	vector<string> ret = top;

	/*
	for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
	{
		ret.push_back((*it));
	}
	*/

	ret.insert(ret.end(), bottom.begin(), bottom.end());  // same as loop above

	return ret;
}



int source_5()
{


	return 0;
}