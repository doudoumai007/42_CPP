#include "Fixed.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int main( void )
{
	std::cout << BOLD << BLUE <<  "----------  CLASS CREATED  ----------" << RESET << std::endl;
	
	//Original constructor
	std::cout << BOLD << YELLOW << "[FIXED A]\n" << RESET;
	Fixed a;
	std::cout << std::endl;

	//Copy constructor
	std::cout << BOLD << YELLOW << "[FIXED B]\n" << RESET;
	Fixed b(a);
	std::cout << std::endl;
	//
	// std::cout << BOLD << YELLOW << "[FIXED B1]\n" << RESET;
	// Fixed b1 = a;
	// std::cout << std::endl;

	//Copy assignment operator
	std::cout << BOLD << YELLOW << "[FIXED C]\n" << RESET;
	Fixed c;
	c = b;

	std::cout << std::endl << BOLD << BLUE << "----------   SHOW VALUE   ----------" << RESET << std::endl;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << std::endl << BOLD << BLUE << "----------  SCOPE FINISHED  ----------" << RESET << std::endl;

	return (0);
}