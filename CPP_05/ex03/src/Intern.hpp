#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		//Ability
		AForm*	makeForm(const std::string& name, const std::string& target);

		//Exception Class
		class FormNameNotExist: public std::exception
		{
			public:
			const char* what() const throw();
		};
};



#endif