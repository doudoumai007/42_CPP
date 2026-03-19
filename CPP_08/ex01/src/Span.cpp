#include "Span.hpp"

#include <stdexcept>
#include <algorithm>

Span::Span(): _size(0), _numbers() {}

Span::Span(unsigned int N): _size(N), _numbers() {}

Span::Span(const Span& other): _size(other._size), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_size = other._size;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int num)
{
	if (_numbers.size() == _size)
		throw std::runtime_error("Span is full");
	_numbers.push_back(num);
}

long long	Span::shortestSpan()
{
	//Size too small to compare
	if (_numbers.size() < 2)
		throw (std::runtime_error("Too few numbers"));
	
	//Prepare a copy container to traverse
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	//Traverse
	long long miniSpan = static_cast<long long>(tmp[1]) - static_cast<long long>(tmp[0]);
	for (size_t i = 1; i < _numbers.size() - 1; ++i)
	{
		if (static_cast<long long>(tmp[i + 1]) - static_cast<long long>(tmp[i]) < miniSpan)
			miniSpan = static_cast<long long>(tmp[i + 1]) - static_cast<long long>(tmp[i]);
	}
	return (miniSpan);
}


long long	Span::longestSpan()
{
	//Size too small to compare
	if (_numbers.size() < 2)
		throw (std::runtime_error("Too few numbers"));

	//Use std::min_element or std::max_element(in the algorithm)
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return (static_cast<long long>(max) - static_cast<long long>(min));
}