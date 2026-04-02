#include "PmergeMe.hpp"

#include <stdexcept>
#include <cstdlib>
#include <limits>
#include <iostream>

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
	if (_vec.size() > 1)
		sortVector(_vec);
	// if (_deq.size() > 1)
	// 	sortDeque(_deq);
}

std::vector<int> PmergeMe::generateJacobsthal(std::size_t n)
{
    std::vector<int> jac;
    jac.push_back(0);
    if (n == 1) return jac;
    jac.push_back(1);

    int i = 2;
    while (true) {
        size_t next = jac[i-1] + 2 * jac[i-2];
        if (next >= n)
            break;
        jac.push_back(next);
        i++;
    }
    return jac;
}

void	PmergeMe::sortVector(std::vector<int>& v)
{
if (v.size() <= 1) return;

	std::vector<int> big, small;

	// 两两分组
	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		_comparisons++; // 每对比较一次
		if (v[i] < v[i + 1])
		{
			small.push_back(v[i]);
			big.push_back(v[i + 1]);
		}
		else
		{
			small.push_back(v[i + 1]);
			big.push_back(v[i]);
		}
	}
	if (v.size() % 2 != 0)
		small.push_back(v.back());

	// 递归排序 big
	sortVector(big);
	sortVector(small);
	

 // Jacobsthal 序列生成
    std::vector<int> jac = generateJacobsthal(small.size());
    std::vector<bool> inserted(small.size(), false);

    // Jacobsthal 顺序插入 small
    for (size_t i = 1; i < jac.size(); ++i) {
        size_t idx = jac[i];
        if (idx < small.size()) {
            // 手动 lower_bound，统计比较次数
            size_t l = 0, r = big.size();
            while (l < r) {
                _comparisons++;
                size_t m = (l + r) / 2;
                if (big[m] < small[idx])
                    l = m + 1;
                else
                    r = m;
            }
            big.insert(big.begin() + l, small[idx]);
            inserted[idx] = true;
        }
    }

    // 剩余 small 元素按顺序插入
    for (size_t i = 0; i < small.size(); ++i) {
        if (!inserted[i]) {
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
    }

    v = big;
}

// ================= 输出比较次数 =================
void PmergeMe::printComparisons()
{
	std::cout << "Total comparisons: " << _comparisons << "\n";
}