#include "Ice.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice") {}

Ice::Ice(const Ice& other): AMateria(other.type) {}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

Ice::~Ice() {}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria* tmp = new Ice();
	return (tmp);
}