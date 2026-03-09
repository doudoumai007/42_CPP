#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") {}

Cure::Cure(const Cure& other): AMateria(other.type) {}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
		type = other.type;
	return (*this);
}

Cure::~Cure() {}

void Cure::use(ICharacter& target)
{
	std::cout << "* shoots an Cure bolt at " << target.getName() << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria* tmp = new Cure();
	return (tmp);
}