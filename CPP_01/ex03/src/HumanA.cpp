#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, const Weapon &weapon): name(name), weapon(weapon) {}

void    HumanA::attack()
{
    std::cout << this->name << " attack with their " << this->weapon.getType() << std::endl;
}