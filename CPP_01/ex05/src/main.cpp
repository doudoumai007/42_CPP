#include "Harl.hpp"
#include <iostream>

int	main()
{
	Harl client;

	std::cout << "\033[1;34m" << "DEBUG level passed" << "\033[0m" << std::endl;
	client.complain("DEBUG");

	std::cout << std::endl << "\033[1;34m" << "INFO level passed" << "\033[0m" << std::endl;
	client.complain("INFO");

	std::cout << std::endl << "\033[1;34m" << "WARNING level passed" << "\033[0m" << std::endl;
	client.complain("WARNING");

	std::cout << std::endl << "\033[1;34m" << "ERROR level passed" << "\033[0m" << std::endl;
	client.complain("ERROR");

	std::cout << std::endl << "\033[1;34m" << "Unknown level passed" << "\033[0m" << std::endl;
	client.complain("SILENCE");
	
	return (0);
}