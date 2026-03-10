#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& name, bool isSigned, const int gradeToSign, const int gradeToExe)
	: AForm(name, isSigned, gradeToSign, gradeToExe)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other.getName(), other.getIsSigned(), other.getGradeToSign(), other.getGradeToExe())
{

}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

//Sign
void				beSigned(const Bureaucrat& b);

//Exe
void		execute(Bureaucrat const & executor) const;
