#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _rawBits(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	*this = other; // call Copy assignment operator but NOT obligatory
	
	// 👇Make more sense//
	// _rawBits = other.getRawBits();
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	_rawBits = value << _frac;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	_rawBits = roundf(value * (1 << _frac));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		_rawBits = other.getRawBits();
	return (*this);
}


/////////////// Comparison operator //////////////////
bool	Fixed::operator>(const Fixed& other) const
{
	// > is a bool type expression,
	return (this->_rawBits > other._rawBits);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_rawBits < other._rawBits);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_rawBits == other._rawBits);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_rawBits != other._rawBits);
}


/////////////// Arithmetic operator ////////////////
Fixed Fixed::operator+(const Fixed& other)
{
	return(Fixed(this->_rawBits + other._rawBits));
}

Fixed Fixed::operator-(const Fixed& other)
{
	return(Fixed(this->_rawBits - other._rawBits));
}

Fixed Fixed::operator*(const Fixed& other)
{
	Fixed res;
	res._rawBits = (int64_t(_rawBits) * int64_t(other._rawBits)) >> _frac;
	return (res);
}

Fixed Fixed::operator/(const Fixed& other)
{
	Fixed res;
	res._rawBits = ((int64_t(_rawBits) << _frac) / int64_t(other._rawBits)) >> _frac;
	return (res);
}

/////////////// Increment operator ////////////////
Fixed& Fixed::operator++()
{
	_rawBits += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	_rawBits += 1;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	_rawBits -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	_rawBits -= 1;
	return (tmp);
}


/////////////// Min Max ////////////////
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}



float	Fixed::toFloat() const
{
	std::cout << "toFloat called\n";
	return (static_cast<float>(_rawBits) / (1 << _frac));
}

int	Fixed::toInt() const
{
	return (_rawBits / (1 << _frac));
}

int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called\n";
	return (_rawBits);
}

// void	Fixed::setRawBits(int const raw)
// {
// 	std::cout << "setRawBits member function called\n";
// 	_rawBits = raw;
// }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
