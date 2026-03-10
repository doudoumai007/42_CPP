#include "AForm.hpp"

AForm::AForm(const std::string& name, bool isSigned, const int gradeToSign, const int gradeToExe)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExe(gradeToExe)
{
	if (gradeToSign < 1 || gradeToExe < 1)
		throw (AForm::GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExe > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm& other)
	: name(other.name), gradeToSign(other.gradeToSign), gradeToExe(other.gradeToExe)
{
	isSigned = other.isSigned;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return (*this);
}

AForm::~AForm() {}

//Exception
const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}
//Sign
void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw (AForm::GradeTooLowException());
}

//Exe
void	AForm::execute(Bureaucrat const & executor) const
{

}


//Getter
const std::string& AForm::getName() const
{
	return(name);
}

bool AForm::getIsSigned() const
{
	return (isSigned);
}

int AForm::getGradeToSign() const
{
	return (gradeToSign);
}

int AForm::getGradeToExe() const
{
	return (gradeToExe);
}

//Overload <<
std::ostream& operator<<(std::ostream& out, const AForm& f)
{
	out << f.getName() << " 's Grade to sign is " << f.getGradeToSign()
					   << " ,Grade to execute is " << f.getGradeToExe() << std::endl; 
	return (out);
}

