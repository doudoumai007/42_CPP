#include "Ice.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice constructor called\n";
}

Ice::Ice(const Ice& other): AMateria(other.type)
{
	std::cout << "Ice copy constructor called\n";
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Ice copy assignment operatot called\n";
	if (this != &other)
		type = other.type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor called\n";
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at" << target.getName() << std::endl;
}