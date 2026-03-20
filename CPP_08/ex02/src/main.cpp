#include "MutantStack.hpp"

#include <iostream>
#include <list>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int main()
{
	//MutantStack
	std::cout << BOLD << BLUE << "--- MutantStack ---\n" << RESET;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << BOLD << YELLOW << "[top]\n" << RESET;
	std::cout << mstack.top() << std::endl;

	//pop 17
	mstack.pop();

	//size
	std::cout << BOLD << YELLOW << "[size]\n" << RESET;
	std::cout << mstack.size() << std::endl;

	//Test iterator
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << BOLD << YELLOW << "[iterate]\n" << RESET;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	//object slicing
	//A base class constructor can accept a reference or a copy of a derived class object
	std::stack<int> s(mstack);
	//s.begin() doesn't work

	//deep copy
	MutantStack<int> copy(mstack);
	copy.pop();
	std::cout << BOLD << YELLOW << "[deep copy]:\n" << RESET;
	//copy (poped 0)
	std::cout << BOLD << BLUE << "copy:(poped 0)\n" << RESET;
	for (MutantStack<int>::iterator it1 = copy.begin(); it1 != copy.end(); ++it1)
		std::cout << *it1 << std::endl;
	//origin (stay the same as before)
	std::cout << BOLD << BLUE<< "origin:\n" << RESET;
	it = mstack.begin();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}


	//std::list
	std::cout << BOLD << BLUE << "--- std::list ---\n" << RESET;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << BOLD << YELLOW << "[top == back]\n" << RESET;
	std::cout << lst.back() << std::endl;
	std::cout << BOLD << YELLOW << "[pop == pop_back]\n" << RESET;
	//pop_back 17
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();
	++it;
	--it;
	std::cout << BOLD << YELLOW << "[iterate]\n" << RESET;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::list<int> l(lst);

	return (0);
}