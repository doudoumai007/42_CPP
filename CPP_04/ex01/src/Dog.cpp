#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called\n";
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor called\n";
	type = other.type;
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operatot called\n";
	if (this != &other)
	{
		type = other.type;
		delete(_brain);
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete(_brain);
}

void Dog::makeSound() const
{
	std::cout << "Dog barked\n";
}

Brain* Dog::getBrain()
{
	return (_brain);
}

