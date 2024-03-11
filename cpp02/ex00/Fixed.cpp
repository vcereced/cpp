/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:40:44 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 14:01:18 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructors
Fixed::Fixed(void): _fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;	
}

Fixed::Fixed(Fixed const &ref)
{
	std::cout << "Copy constructor called" << std::endl;	
	this->_fixedValue = ref.getRawBits();
}

//Destructors
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;	
}

//Overload assigment operator
Fixed &Fixed::operator=(const Fixed& ref)
{
	std::cout << "Copy assignemt operator called" << std::endl;
    this->_fixedValue = ref.getRawBits();
    return *this;
}

//Methods
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;	
	return this->_fixedValue;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedValue = raw;
}

int Fixed::getFrationalBits(void)
{
	std::cout << "getFrationalBits static member function called" << std::endl;
	return Fixed::_fractionalBits;
}
