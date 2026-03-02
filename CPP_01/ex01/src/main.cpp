#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

bool	isNumber(std::string input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return (false);
	}
	return (true);
}

void	zombieChump(int N, Zombie *horde)
{
	std::cout << "-------  Announce  -------" << std::endl;
	for (int i = 0; i < N; i ++)
	{
		std::cout << "[" << i << "]";
		horde[i].announce();
	}
}

void	deleteZombie(Zombie *horde)
{
	delete[] horde;
}

bool	handleNumber(int *N)
{
	std::string number;

	while (true)
	{
		std::cout << "\033[1;34m" << "Please enter the number of Zombies" << "\033[0m" << std::endl;
		std::getline(std::cin, number);
		if (std::cin.eof())
		{
			std::cout << "\033[1;31m" << "Error: CTRL + D passed. Exiting program!" << "\033[0m" << std::endl;
			return (false);
		}
		if (number.empty())
		{

			std::cout << "\033[1;31m" << "Input cannot be empty!" << "\033[0m" << std::endl;
			continue ;
		}
		if (!isNumber(number))
		{
			std::cout << "\033[1;31m" << "Invalid number!" << "\033[0m" << std::endl;
			continue ;
		}
		*N = atoi(number.c_str());
		if (*N <= 0)
		{
			std::cout << "\033[1;31m" << "Invalid number!" << "\033[0m" << std::endl;
			continue;
		}
		break ;
	}
	return (true);
}

std::string	handleName()
{
	std::string name;
	while (true)
	{
		std::cout << "\033[1;34m" << "Please enter Zombies's name" << "\033[0m" << std::endl;
		std::getline(std::cin, name);
		if (std::cin.eof())
		{
			std::cout << "\033[1;31m" << "Error: CTRL + D passed. Exiting program!" << "\033[0m" << std::endl;
			return ("");
		}
		if (name.empty())
		{
			std::cout << "\033[1;31m" << "Input cannot be empty!" << "\033[0m" << std::endl;
			continue ;
		}
		break ;
	}
	return (name);
}

int	main()
{
	std::string name;
	int			N;

	N = 0;
	if (!handleNumber(&N))
		return (1);
	name = handleName();
	if (name.empty())
		return (1);
	Zombie *horde = zombieHorde(N, name);
	zombieChump(N, horde);
	deleteZombie(horde);
	return (0);
}