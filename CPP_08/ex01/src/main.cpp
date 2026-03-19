#include "Span.hpp"

#include <vector>
#include <list>
#include <iostream>
#include <ctime>
#include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int main()
{
	/////// Try int max - min, does't overflow ///////
	std::cout << BOLD << BLUE << "--- Try int max - min ---\n" << RESET;
	Span v(5);
	v.addNumber(2147483647);
	v.addNumber(-2147483648);
	std::cout << "Longest span: " << v.longestSpan() << std::endl;

	/////// Try to add more than N number ///////
	std::cout << BOLD << BLUE << "--- Try to add more than N number ---\n" << RESET;
	Span sp = Span(10);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// More than 5 number, return an exception
		sp.addNumber(14);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	/////// Try no number stored ///////
	std::cout << BOLD << BLUE << "--- Try no number stored ---\n" << RESET;
	Span v2(5);
	try
	{
		v2.longestSpan();
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/////// Try 1 number stored ///////
	std::cout << BOLD << BLUE << "--- Try 1 number stored ---\n" << RESET;
	try
	{
		v2.addNumber(5);
		v2.longestSpan();
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	/////// 10 Ramdom number range ///////
	std::cout << BOLD << BLUE << "--- Try add a range of 10 numbers ---\n" << RESET;
	std::vector<int> range;
	range.reserve(10);
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < 10; ++i)
	{
		int num = rand();
		std::cout << "num: " << num << std::endl;
		range.push_back(num);
	}
	//Add range
	Span v3(10);
	try
	{
		v3.addRange(range.begin(), range.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Shortest span: " << v3.shortestSpan() << std::endl;
	std::cout << "Longest span: " << v3.longestSpan() << std::endl;

	/////// 10000 Ramdom number range ///////
	std::cout << BOLD << BLUE << "--- Try add a range of 10000 numbers ---\n" << RESET;
	std::vector<int> range2;
	range2.reserve(10000);
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < 10000; ++i)
	{
		int num = rand();
		range2.push_back(num);
	}
	//Add range
	Span v4(10000);
	try
	{
		v4.addRange(range2.begin(), range2.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Shortest span: " << v4.shortestSpan() << std::endl;
	std::cout << "Longest span: " << v4.longestSpan() << std::endl;

	return (0);
}