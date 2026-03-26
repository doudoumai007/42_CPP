#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		//map:associative array
		//key & mapped
		//function1: operator[], allow read and write, non-exist value will create automaticly
		//function2: at(), mostly read, non-exist value will throw an exception
		std::map<std::string, double> rates;

	public:
		BitcoinExchange() {}
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange() {}

		void	loadDatabase(const std::string& filename);
		double	getRate(const std::string& date);
		void	printPrice(const std::string& date, double value, double price);
		void	processInput(const std::string& filename);
};





