#include "Contact.hpp"
#include "PhoneBook.hpp"
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

std::string getInput(const std::string& prompt) {
	std::string str;
	std::cout << "\033[1;36m" << prompt << "\033[0m" << std::endl;
	while (not std::getline(std::cin, str) or str.empty()) {
		if (std::cin.eof()) {
			std::cout << "\033[1;31m" << "Input interrupted by EOF. Exiting program." << "\033[0m" << std::endl;
			return "";
		}
		std::cout << "\033[1;31m" << prompt << " cannot be empty. Please enter again:" << "\033[0m" << std::endl;
	}
	return str;
}

void	handleAdd(PhoneBook& phonebook)
{
	Contact c;
	c.setContact(
		getInput("first name"),
		getInput("last name"),
		getInput("nickname"),
		getInput("phone number"),
		getInput("secret")
	);
	phonebook.addContact(c);
}

void	handleSearch(PhoneBook& phonebook)
{
	if (!phonebook.showPhonebook())
		return ;
	while (true)
	{
		std::cout << "\033[1;33m" << "Please enter an index(1 - 8). Enter 0 to exit." << "\033[0m" << std::endl;
		std::string input;
		std::getline(std::cin, input);
		if (!isNumber(input))
		{
			std::cout << "\033[1;31m" << "Invalid index!" << "\033[0m" << std::endl;
			continue ;
		}
		int index = atoi(input.c_str());
		if (index == 0)
			break ;
		else if (index < 0 || index > 8)
		{
			std::cout << "\033[1;31m" << "Invalid index (should between 1 and 8)!" << "\033[0m" << std::endl;
			continue ;
		}
		if (!phonebook.showContact(index - 1))
		{
			std::cout << "\033[1;31m" << "No information in the index!" << "\033[0m" << std::endl;
			continue ;
		}
	}
}

int	main()
{
	PhoneBook phonebook;
	std::string cmd;

	while (true)
	{
		std::cout << "\033[1;36m" << "Enter command (ADD SEARCH EXIT)" << "\033[0m" << std::endl;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cout << "\033[1;31m" << "Error: CTRL + D passed" << "\033[0m" << std::endl;
			break;
		}
		if (cmd == "ADD")
			handleAdd(phonebook);
		else if (cmd == "SEARCH")
			handleSearch(phonebook);
		else if (cmd == "EXIT")
			break ;
	}
	return (0);
}