#include "Harl.hpp"
#include <string>
#include <iostream>

Harl::Harl() {}

void	Harl::debug()
{ 
	std::cout 
		<< "[ DEBUG ]"
		<< std::endl
		<< "Debug message"
		<< std::endl;
}

void	Harl::info()
{ 
	std::cout
		<< "[ INFO ]"
		<< std::endl
		<< "Info message"
		<< std::endl;
}

void	Harl::warning()
{ 
	std::cout 
		<< "[ WARNING ]"
		<< std::endl
		<< "Warning message"
		<< std::endl;
}

void	Harl::error()
{ 
	std::cout
		<< "[ ERROR ]"
		<< std::endl
		<< "Error message"
		<< std::endl;
}

void    Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*f[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int	levelIndex = 5;
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			levelIndex = i;
			break ;
		}
	}
	switch (levelIndex)
	{
		case 0:
			(this->*f[0])();
			std::cout << std::endl;
		case 1:
			(this->*f[1])();
			std::cout << std::endl;
		case 2:
			(this->*f[2])();
			std::cout << std::endl;
		case 3:
			(this->*f[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
					  << std::endl;
			break;
	}
}