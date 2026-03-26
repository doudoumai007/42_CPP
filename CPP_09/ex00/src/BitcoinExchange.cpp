#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctype.h>
#include <stdio.h>

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		rates = other.rates;
	return (*this);
}

void    BitcoinExchange::loadDatabase(const std::string& filename)
{
	//input file stream using <fstream> read&write file
	std::ifstream file(filename.c_str());
	if (!file)
		throw (std::runtime_error("Error: could't open data file."));

	std::string line;

    //std::getline(): reads text from an input stream line by line
    //until it encounters a newline character (or custom delimiter👍)
    //usually used with std::ifstream (for reading files) or std::cin (standard input).
    std::getline(file, line); // Jump the header

    while(std::getline(file, line))
    {
		// std::stringstream: Treat a string as a stream, allowing read from and write to the string
		// An “in-memory string stream” that supports both input and output,
		// easy for string parsing or formatting
		std::stringstream ss(line);
		std::string date, rate;

		std::getline(ss, date, ',');
		std::getline(ss, rate);

		//std::atof: convert const char* to double
		rates[date] = std::atof(rate.c_str());
    }

	// std::cout << "Loaded " << rates.size() << " entries\n";
}

double BitcoinExchange::getRate(const std::string& date)
{
	// Try to find the iterator of the corresponding map
	// if non-found, return a closest higher key (key >= date) or rates.end()
	std::map<std::string, double>::iterator it = rates.lower_bound(date);

	// 2 cases that we should return an earlier date:
	// 1: date given is newer than the last date
	// 2: date in the middle but doesn't exist
	if (it == rates.end() || it->first != date)
	{
		if (it == rates.begin())
			throw (std::runtime_error("Error: Date too early."));
		--it;
	}
	return (it->second);
}

void BitcoinExchange::printPrice(const std::string& date, double value, double price)
{
	std::cout << date << " => " << value << " = "  << price << std::endl;
}

bool	parseDate(const std::string& date)
{
	// Lenth
	if (date.length() != 10)
		return (false);

	// Format YYYY-MM-DD
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!isdigit(date[i]))
			return (false);
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	// Month
	if (month < 1 || month > 12)
		return (false);

	// Day in each month
	int	dayInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
		dayInMonth[1] = 29;
	
	// Day
	if (day < 1 || day > dayInMonth[month - 1])
		return (false);
	
	return (true);
}

bool	parseValue(const std::string& valueStr)
{
	char*	pos;
	double value = std::strtod(valueStr.c_str(), &pos);

	//Empty value
	if (valueStr == "")
	{
		std::cerr << "Error: no value input.\n";
		return (false);
	}

	// Not only digit
	if (*pos != 0)
	{
		std::cerr << "Error: bad input => " << valueStr << std::endl;
		return (false);
	}

	// Negative
	if (value < 0)
	{
		std::cerr << "Error: not a positive number.\n";
		return (false);
	}

	// Too big
	if (value > 1000)
	{
		std::cerr << "Error: too large a number.\n";
		return (false);
	}
	return (true);
}

// Trim sapce and tab
std::string trim(const std::string& str)
{
	size_t begin = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");

	// std::string::npos means not found position, value -1
	if (begin == std::string::npos)
		return ("");
	// Return a new string stating from position begin with lenth(end - begin + 1)
	return (str.substr(begin, end - begin + 1));
}

void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw (std::runtime_error("Error: could't open input file."));
	std::string line;

	//Jump header
	std::getline(file, line);

	while (std::getline(file, line))
	{
		// Handle empty line
		if (line.empty())
		{
			std::cerr << "Error: empty line.\n";
			continue ;
		}
		std::stringstream ss(line);
		std::string date, valueStr;
		std::getline(ss, date, '|');
		std::getline(ss, valueStr);

		//trim spaces and tabs
		date = trim(date);
		valueStr = trim(valueStr);

		// Empty date
		if (date == "")
		{
			std::cerr << "Error: no date input.\n";
			continue ;
		}

		//parse date
		if (!parseDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}

		//parse value
		if (!parseValue(valueStr))
			continue ;
		
		double value = std::atof(valueStr.c_str());

		double price;
		try
		{
			double rate = getRate(date);
			price = value * rate;
			printPrice(date, value, price);	
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
}