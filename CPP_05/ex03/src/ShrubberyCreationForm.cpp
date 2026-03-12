#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145,137),
	  target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExe()),
	  target(other.target)
{
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

//Exe
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw (FormNotSignedException());
	if (executor.getGrade() > this->getGradeToExe())
		throw (GradeTooLowException());

	//Output file system
	//ofstream inherits all the functionality of ostream, plus file operation capabilities
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file)
		return ;
	file <<
	"  /\\\n"
	" /**\\\n"
	"/****\\\n"
	"  ||\n";
	file.close();
}
