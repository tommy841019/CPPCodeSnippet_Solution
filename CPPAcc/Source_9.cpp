#include <string>
#include <vector>
#include <iostream>



struct Student_info 
{
	std::string name;
	double midterm, final;
	std::vector<double> homework;

	std::istream& read(std::istream&);
	double grade() const;  // const means not change any of the data when call grade()
};



void read_hw(std::istream& in, std::vector<double> homework) {}



std::istream& Student_info::read(std::istream& in)  //  defining a function as a member of Student_info
{
	in >> name >> midterm >> final;
	read_hw(in, homework);
	return in;
}



double grade(double midterm, double final, std::vector<double> homework) {}



double Student_info::grade() const  // const memeber function
{
	return ::grade(midterm, final, homework);  // :: to use the grade() is not a member of anything
}



class Student_info {  // define a class
public:
	// interface goes here
	Student_info();
	Student_info(std::istream&);

	double grade() const;
	std::istream& read(std::istream&);
	std::string name() const { return n; }
	bool isValid() { return !homework.empty(); }

private:
	// implementation goes here
	std::string n;
	double midterm, final;
	std::vector<double> homework;
};



Student_info::Student_info() : midterm(0), final(0) {}  // constructor initializers

Student_info::Student_info(std::istream& in) { read(in);  }



bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}