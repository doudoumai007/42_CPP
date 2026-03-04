#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor called\n";
	
	hit_point = 100;
	engergy_point = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called\n";

	name = other.name;
	hit_point = other.hit_point;
	engergy_point = other.engergy_point;
	attack_damage = other.attack_damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy ssignment operator called\n";
	if (this != &other)
	{
		name = other.name;
		hit_point = other.hit_point;
		engergy_point = other.engergy_point;
		attack_damage = other.attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode\n";
}