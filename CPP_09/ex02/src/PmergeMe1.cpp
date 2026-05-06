#include "PmergeMe1.hpp"

#include <stdexcept>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <utility> // std::pair
#include <cmath>
#include <algorithm> // std::upper_bound

long	PmergeMe::_comparisons = 0;

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
	_vec = other._vec;
	_deq = other._deq;
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
	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];

	sortVector(_vec, 1);

	std::cout << "\nAfter:  ";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	// if (_deq.size() > 1)
	// 	sortDeque(_deq);
}


int	jacobsthal(int k)
{
	// J(k) = (2^(k+1) + (-1)^k) / 3
	return (int)((pow(2, k + 1) + pow(-1, k)) / 3);
}

void	PmergeMe::sortVector(std::vector<int>& v, int level)
{
	typedef typename std::vector<int>::iterator iterator;
	typedef typename std::vector<iterator>::iterator iterator_it;

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
	// end: last element of the last block
	iterator start = v.begin();
	iterator end = v.begin() + ((block_nbr - is_odd) * level);

	// 🟢 Compare two next blocks' big and swap 2 blocks
	for (iterator it = start; it + (level * 2) <= end; it += (level * 2))
	{
		_comparisons++;
		// 2 blocks: first block & next block
		iterator this_start = it;
		iterator this_end = it + level - 1;
		iterator next_start = it + level;
		iterator next_end = it + (level * 2) - 1;

		if (*this_end > *next_end)
			_swap_pair(this_start, next_start, level);
	}

	// 🟢 Recursive until tehre are only 2 biggest blocks
	sortVector(v, level * 2);
	// std::cout << "\nAfter Swapping: ";
	// for (size_t i = 0; i < _vec.size(); ++i)
	// 	std::cout << " " << _vec[i];

	// 🟢 Every recursive we rebuild the main and the pend
	// Main and pend are container of iterator
	std::vector<iterator> main;
	std::vector<iterator> pend;

	// Initialize the main chain with the first 2 blocks: a1, b1
	// Because b1 is the smallest in b group and a1 is definately smaller than b1
	// (For the biggest level, just put both of the big blocks directly)
	main.push_back(v.begin() + level - 1);
	main.push_back(v.begin() + level * 2 - 1);

	// According to the current level, we put main and pend chain
	// Jump the first 2 blocks(a1 b1)
	// Everytime increment level*2 elements (to jump 2 blocks)
	// Put the first block in pend and the second block in main
	for (iterator it = start + 2 * level; it + level * 2 <= end; it += level * 2)
	{
		iterator first_block = it;
		iterator second_block = it + level;

		pend.push_back(first_block + level - 1);
		main.push_back(second_block + level - 1);
	}

	// Put the odd block in pend
	if (is_odd)
		pend.push_back(end + level - 1);

	// 🟢 Insert according to the Jacobsthal sequence
	int	prev_jacobsthal = jacobsthal(1);
	int inserted_numbers = 0;
	// As we already put a1 to the main, so we the sequence in main starts from k=2->3
	for (int k = 2;; ++k)
	{
		// Current jacobsthal decides the searching scale
		int curr_jacobsthal = jacobsthal(k);
		// Jacobsthal diff decides how many element to insert once
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		// offset check if the inserded element pushed back the bound
		int offset = 0;

		if (jacobsthal_diff > static_cast<int>(pend.size()))
			break ;
		int i = jacobsthal_diff;
		iterator_it pend_it = pend.begin() + jacobsthal_diff - 1;
		iterator_it bound_it = main.begin() + curr_jacobsthal + inserted_numbers;

		while (i--)
		{
			// Use _comp to do the comparision of value
			iterator_it idx = std::upper_bound(main.begin(), bound_it, *pend_it, _comp<iterator>);

			// Insert the pend element to main
			iterator_it inserted = main.insert(idx, *pend_it);

			// Erase the pend element from pend and put the iterator pointing the element in front
			pend_it = pend.erase(pend_it);
			if (!pend.empty() && pend_it != pend.begin())
				pend_it--;
			if ((inserted - main.begin()) == curr_jacobsthal + inserted_numbers)
				offset = 1;
			bound_it = main.begin() + curr_jacobsthal + inserted_numbers - offset;
		}
		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
		offset = 0;
	}
	
	// 🟢 Insert the remainning elements in reversed order
	for (ssize_t i = pend.size() - 1; i >= 0; --i)
	{
		iterator_it curr_pend = pend.begin() + i;
		iterator_it idx= std::upper_bound(main.begin(), main.end(), *curr_pend, _comp<iterator>);
		main.insert(idx, *curr_pend);
	}

	// 🟢 Rebuild the vector by the order saved in main 
	// (!!! main just save the address, not the value)
	std::vector<int> copy;
	copy.reserve(v.size());
	for (iterator_it it = main.begin(); it != main.end(); ++it)
	{
		iterator block_start = *it - level + 1;
		for (int i = 0; i < level; ++i)
			copy.push_back(*(block_start + i));
	}
	// Replace
	iterator v_it = v.begin();
	for (iterator copy_it = copy.begin(); copy_it != copy.end(); ++copy_it)
	{
		*v_it = *copy_it;
		++v_it;
	}

	// std::cout << "\nAfter Pending: ";
	// for (size_t i = 0; i < _vec.size(); ++i)
	// 	std::cout << " " << _vec[i];
}

// ================= 输出比较次数 =================
void PmergeMe::printComparisons()
{
	std::cout << "\nTotal comparisons: " << _comparisons << "\n";
}



// https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91