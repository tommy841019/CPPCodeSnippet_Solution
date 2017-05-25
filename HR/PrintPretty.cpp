#include <iostream>
#include <iomanip>
#include <deque>
#include <algorithm>

int mainPP(){
	int A = 10;
	double D = 99.88;
	std::cout<<A<<" "<<D<<std::endl;
	std::cout<<A<<" "<<(int)D<<std::endl;
	std::cout<<std::setiosflags(std::ios::showbase | std::ios::uppercase | std::ios::showpos);
	std::cout<<std::hex<<A<<" "<<D<<std::endl;
	std::cout<<A<<" "<<(int)D<<std::endl;
	std::cout<<std::setw(100)<<std::setfill('_')<<std::left;
	std::cout<<A<<std::endl;
	std::cout<<std::setw(100)<<std::setfill('_')<<std::internal;
	std::cout<<(int)D<<std::endl;
	std::cout.precision(9);
	std::cout<<std::fixed<<D<<std::endl;
	std::cout<<std::scientific<<D<<std::endl;
	std::resetiosflags(std::ios::showbase | std::ios::uppercase | std::ios::showpos);
	std::cout<<12.12<<std::endl;
	std::cout.precision(0);
	std::cout<< std::setiosflags(std::ios::showbase)<<std::fixed<<std::hex<<12.12;

	std::deque<int> dq;
	dq.push_back(1);
	dq.push_front(2);
	dq.push_back(20);
	

	return 0;
}