#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int			grade;
	
	public:
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		//Exception Class
		class	GradeTooHighException: public std::exception
		{
			public:
			const char* what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
			const char* what() const throw();
		};

		//Increment
		void				incrementGrade();
		//Decrement
		void				decrementGrade();


		//Getter
		const std::string&	getName() const;
		const int&			getGrade() const;

		//Sign
		void				signForm(AForm& f) const;

		//Exe
		void				executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
#endif