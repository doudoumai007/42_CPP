#include "PmergeMe.hpp"

#include <stdexcept>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <ctime>

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

PmergeMe::PmergeMe(char *av[]): _comparisons(0)
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
	_vec = other._vec;
	_deq = other._deq;
	_comparisons = other._comparisons;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
		_comparisons = other._comparisons;
	}
	return (*this);
}

void	PmergeMe::sort()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];

	clock_t start = clock();
	sortVector(_vec);
	clock_t end =  clock();

	std::cout << "\nAfter:  ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	double time =  double(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "\nTime to process a range of " << _vec.size()
			  << " elements with std::vector : " << time << " us " <<std::endl;
	
	start = clock();
	sortDeque(_deq);
	end =  clock();

	time =  double(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::deque : " << time << " us " <<std::endl;
}


void	PmergeMe::sortVector(std::vector<int>& v)
{
	if (v.size() <= 1)
		return ;
	
	std::vector<int> small;
	std::vector<int> big;

	// Pair to compare
	for (size_t i = 0; i < v.size() - 1; i += 2)
	{
		_comparisons++; // 每对比较一次
		if (v[i] < v[i + 1])
		{
			small.push_back(v[i]);
			big.push_back(v[i + 1]);
		}
		else
		{
			big.push_back(v[i]);
			small.push_back(v[i + 1]);
		}
	}
	//Odd number add the last number to small
	if (v.size() % 2 != 0)
		small.push_back(v[v.size() -  1]);

	std::cout << "\nSmall: ";
	for (size_t i = 0; i < small.size(); ++i)
		std::cout << " " << small[i];
	
	std::cout << "\nBig: ";
	for (size_t i = 0; i < big.size(); ++i)
		std::cout << " " << big[i];

	// Recursive until find the biggest number and its pair
	sortVector(big);

	// Binary insertion
	for (size_t i = 0; i < small.size(); ++i) {
		size_t l = 0, r = big.size();
		while (l < r) {
			_comparisons++;
			size_t m = (l + r) / 2;
			if (big[m] < small[i])
				l = m + 1;
			else
				r = m;
		}
		big.insert(big.begin() + l, small[i]);
    }

	v = big;
}

void	PmergeMe::sortDeque(std::deque<int>& deq)
{
	if (deq.size() <= 1)
		return ;
	
	std::deque<int> small;
	std::deque<int> big;

	// Pair to compare
	for (size_t i = 0; i < deq.size() - 1; i += 2)
	{
		if (deq[i] < deq[i + 1])
		{
			small.push_back(deq[i]);
			big.push_back(deq[i + 1]);
		}
		else
		{
			big.push_back(deq[i]);
			small.push_back(deq[i + 1]);
		}
	}

	//Odd number add the last number to small
	if (deq.size() % 2 != 0)
		small.push_back(deq[deq.size() -  1]);

	// Recursive until find the biggest number and its pair
	sortDeque(big);

	// Binary insertion
	for (size_t i = 0; i < small.size(); ++i)
	{
		size_t l = 0, r = big.size();
		while (l < r) {
			size_t m = (l + r) / 2;
			if (big[m] < small[i])
				l = m + 1;
			else
				r = m;
		}
		big.insert(big.begin() + l, small[i]);
    }

	deq = big;
}

// ================= 输出比较次数 =================
void PmergeMe::printComparisons()
{
	std::cout << "Total comparisons: " << _comparisons << "\n";
}