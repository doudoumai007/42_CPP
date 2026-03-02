#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		count;
		int		index;

	public:
		PhoneBook();
		void	addContact(const Contact& c);
		bool	showPhonebook() const;
		bool	showContact(const int index) const;
};

#endif