#pragma once

#include <vector>
#include <deque>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		template <typename T>
		void	_swap_pair(T this_start, T next_start, int level)
		{
			for (int i = 0; i < level; ++i)
			{
				std::iter_swap(this_start, next_start);
				++this_start;
				++next_start;
			}
		}

	public:
		PmergeMe(char *av[]);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe() {}

		void	sort();
		void	sortVector(std::vector<int>& _vec, int level);
		// void	sortDeque(std::deque<int> _deq);
		void	printComparisons();

		static long	_comparisons;

};

template <typename T>
bool	_comp(T left_value, T right_value)
{
	PmergeMe::_comparisons++;
	return (*left_value < *right_value);
}

