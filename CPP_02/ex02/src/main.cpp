#include "Fixed.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int main()
{
	std::cout << BOLD << BLUE <<  "----------  CLASS CREATED  ----------" << RESET << std::endl;

	std::cout << BOLD << YELLOW << "[FIXED A]\n" << RESET;
	Fixed a;
	std::cout << std::endl;

	// std::cout << BOLD << YELLOW << "[FIXED FLOAT]\n" << RESET;
	// Fixed( 5.05f );
	// std::cout << std::endl;

	// std::cout << BOLD << YELLOW << "[FIXED INT]\n" << RESET;
	// Fixed( 2 );
	// std::cout << std::endl;

	std::cout << BOLD << YELLOW << "[FIXED B]\n" << RESET;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << std::endl;

	std::cout << std::endl << BOLD << BLUE << "----------   SHOW VALUE   ----------" << RESET << std::endl;

	std::cout << BOLD << YELLOW << "SHOW A VALUE\n" << RESET;
	std::cout << a << std::endl;
	std::cout << std::endl;

	std::cout << BOLD << YELLOW << "SHOW ++A VALUE\n" << RESET;
	std::cout << ++a << std::endl;
	std::cout << std::endl;

	std::cout << BOLD << YELLOW << "SHOW A VALUE\n" << RESET;
	std::cout << a << std::endl;
	std::cout << std::endl;

	std::cout << BOLD << YELLOW << "SHOW A++ VALUE\n" << RESET;
	std::cout << a++ << std::endl;
	std::cout << std::endl;

	std::cout << BOLD << YELLOW << "SHOW A VALUE\n" << RESET;
	std::cout << a << std::endl;
	std::cout << std::endl;

	std::cout << BOLD << YELLOW << "SHOW B VALUE\n" << RESET;
	std::cout << b << std::endl;
	std::cout << std::endl;

	std::cout << BOLD << YELLOW << "SHOW AB MAX\n" << RESET;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
}