#include "RPN.hpp"

#include <iostream>

int	main(int ac, char* av[])
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RPN string\n";
		return (1);
	}
	try
	{
		RPN rpn;
		rpn.processInput(av[1]);
		rpn.printResult();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	
	return (0);
}