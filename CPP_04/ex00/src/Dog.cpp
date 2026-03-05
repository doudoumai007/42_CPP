#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called\n";
    type = "Dog";
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor called\n";
    type = other.type;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operatot called\n";
    if (this != &other)
        type = other.type;
    return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "Dog barked\n";
}
