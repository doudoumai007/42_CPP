#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExe;

	public:
		AForm(const std::string& name, bool isSigned, const int gradeToSign, const int gradeToExe);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

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
		virtual void				beSigned(const Bureaucrat& b) = 0;

		//Exe
		virtual void		execute(Bureaucrat const & executor) const = 0;

		//Getter
		const std::string& getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExe() const;
};


std::ostream& operator<<(std::ostream& out, const AForm& b);

#endif
