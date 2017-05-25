#include "io.h";

int main()
{
	double x,y;
	x = readNumber("Enter a double value: ");
	y = readNumber("Enter a second double value: ");
	char op;
	op = readOp("Enter one of the following: +, -, *, or /: ");

	switch(op)
	{
		case '+': writeAnswer(x, y, op, x+y);break;
		case '-': writeAnswer(x, y, op, x-y);break;
		case '*': writeAnswer(x, y, op, x*y);break;
		case '/': writeAnswer(x, y, op, x/y);break;
	};
	
	return 0;
}






