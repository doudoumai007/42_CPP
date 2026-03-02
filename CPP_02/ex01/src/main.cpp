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

	std::cout << BOLD << YELLOW << "[FIXED A]\n" << RESET;
	Fixed a;
	std::cout << std::endl;

	std::cout << BOLD << YELLOW << "[FIXED B]\n" << RESET;
	Fixed const b( 10 );
	std::cout << std::endl;

	std::cout << BOLD << YELLOW << "[FIXED C]\n" << RESET;
	Fixed const c( 42.42f );
	std::cout << std::endl;

	std::cout << BOLD << YELLOW << "[FIXED D]\n" << RESET;
	Fixed const d( b );
	std::cout << std::endl;

	std::cout << BOLD << YELLOW << "[FIXED A]: reassignment\n" << RESET;
	a = Fixed( 1234.4321f );
	std::cout << std::endl;


	std::cout << std::endl << BOLD << BLUE << "----------   SHOW VALUE   ----------" << RESET << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << std::endl << BOLD << BLUE << "----------   SHOW INTEGER   ----------" << RESET << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << std::endl << BOLD << BLUE << "----------  SCOPE FINISHED  ----------" << RESET << std::endl;

	return (0);
}