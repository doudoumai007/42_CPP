#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
	PresidentialPardonForm(const std::string& name, bool isSigned, const int gradeToSign, const int gradeToExe);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	//Sign
	void				beSigned(const Bureaucrat& b);

	//Exe
	void		execute(Bureaucrat const & executor) const;

};



#endif