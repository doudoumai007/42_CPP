#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name): name(name), weapon(NULL) {}

void	HumanB::setWeapon(Weapon &weapon) // weapon is a reference to the parameter passed in
{
	this->weapon = &weapon; //get the address of the objet that the reference represent
}

void    HumanB::attack()
{
	if (weapon)
		std::cout << this->name << " attack with their " << weapon->getType() << std::endl;
	else
		std::cout << this->name << " attack with their bare hands" << std::endl;
}