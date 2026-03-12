#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
			:ClapTrap(name + "_clap_name"),
			 ScavTrap(name),
			 FragTrap(name),
			 name(name)
{
	std::cout << "DiamondTrap Constructor called\n";

	hit_point = FragTrap::hit_point;
	energy_point = ScavTrap::energy_point;
	attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
			:ClapTrap(other),
			 ScavTrap(other),
			 FragTrap(other),
			 name(other.name)
{
	std::cout << "DiamondTrap Copy constructor called\n";
	hit_point = other.hit_point;
	energy_point = other.energy_point;
	attack_damage = other.attack_damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap Copy assignment operator called\n";
	if (this != &other)
	{
		name = other.name;
		ClapTrap::operator=(other);
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called\n";
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << std::endl 
			  <<  "ClapTrap name: " << ClapTrap::name << std::endl;
}