#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static std::string _impossibleNotif;
		static std::string _nonDisplayableNotif;

		static void	_printChar(double value);
		static void	_printInt(double value);
		static void	_printFloat(double value);
		static void	_printDouble(double value);
		static void	_printPseudo(const std::string& pseudo);

	public:
		static void convert(const std::string& literal);
};

#endif