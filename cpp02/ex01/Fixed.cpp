/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:40:44 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 16:19:53 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//	Constructors
Fixed::Fixed(void): _fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;	
}

Fixed::Fixed(const int _fixedValue)											  //compiler allows bit shifting in int type
{
	std::cout << "Int constructor called" << std::endl;						  //    int * 1^fractionBits = int | int * 1^fractionBits = int
	this->_fixedValue = (_fixedValue << Fixed::_fractionalBits);			  //ej: 10  * 2 			 = 20  |  10 * 8 		      = 80  ...
}

Fixed::Fixed(const float _fixedValue)										  //compiler doesn´t allows bit shifting in float type
{
	std::cout << "Float constructor called" << std::endl;					  //   float * 1^fractionBits = int | float * 1^fractionBits = int | float  * 1^fractionBits = int
	this->_fixedValue = roundf(_fixedValue * (1  << Fixed::_fractionalBits)); //ej: 10.5 * 2   			  = 21  | 10.25 * 4 			 = 41  | 10,125 * 8 			 = 81  ...
}

Fixed::Fixed(Fixed const &ref)
{
	std::cout << "Copy constructor called" << std::endl;	
	this->_fixedValue = ref.getRawBits();
}

//	Destructors
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;	
}

//	Methods
int Fixed::toInt( void ) const													//compiler allows bit shifting in int type
{																				//    int / 1^fractionBits = int | int / 1^fractionBits = int
	return this->_fixedValue >> Fixed::_fractionalBits;							//ej: 10  / 2 			   = 20  |  10 / 8 				= 80  ...
}

float Fixed::toFloat(void) const												 //compiler doesn´t allows bit shifting in float type
{
	return static_cast<float>(this->_fixedValue) / (1 << Fixed::_fractionalBits);//   int / 1^fractionBits = float | int / 1^fractionBits = float | int / 1^fractionBits = float
}																				 //ej: 21 / 2 			   = 10.5  | 41  / 4 		      = 10.25 | 81  / 8 			 = 10,125 ...

//	setters & getters
int Fixed::getRawBits(void) const
{
	return this->_fixedValue;
}

void Fixed::setRawBits(const int raw)
{
	this->_fixedValue = raw;
}

//	overload operators
Fixed &Fixed::operator=(const Fixed& ref)
{
	std::cout << "Copy assignemt operator called" << std::endl;
    this->_fixedValue = ref.getRawBits();
    return *this;
}

//outside of the class Fixed
std::ostream &operator<<(std::ostream& stream, const Fixed& ref)
{
    stream << ref.toFloat();
    return (stream);
}
