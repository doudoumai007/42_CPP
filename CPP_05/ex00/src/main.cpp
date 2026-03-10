#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int	main()
{
	/////// Too High //////
	std::cout << BOLD << BLUE << "--- Too High ---\n" << RESET;
	try
	{
		Bureaucrat("Alice", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/////// Too Low //////
	std::cout << BOLD << BLUE << "\n--- Too Low ---\n" << RESET;
	try
	{
		Bureaucrat("Bob", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	/////// Normal + Increment //////
	std::cout << BOLD << BLUE << "\n--- Normal + Increment ---\n" << RESET;
	try
	{
		Bureaucrat alice("Alice", 2);
		std::cout << alice;
		alice.incrementGrade();
		std::cout << alice;
		alice.incrementGrade();
		std::cout << alice;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/////// Normal + Decrement //////
	std::cout << BOLD << BLUE << "\n--- Normal + Decrement ---\n" << RESET;
	try
	{
		Bureaucrat bob("Bob", 149);
		std::cout << bob;
		bob.decrementGrade();
		std::cout << bob;
		bob.decrementGrade();
		std::cout << bob;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}