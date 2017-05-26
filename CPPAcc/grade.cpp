#include "grade.h"
#include "median.h"
#include "Student_info.h"


using std::vector;
using std::domain_error;



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



double grade(const Student_info& s)  // const type&: ref to a type and no udpate
{
	return grade(s.midterm, s.final, s.homework);
}