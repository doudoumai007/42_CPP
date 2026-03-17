#include "ScalarConverter.hpp"

#include <iostream>
#include <limits>
#include <iomanip>
#include <cstdlib>

std::string ScalarConverter::_impossibleNotif = "impossible\n";
std::string ScalarConverter::_nonDisplayableNotif = "Non displayable\n";

void	ScalarConverter::_printChar(double value)
{
	//Safty Check: NaN , < 0, > 127
	if (value != value || value < 0 || value > 127)
		std::cout << "char: " << _impossibleNotif;
	//Non displayable
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "char: " << _nonDisplayableNotif;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'\n";
}

void	ScalarConverter::_printPseudo(const std::string& pseudo)
{
	std::cout << "char: " << _impossibleNotif;
	std::cout << "int: " << _impossibleNotif;

	//Nan
	if (pseudo == "nan")
		std::cout << "float: nanf\ndouble: nan\n";
	//Inf
	else if (pseudo == "inf")
		std::cout << "float: +inff\ndouble: +inf\n";
	//-Inf
	else if (pseudo == "-inf")
		std::cout << "float: -inff\ndouble: -inf\n";
}

void	ScalarConverter::_printInt(double value)
{
	//Safty Check:
	if (value != value || value < std::numeric_limits<int>::min() || \
		value > std::numeric_limits<int>::max())
		std::cout << "int: " << _impossibleNotif;
	else
		std::cout << "int: " << static_cast<int>(value) << "\n";
}

void	ScalarConverter::_printFloat(double value)
{
	std::cout << "float: ";
	if (value != value)
		std::cout << "naf\n";
	// infinity is under type double
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "+inff\n";
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "-inff\n";
	else
	// std::fixed to put under fixed format
	// std::precision to set precision to 1 decimal place !!header <iomanip>
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";
}

void	ScalarConverter::_printDouble(double value)
{
	std::cout << "double: ";
	if (value != value)
		std::cout << "nan\n";
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "+inf\n";
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "-inf\n";
	else
		std::cout << std::fixed << std::setprecision(1) << value << "\n";
}

void ScalarConverter::convert(const std::string& literal)
{
	double value;

	// if Char
	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		value = literal[0];
		_printChar(value);
		_printInt(value);
		_printFloat(value);
		_printDouble(value);
		return ;
	}
	// if Pseudo
	if (literal == "nan" || literal == "nanf")
	{
		_printPseudo("nan");
		return ;
	}
	else if (literal == "+inf" || literal == "inff")
	{
		_printPseudo("inf");
		return ;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		_printPseudo("-inf");
		return ;
	}

	// Common parsing: get valide number from the first part
	// and check if the end of the string is "f"
	char *end;
	value = strtod(literal.c_str(), &end);
	if (*end != 0 && !(*end == 'f' && *(end + 1) == '\0'))
	{
		std::cout << "Invalid literal\n";
		return ;
	}
	//To define if it's float
	bool isFloat = (*end == 'f');

	//Print
	_printChar(value);
	_printInt(value);
	//If it's float, should put float as parameter
	if (isFloat)
		_printFloat(static_cast<float>(value));
	else
		_printFloat(value);
	_printDouble(value);	
}
