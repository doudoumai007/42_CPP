#include <string>
#include <iostream>

int	main()
{
	std::string	s = "HI THIS IS BRAIN";
	std::string	*stringPTR = &s;
	std::string	&stringREF = s;

	std::cout << "----------  ADDRESS  ----------" << std::endl;
	std::cout << "Address of s: " << &s << std::endl;
	std::cout << "Address of stringPTR: " << &stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;

	std::cout << "----------   VALUE   ----------" << std::endl;
	std::cout << "Value of s: " << s << std::endl;
	std::cout << "Value of stringPTR: " << stringPTR << std::endl;
	std::cout << "Value of stringREF: " << stringREF << std::endl;

	return (0);
}