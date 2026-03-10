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
		std::cout << BOLD << YELLOW << "[Bureaucrat Info]\n" << RESET;
		Bureaucrat alice("Alice", 2);
		std::cout << alice;

		std::cout << BOLD << YELLOW << "[Form Info]\n" << RESET;
		Form f1("form1", 30, 50);
		std::cout << f1;

		std::cout << BOLD << YELLOW << "[Signature Info]\n" << RESET;
		alice.signForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/////// Too low to sign ///////
	std::cout << BOLD << BLUE << "\n--- Too low to sign ---\n" << RESET;
	try
	{
		std::cout << BOLD << YELLOW << "[Bureaucrat Info]\n" << RESET;
		Bureaucrat bob("Bob", 149);
		std::cout << bob;

		std::cout << BOLD << YELLOW << "[Form Info]\n" << RESET;
		Form f2("form1", 30, 50);
		std::cout << f2;

		std::cout << BOLD << YELLOW << "[Signature Info]\n" << RESET;
		bob.signForm(f2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}