#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <string>
#include <vector>
#include <iostream>

// structure should be defined in header file
struct Student_info {
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};  // ; is required


// function could be marked as inline in header file, to improve performance
bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif