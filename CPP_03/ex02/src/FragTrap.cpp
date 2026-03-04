#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor called\n";
	
	hit_point = 100;
	engergy_point = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called\n";

	name = other.name;
	hit_point = other.hit_point;
	engergy_point = other.engergy_point;
	attack_damage = other.attack_damage;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Copy assignment operator called\n";
	if (this != &other)
	{
		name = other.name;
		hit_point = other.hit_point;
		engergy_point = other.engergy_point;
		attack_damage = other.attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called\n";
}

void FragTrap::attack(const std::string& target)
{
		if (hit_point <= 0)
	{
		std::cout << "FragTrap " << name << " is already dead! Cannot attatck!\n";
		return ;
	}
	if (engergy_point == 0)
	{
		std::cout << "FragTrap " << name << " has no energy left! Cannot attatck\n";
		return ;
	}
	engergy_point--;
	std::cout << "FragTrap " << name << " attack " << target 
			  << " causing " << attack_damage << " points of damage!\n";
	std::cout << name << " used 1 energy point, EP left:  " << engergy_point << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name <<" happily requests high-fives!\n";
}