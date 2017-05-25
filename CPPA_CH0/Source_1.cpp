#include <iostream>
#include <string>

int source_1()
{
	std::cout << "input name: "; // :: scope operator

	std::string name;
	std::cin >> name;

	const std::string greeting = "hi " + name + "!"; // + operator overload
	//std::cout << "hi " << name << "!";

	const std::string spaces(greeting.size(), ' ');  //.size() memeber function
	const std::string second = "* " + spaces + " *";
	const std::string first(second.size(), '*');

	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " + greeting + " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;

	return 0;
}