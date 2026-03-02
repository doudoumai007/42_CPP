#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string& name): name(name) {}
Zombie::~Zombie()
{
    std::cout << this->name << " has been destoryed.\n";
}

void Zombie:: announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
