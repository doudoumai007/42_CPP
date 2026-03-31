#include "PmergeMe.hpp"

#include <iostream>

int	main(int ac, char *av[])
{
	if (ac < 2)
	{
		std::cout << "Usage: ./PmergeMe <positive integer sequence>\n";
		return (1);
	}

	try
	{
		PmergeMe p(av);
		p.sort();
		p.printComparisons();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}

	return (0);
}