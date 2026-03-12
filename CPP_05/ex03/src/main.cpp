#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int	main()
{
	srand(time(NULL));
	/////// Create 3 Forms ///////
	std::cout << BOLD << BLUE << "--- Create 3 Forms ---\n" << RESET;
	PresidentialPardonForm	form1("Target1");
	RobotomyRequestForm		form2("Target2");
	ShrubberyCreationForm	form3("Target3");
	
	std::cout << form1;
	std::cout << form2;
	std::cout << form3;

	/////// Too low to sign and exe ///////
	std::cout << BOLD << BLUE << "\n--- Too low to sign and exe ---\n" << RESET;
	try
	{
		std::cout << BOLD << YELLOW << "[Bob Sign && Exe]\n" << RESET;
		Bureaucrat bob("Bob", 149);
		std::cout << bob;
		bob.signForm(form1);
		bob.signForm(form2);
		bob.signForm(form3);
		bob.executeForm(form1);
		bob.executeForm(form2);
		bob.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/////// Ok to sign and exe //////////
	std::cout << BOLD << BLUE << "\n--- Ok to sign ---\n" << RESET;
	try
	{
		std::cout << BOLD << YELLOW << "[Alice Sign]\n" << RESET;
		Bureaucrat alice("Alice", 5);
		std::cout << alice;
		alice.signForm(form1);
		alice.signForm(form2);
		alice.signForm(form3);

		std::cout << BOLD << YELLOW << "[Forms Status]\n" << RESET;
		std::cout << form1;
		std::cout << form2;
		std::cout << form3;

		std::cout << BOLD << BLUE << "\n--- Signed but too low to exe ---\n" << RESET;
		std::cout << BOLD << YELLOW << "[Bob Exe]\n" << RESET;
		Bureaucrat bob("Bob", 149);
		std::cout << bob;
		bob.executeForm(form1);
		bob.executeForm(form2);
		bob.executeForm(form3);

		std::cout << BOLD << BLUE << "\n--- Signed and ok to exe ---\n" << RESET;
		std::cout << BOLD << YELLOW << "[Alice Exe]\n" << RESET;
		std::cout << BOLD << GREEN << "[PresidentialPardonForm]\n" << RESET;
		alice.executeForm(form1);
		std::cout << BOLD << GREEN << "[RobotomyRequestForm]\n" << RESET;
		alice.executeForm(form2);
		std::cout << BOLD << GREEN << "[RobotomyRequestForm]\n" << RESET;
		alice.executeForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat bob("Bob", 147);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}