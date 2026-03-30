#include "PmergeMe.hpp"

#include <stdexcept>
#include <cstdlib>
#include <limits>

int	positiveInt(char *av)
{
	if (!av || !*av)
		throw (std::invalid_argument("Error: empty input."));
	
	int value = 0;
	for (int i = 0; av[i]; ++i)
	{
		if (!std::isdigit(av[i]))
			throw (std::invalid_argument("Error: wrong character in the input."));
		int	digit = av[i] - '0';
		if (value > (std::numeric_limits<int>::max() - digit) / 10)
			throw (std::invalid_argument("Error: interger overflow."));
		value = value * 10 + digit;
	}
	if (value <= 0)
		throw (std::invalid_argument("Error: only positive integers allowed."));
	return (value);
}

PmergeMe::PmergeMe(char *av[])
{
    int	i = 1;
	while (av[i])
	{
		int value = positiveInt(av[i]);
		_vec.push_back(value);
		_deq.push_back(value);
		++i;
	}
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return (*this);
}

void	PmergeMe::sort()
{
	if (_vec.size() > 1)
		sortVector(_vec);
	if (_deq.size() > 1)
		sortDeque(_deq);
}

// void	PmergeMe::sortVector(std::vector<int> v)
// {

// }