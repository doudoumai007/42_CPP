#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = grade;	
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

//Exception
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}


//Increment
void	Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw (GradeTooHighException());
	grade--;
}
//Decrement
void	Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw (GradeTooLowException());
	grade++;
}

//Getter
const std::string&	Bureaucrat::getName() const
{
	return (name);
}

int			Bureaucrat::getGrade() const
{
	return (grade);
}

//Sign
void	Bureaucrat::signForm(Form& f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
	
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (out);
}
