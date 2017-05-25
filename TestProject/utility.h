#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
namespace Utility
{
	inline void pauseForInput()
	{
		std::cout<<std::endl<<std::endl<<"Press any key to exit...";
		std::getchar();
	}
}

#endif

