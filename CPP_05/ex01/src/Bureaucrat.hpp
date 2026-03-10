#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Form;

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
		void	incrementGrade();
		//Decrement
		void	decrementGrade();


		//Getter
		const std::string&	getName() const;
		int			getGrade() const;

		//Sign
		void				signForm(Form& f) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
#endif