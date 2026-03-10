#include "Bureaucrat.hpp"
#include "Form.hpp"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int	main()
{
	/////// Too High ///////
	std::cout << BOLD << BLUE << "--- Too High ---\n" << RESET;
	try
	{
		Form f1("form1", 30, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/////// Too Low ///////
	std::cout << BOLD << BLUE << "\n--- Too Low ---\n" << RESET;
	try
	{
		Form f2("form1", 30, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	/////// OK to sign ///////
	std::cout << BOLD << BLUE << "\n--- OK to sign ---\n" << RESET;
	try
	{
		Bureaucrat alice("Alice", 2);
		std::cout << alice;
		Form f1("form1", 30, 50);
		alice.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/////// Too low to sign ///////
	std::cout << BOLD << BLUE << "\n--- Normal + Decrement ---\n" << RESET;
	try
	{
		Bureaucrat bob("Bob", 149);
		std::cout << bob;
		Form f2("form1", 30, 50);
		bob.signForm(f2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}