#pragma once

#include <vector>
#include <deque>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		long				_comparisons;

		template <typename T>
		void	_swap_pair(T this_start, T next_start)
		{
			while (this_start != next_start)
			{
				std::iter_swap(this_start, next_start);
				++this_start;
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



};

