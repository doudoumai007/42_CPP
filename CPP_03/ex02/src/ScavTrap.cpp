#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor called\n";
	
	hit_point = 100;
	energy_point = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called\n";

	name = other.name;
	hit_point = other.hit_point;
	energy_point = other.energy_point;
	attack_damage = other.attack_damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy ssignment operator called\n";
	if (this != &other)
	{
		name = other.name;
		hit_point = other.hit_point;
		energy_point = other.energy_point;
		attack_damage = other.attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (hit_point <= 0)
	{
		std::cout << "ScavTrap " << name << " is already dead! Cannot attatck!\n";
		return ;
	}
	if (energy_point == 0)
	{
		std::cout << "ScavTrap " << name << " has no energy left! Cannot attatck\n";
		return ;
	}
	energy_point--;
	std::cout << "ScavTrap " << name << " attack " << target 
			  << " causing " << attack_damage << " points of damage!\n";
	std::cout << "ScavTrap " << name << " used 1 energy point, EP left:  " << energy_point << std::endl;
}


void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode\n";
}