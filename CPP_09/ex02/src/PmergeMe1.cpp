#include "PmergeMe.hpp"

#include <stdexcept>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <utility> // std::pair
#include <cmath>

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

	sortVector(_vec);

	std::cout << "\nAfter:  ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	// if (_deq.size() > 1)
	// 	sortDeque(_deq);
}


int	jacobsthal(int k)
{
	return (int)((pow(2, k + 1) + pow(-1, k)) / 3);
}

void	PmergeMe::sortVector(std::vector<int>& v, int level)
{
	typedef typename std::vector<int>::iterator iterator;

	// How many blocks exist in vector
	// level starts by 1, and also means how many elements in each block
	int	block_nbr = v.size() / level;

	// When there is less than 2 blocks, stop recursive
	if (block_nbr < 2)
		return ;
	
	// Too see if every block can make paris, if not there's a odd ate the emd
	bool is_odd = block_nbr % 2 == 1;

	// Prepare for iterator 
	// start: first element of 1st block
	// end: last element of the last block)
	iterator start = v.begin();
	iterator end = v.begin() + ((block_nbr - odd) * level);

	// Compare two next pairs' big and swap
	for (iterator it = start; it < end; it += (level * 2))
	{
		_comparisons++;
		// 2 blocks: first block & next block
		iterator this_start = it;
		iterator this_end = it + level - 1;
		iterator next_start = it + level;
		iterator next_end = it + (level * 2) - 1;

		if (*this_end > *next_end)
			_swap_pair(this_start, next_start);
	}

	// Recursive
	sortVector(v, level * 2);
	
	// Every recursive we rebuild the main and the pend
	std::vector<iterator> main;
	std::vector<iterator> pend;

	// Initialize the main chain with the first 2 blocks: a1, b1
	// Because b1 is the smallest in b group and a1 is definately smaller than b1
	main.push_back(v[level - 1]);
	main.push_back(v[level * 2 - 1]);

	// According to the current level, we put main and pend chain
	// Jump the first 2 blocks(a1 b1)
	// Everytime increment level*2 elements (to jump 2 blocks)
	// Put the first block in pend and the second block in main
	for (iterator it = start + 2 * level; it + level * 2 <= end; it += level * 2)
	{
		iterator first_block = it;
		iterator second_block = it + level;

		pend.push_back(*(first_block + level - 1));
		main.push_back(*(second_block + level - 1));
	}

	// Put the odd block in pend
	if (is_odd)
		





}

// ================= 输出比较次数 =================
void PmergeMe::printComparisons()
{
	std::cout << "\nTotal comparisons: " << _comparisons << "\n";
}

// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91