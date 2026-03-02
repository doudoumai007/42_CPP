#include "Harl.hpp"
#include <string>
#include <iostream>

Harl::Harl() {}

void	Harl::debug() { std::cout << "Debug message" << std::endl;}

void	Harl::info() { std::cout << "Info message" << std::endl; }

void	Harl::warning() { std::cout << "Warning message" << std::endl;}

void	Harl::error() { std::cout << "Error message" << std::endl;}

void    Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*f[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
		// In member function, there's a hiden pointer "this", which points to its objet//
			(this->*f[i])();
			break ;
		}
	}
}
