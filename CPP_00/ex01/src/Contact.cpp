#include "Contact.hpp"

Contact::Contact() {}

void Contact::setContact
(
	const std::string& fn,
	const std::string& ln,
	const std::string& nn,
	const std::string& pn,
	const std::string& ds
) 
{
	firstName = fn;
	lastName = ln;
	nickName = nn;
	phoneNumber = pn;
	darkestSecret= ds;
}

std::string Contact::getFirstName() const 
{
	return (firstName);
}

std::string Contact::getLastName() const 
{
	return (lastName);
}

std::string Contact::getNickName() const 
{
	return (nickName);
}

std::string Contact::getPhoneNumber() const 
{
	return (phoneNumber);
}

std::string Contact::getSecret() const 
{
	return (darkestSecret);
}