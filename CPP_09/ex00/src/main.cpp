#include "BitcoinExchange.hpp"

#include <iostream>

int	main(int ac, char* av[])
{
	//Check arg number
	if (ac != 2)
	{
		std::cerr << "Usage: ./btc input.txt\n";
		return (1);
	}

	//Load database
	BitcoinExchange btc;

	//Input searching file
	try
	{
		btc.loadDatabase("data.csv");
		btc.processInput(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}

	return (0);
}