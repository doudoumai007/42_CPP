#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45),
	  target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExe()),
	  target(other.target)
{
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

//Exe
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw (FormNotSignedException());
	if (executor.getGrade() > this->getGradeToExe())
		throw (GradeTooLowException());
	
	std::cout << "Brrrrrrrrrrrzzzzzzzzzz\n";
	if (rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully\n";
	else
		std::cout << target << " has failed the robotomy\n";

}