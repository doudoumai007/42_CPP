#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
		: name(name),
		  hit_point(10),
		  engergy_point(10),
		  attack_damage(0)
{
	std::cout << "ClapTrap" << name << "created\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (hit_point <= 0)
	{
		std::cout << name << " is already dead! Cannot attatck!\n";
		return ;
	}
	if (engergy_point == 0)
	{
		std::cout << name << " has no energy left! Cannot attatck\n";
		return ;
	}
	engergy_point--;
	std::cout << name << " attack " << target 
			  << " causing " << attack_damage << " points of damage!\n";
	std::cout << name << " used 1 energy point, EP left:  " << engergy_point << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_point <= 0)
	{
		std::cout << name << " is already dead!\n";
		return ;
	}
	hit_point -= amount;
	if (hit_point < 0)
		hit_point = 0;
	std::cout << name << " took " << amount
			  << " damage! HP left: " << hit_point << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_point <= 0)
	{
		std::cout << name << " is already dead! Cannot repair!\n";
		return ;
	}
	if (engergy_point == 0)
	{
		std::cout << name << " has no energy left! Cannot repair!\n";
		return ;
	}
	engergy_point--;
	hit_point += amount;
	std::cout << name << " repairs itself for " << amount
			  << " HP! Current HP: " << hit_point << std::endl;
	std::cout << name << " used 1 energy point, EP left:  " << engergy_point << std::endl;
}