#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExe;

	public:
		Form(const std::string name, const int gradeToSign, const int gradeToExe);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		//Exception
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
		
		//Sign
		void				beSigned(const Bureaucrat& b);

		//Getter
		const std::string&	getName() const;
		bool				getIsSigned() const;
		int 				getGradeToSign() const;
		int 				getGradeToExe() const;
};


std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
