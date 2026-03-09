#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const& type): type(type) {}

AMateria::AMateria(AMateria const & other)
{
	(void)other;
}

AMateria& AMateria::operator=(AMateria const & other)
{
	(void)other;
	return (*this);
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}