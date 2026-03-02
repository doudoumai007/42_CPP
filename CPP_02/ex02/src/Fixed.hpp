#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_frac = 8;
		
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed(const int);
		Fixed(const float);
		Fixed& operator=(const Fixed& other);


		// Comparison operator
		bool			operator>(const Fixed& other) const;
		bool			operator<(const Fixed& other) const;
		bool			operator>=(const Fixed& other) const;
		bool			operator<=(const Fixed& other) const;
		bool			operator==(const Fixed& other) const;
		bool			operator!=(const Fixed& other)const;

		// Arithmetic operator
		Fixed 			operator+(const Fixed& other);
		Fixed			operator-(const Fixed& other);
		Fixed 			operator*(const Fixed& other);
		Fixed 			operator/(const Fixed& other);
		
		// Increment operator
		Fixed& 			operator++();
		Fixed 			operator++(int);
		Fixed& 			operator--();
		Fixed 			operator--(int);


		float				toFloat( void ) const;
		int					toInt( void ) const;
		int					getRawBits(void) const;
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		Fixed&				max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);


		// void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif