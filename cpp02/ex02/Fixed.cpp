/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:40:44 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 16:55:09 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructors
Fixed::Fixed(void): _fixedValue(0) {}

Fixed::Fixed(const int _fixedValue)
{
	this->setRawBits(_fixedValue << Fixed::_fractionalBits);
}

Fixed::Fixed(const float _fixedValue)
{
	this->setRawBits(roundf(_fixedValue * (1  << Fixed::_fractionalBits)));
}

Fixed::Fixed(Fixed const &ref)
{
	*this = ref;
}

//Destructors
Fixed::~Fixed(void) {}

//Methods
int Fixed::toInt( void ) const
{
	return this->_fixedValue >> Fixed::_fractionalBits;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fixedValue) / (1 << Fixed::_fractionalBits);
}

//setters & getters
int Fixed::getRawBits(void) const
{
	return this->_fixedValue;
}

void Fixed::setRawBits(const int raw)
{
	this->_fixedValue = raw;
}

//overload operators
Fixed &Fixed::operator=(const Fixed& ref)
{
    this->_fixedValue = ref.getRawBits();
    return *this;
}

//overload class comparison operators
bool Fixed::operator>(const Fixed& ref) const
{
	return this->_fixedValue > ref.getRawBits() ? true : false;
}

bool Fixed::operator<(const Fixed& ref) const
{
	return this->_fixedValue < ref.getRawBits() ? true : false;
}
bool Fixed::operator>=(const Fixed& ref) const
{
	return this->_fixedValue >= ref.getRawBits() ? true : false;
}
bool Fixed::operator<=(const Fixed& ref) const
{
	return this->_fixedValue <= ref.getRawBits() ? true : false;
}

bool Fixed::operator==(const Fixed& ref) const
{
	return this->_fixedValue == ref.getRawBits() ? true : false;
}
bool Fixed::operator!=(const Fixed& ref) const
{
	return this->_fixedValue != ref.getRawBits() ? true : false;
}

//overload class arithmetic operators
Fixed Fixed::operator+(const Fixed& ref) const
{
	return Fixed(this->toFloat() + ref.toFloat());
}

Fixed Fixed::operator-(const Fixed& ref) const
{
	return Fixed(this->toFloat() - ref.toFloat());
}

Fixed Fixed::operator*(const Fixed& ref) const
{
	return Fixed(this->toFloat() * ref.toFloat());
}

Fixed Fixed::operator/(const Fixed& ref) const
{
	return Fixed (this->toFloat() / ref.toFloat());	
}

// //overload class increment/decrement operators
Fixed &Fixed::operator++(void)//pre-increment
{
	this->_fixedValue++;
	return *this;
}

Fixed &Fixed::operator--(void)//pre-increment
{
	this->_fixedValue--;
	return *this;
}
Fixed Fixed::operator++(int)//post-increment
{
	Fixed temp(*this);
	
	temp._fixedValue = this->_fixedValue;
	this->_fixedValue++;
	return temp;
}

Fixed Fixed::operator--(int)//post-increment
{
	Fixed temp(*this);
	
	temp._fixedValue = this->_fixedValue;
	this->_fixedValue--;
	return temp;
}

//static class methods
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits()) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits()) ? a : b;
}

//overload operator outside of the class Fixed
std::ostream &operator<<(std::ostream& stream, const Fixed& ref)
{
    stream << ref.toFloat();
    return stream;
}