#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
		: name(name),
		  hit_point(10),
		  engergy_point(10),
		  attack_damage(0)
{
	std::cout << "ClapTrap Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
		: name(other.name),
		  hit_point(other.hit_point),
		  engergy_point(other.engergy_point),
		  attack_damage(other.attack_damage)
{
	std::cout << "ClapTrap Copy constructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy ssignment operator called\n";
	if (this != &other)
	{
		name = other.name;
		hit_point = other.hit_point;
		engergy_point = other.engergy_point;
		attack_damage = other.attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (hit_point <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead! Cannot attatck!\n";
		return ;
	}
	if (engergy_point == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left! Cannot attatck\n";
		return ;
	}
	engergy_point--;
	std::cout << "ClapTrap " << name << " attack " << target 
			  << " causing " << attack_damage << " points of damage!\n";
	std::cout << name << " used 1 energy point, EP left:  " << engergy_point << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_point <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead!\n";
		return ;
	}
	hit_point -= amount;
	if (hit_point < 0)
		hit_point = 0;
	std::cout << "ClapTrap " << name << " took " << amount
			  << " damage! HP left: " << hit_point << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_point <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead! Cannot repair!\n";
		return ;
	}
	if (engergy_point == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left! Cannot repair!\n";
		return ;
	}
	engergy_point--;
	hit_point += amount;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount
			  << " HP! Current HP: " << hit_point << std::endl;
	std::cout << "ClapTrap " << name << " used 1 energy point, EP left:  " << engergy_point << std::endl;
}