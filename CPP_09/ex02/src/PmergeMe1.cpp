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

	// How many pairs exist in vector
	int	pair_nbr = v.size() / level;
	if (pair_nbr < 2)
		return ;
	
	// Odd pair (put at the end of pend)
	bool odd = pair_nbr % 2 == 1;

	iterator start = v.begin();
	iterator end = v.begin() + ((pair_nbr - odd) * level);

	// Compare two next pairs' big and swap
	for (iterator it = start; it < end; it += (level * 2))
	{
		_comparisons++;
		iterator this_start = it;
		iterator this_end = it + level - 1;
		iterator next_start = it + level;
		iterator next_end = it + (level * 2) - 1;

		if (*this_end > *next_end)
			_swap_pair(this_start, next_start);
	}

	// Recursive
	sortVector(v, level * 2);
	
	std::vector<iterator> main;
	std::vector<iterator> pend;

	// Initialize the main chain with first 2 pairs



	if (v.size() <= 1) return;

	// std::vector<int> big, small;

	std::vector<std::pair<int, int> > pairs;
	int odd = -1;

	// 配对并排列
	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		_comparisons++; // 每对比较一次
		if (v[i] <= v[i + 1])
			pairs.push_back(std::make_pair(v[i], v[i+1]));
		else
			pairs.push_back(std::make_pair(v[i+1], v[i]));
	}

	if (v.size() % 2 != 0)
		odd = v.back();

	std::vector<int> big;
	
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin();it != pairs.end(); ++it)
		big.push_back(it->second);

	// 递归排序 big
	sortVector(big);
	
	std::cout << "\nBig: ";
	for (size_t i = 0; i < big.size(); ++i)
		std::cout << " " << big[i];

	//插入Jacob[0]
	// big.insert(big.begin(), pairs[0].first);
	size_t l = 0, r = big.size();
	while (l < r) {
		_comparisons++;
		size_t m = (l + r) / 2;
		if (big[m] < pairs[0].first)
			l = m + 1;
		else
			r = m;
	}
	big.insert(big.begin() + l, pairs[0].first);


	//分段插入Jacob
	int inserted = 1; // 已经插入了 pend[0]
	int k = 2;

	while (inserted < (int)pairs.size())
	{
		int j_curr = jacobsthal(k);
		int	j_prev = jacobsthal(k-1);

		int	count = j_curr - j_prev;

		if (inserted + count > (int)pairs.size())
			count = pairs.size() - inserted;
		for (int i = count - 1; i >= 0; --i)
		{
			int	index = inserted + i;

			size_t	r = j_curr - 1;
			if (r > big.size())
				r = big.size();
			
			// 二分插入
			size_t l = 0;
			while (l < r) {
				_comparisons++;
				size_t m = (l + r) / 2;
				if (big[m] < pairs[index].first)
					l = m + 1;
				else
					r = m;
			}
			big.insert(big.begin() + l, pairs[index].first);
		}
	
		inserted += count;
		k++;
	}

	//插入剩下odd
	if (odd != -1)
	{
		size_t l = 0, r = big.size();
		while (l < r) {
			_comparisons++;
			size_t m = (l + r) / 2;
			if (big[m] < odd)
				l = m + 1;
			else
				r = m;
		}
		big.insert(big.begin() + l, odd);
	}

	v = big;
}

// ================= 输出比较次数 =================
void PmergeMe::printComparisons()
{
	std::cout << "\nTotal comparisons: " << _comparisons << "\n";
}