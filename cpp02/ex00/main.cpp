/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:58:23 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 14:08:20 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << "EXTRA TEST: CALL TO STATIC MEMBER FUNCTION WITH AN OBJECT OR CLASS SCOPE;" << std::endl;
	std::cout << a.getFrationalBits() << std::endl; //error !
	std::cout << Fixed::getFrationalBits() << std::endl;
	return (0);
}