#include "Form.hpp"

Form::Form(const std::string name, const int gradeToSign, const int gradeToExe)
	: name(name), gradeToSign(gradeToSign), gradeToExe(gradeToExe)
{
	if (gradeToSign < 1 || gradeToExe < 1)
		throw (Form::GradeTooHighException());
	else if (gradeToSign > 150 || gradeToExe > 150)
		throw (Form::GradeTooLowException());
	isSigned = false;
}

Form::Form(const Form& other)
	: name(other.name), gradeToSign(other.gradeToSign), gradeToExe(other.gradeToExe)
{
	isSigned = other.isSigned;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return (*this);
}

Form::~Form() {}

//Exception
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw (Form::GradeTooLowException());
}

const std::string& Form::getName() const
{
	return(name);
}

bool Form::getIsSigned() const
{
	return (isSigned);
}

int Form::getGradeToSign() const
{
	return (gradeToSign);
}

int Form::getGradeToExe() const
{
	return (gradeToExe);
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
	std::string signedInfo;
	if (!f.getIsSigned())
		signedInfo = ", not signed,";
	else
		signedInfo = ", signed,";

	out << f.getName() << signedInfo
					   << " Grade to sign is " << f.getGradeToSign()
					   << ", Grade to execute is " << f.getGradeToExe() << std::endl; 
	return (out);
}

