#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}
Intern::Intern(const Intern& other)
{
	(void)other;
}
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern() {}

AForm*	createPresidential(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}
AForm*	creatRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}
AForm*	createShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	std::string formName[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation",
	};
	//Array of function pointers
	AForm* (*func[3])(const std::string&) = {
		createPresidential,
		creatRobotomy,
		createShrubbery
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == formName[i])
			return (func[i](target));
	}
	throw (Intern::FormNameNotExist());
}

const char* Intern::FormNameNotExist::what() const throw()
{
	return ("Name doesn't exist");
}
