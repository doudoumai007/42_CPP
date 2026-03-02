#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
#include <ctime>

class Contact 
{
	private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	public:
	Contact();
	void setContact
	(
		const std::string& fn,
		const std::string& ln,
		const std::string& nn,
		const std::string& pn,
		const std::string& ds
	);
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getSecret() const;
};

#endif