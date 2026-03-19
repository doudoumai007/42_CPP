#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
	private:
		unsigned int _size;
		std::vector<int> _numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void		addNumber(int num);
		//long long to avoid overflow
		long long	shortestSpan();
		long long	longestSpan();

		// Iterator is a type placeholder
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			// Calculate how many elements
			size_t distance = std::distance(begin, end);

			// Safty check for size
			if (_numbers.size() + distance > _size)
				throw std::runtime_error("Span will overflow");

			// Insert
			_numbers.insert(_numbers.end(), begin, end);
		}
};



#endif