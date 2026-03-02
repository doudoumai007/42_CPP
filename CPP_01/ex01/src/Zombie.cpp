#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(): name("") {}

Zombie::Zombie(const std::string& name): name(name) {}

void	Zombie::setName(const std::string& name)
{
	this->name = name;
}

void	Zombie:: announce(void)
{
    std::cout  << "\033[1;34m" << this->name << ": BraiiiiiiinnnzzzZ..." << "\033[0m" << std::endl;
}