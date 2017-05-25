#include <iostream>
#include <string>

void writeAnswer(double x, double y, char op, double answer)
{
	std::cout<<x<<" "<<op<<" "<<y<<" is: "<<answer<<std::endl;
}


double readNumber(std::string msg)
{
	std::cout<<msg;
	double tmp;
	std::cin >> tmp;
	std::cout<<std::endl;
	return tmp;
}


char readOp(std::string msg)
{
	std::cout<<msg;
	char tmp;
	std::cin >> tmp;
	std::cout<<std::endl;
	return tmp;
}