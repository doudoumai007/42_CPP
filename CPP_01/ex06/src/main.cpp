#include "Harl.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "\033[1;31m" << "Usage: ./HarlFilter [LEVEL]" << "\033[0m" << std::endl;
        return (1);
    }
    std::string level = argv[1];
	Harl client;

	client.complain(level);

	// std::cout << "\033[1;34m" << "DEBUG level passed" << "\033[0m" << std::endl;
	// client.complain("DEBUG");

	// std::cout << std::endl << "\033[1;34m" << "INFO level passed" << "\033[0m" << std::endl;
	// client.complain("INFO");

	// std::cout << std::endl << "\033[1;34m" << "WARNING level passed" << "\033[0m" << std::endl;
	// client.complain("WARNING");

	// std::cout << std::endl << "\033[1;34m" << "ERROR level passed" << "\033[0m" << std::endl;
	// client.complain("ERROR");

	// std::cout << std::endl << "\033[1;34m" << "Unknown level passed" << "\033[0m" << std::endl;
	// client.complain("SILENCE");
	
	return (0);
}