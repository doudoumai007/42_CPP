#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called\n";
	type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment operatot called\n";
	if (this != &other)
		type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";

}

void Animal::makeSound() const
{
	std::cout << "Animal " << "made sound\n";
}

const std::string& Animal::getType() const
{
	return (type);
}
