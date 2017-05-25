#ifndef IO_H
#define IO_H
#include <string>
void writeAnswer(double x, double y, char op, double answer);
double readNumber(std::string msg);
char readOp(std::string msg);
#endif