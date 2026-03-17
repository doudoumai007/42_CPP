#include "Base.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>

Base*	generate(void)
{
	std::srand(time(NULL));
	int r = rand() % 3;
	if (r == 0)
	{
		std::cout << "A created\n";
		return (new A);
	}
	else if (r == 1)
	{
		std::cout << "B created\n";
		return (new B);
	}
	else
	{
		std::cout << "C created\n";
		return (new C);
	}
}

void	identify(Base* p)
	{
	if (dynamic_cast<A*>(p) != NULL)
			std::cout << "A\n";
	else if (dynamic_cast<B*>(p) != NULL)
			std::cout << "B\n";
	else if (dynamic_cast<C*>(p) != NULL)
			std::cout << "C\n";
}

void	identify(Base& p)
{
	//Reference will return an exception,
	//because if dynamic_cast<Base&> failed, there will be an exception
	//And reference could't be empty
	try
	{
		//(void) is to silent the "result unused" notif
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch(...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	}
	catch(...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	}
	catch(...) {}
}