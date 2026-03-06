#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat constructor called\n";
	type = "Cat";
	_brain = new Brain();
	}

Cat::Cat(const Cat& other)
{
	std::cout << "Cat copy constructor called\n";
	type = other.type;
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment operatot called\n";
	if (this != &other)
	{
		type = other.type;
		delete(_brain);
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete(_brain);
}

void Cat::makeSound() const
{
	std::cout << "Cat meowed\n";
}

Brain* Cat::getBrain()
{
	return (_brain);
}
