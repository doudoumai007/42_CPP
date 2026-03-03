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

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		_rawBits = other.getRawBits();
	return (*this);
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

float	Fixed::toFloat() const
{
	// std::cout << "toFloat called\n";
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
