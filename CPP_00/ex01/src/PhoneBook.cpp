#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), index(0) {}

void printContact(const std::string& s)
{
	if (s.length() > 10)
		std::cout << s.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << s;
}

void PhoneBook:: addContact(const Contact& c)
{
	contacts[index] = c;
	index = (index + 1) % 8;
	if (count < 8)
		count++;
}
bool PhoneBook:: showPhonebook() const
{
	if (count == 0)
	{
		std::cout << "\033[1;31m" << "No contact for now, please add a contact!" << "\033[0m" << std::endl;
		return (false);
	}
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		printContact(contacts[i].getFirstName());
		std::cout << "|";
		printContact(contacts[i].getLastName());
		std::cout << "|";
		printContact(contacts[i].getNickName());
		std::cout << std::endl;
	}
	return (true);
}

bool PhoneBook:: showContact(const int index) const
{
	if (index > count - 1)
		return (false);
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].getSecret() << std::endl;
	return (true);
}