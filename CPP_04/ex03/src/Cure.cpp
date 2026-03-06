#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("Cure")
{
	std::cout << "Cure constructor called\n";
}

Cure::Cure(const Cure& other): AMateria(other.type)
{
	std::cout << "Cure copy constructor called\n";
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << "Cure copy assignment operatot called\n";
	if (this != &other)
		type = other.type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called\n";
}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an Cure bolt at" << target.getName() << std::endl;
}