#pragma once

#include <vector>
#include <deque>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		long				_comparisons;

		std::vector<int> generateJacobsthal(std::size_t n);

	public:
		PmergeMe(char *av[]);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe() {}

		void	sort();
		void	sortVector(std::vector<int>& _vec);
		// void	sortDeque(std::deque<int> _deq);
		void	printComparisons();

};
