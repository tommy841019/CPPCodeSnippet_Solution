#include <iostream>
#include <math.h>
#include "constants.h"

double distance(int second, int h)
{
	return h-myConstants::gravityConstant * pow(second, 2) / 2;
}

void printResult(int second, int h)
{
	double tmp = distance(second, h);
	if(tmp<=0)
		std::cout<<"At "<<second<<" seconds, the ball is on the ground."<<std::endl;
	else
		std::cout<<"At "<<second<<" seconds, the ball is at height: "<<tmp<<" meters"<<std::endl;
}

int main()
{
	int h;
	std::cout<<"Enter the initial height of the tower in meters: ";
	std::cin>>h;
	if(h<0) std::cout<<"Height cannot be less than 0";
	else
	{
		for(int i=0; i<=5; i++)
		{
			printResult(i, h);
		}
	}

	std::cin>>h;
	return 0;
}