/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:58:23 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 17:05:49 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;


std::cout << "\nmore tests" << std::endl;
Fixed x;

x = Fixed(5) + Fixed(2);
std::cout << "5 + 2 = " << x << std::endl;
x = Fixed(5) - Fixed(2);
std::cout << "5 - 2 = " << x << std::endl;
x = Fixed(5) * Fixed(2);
std::cout << "5 * 2 = " << x << std::endl;
x = Fixed(5) / Fixed(2);
std::cout << "5 / 2 = " << x << std::endl;
x = Fixed(5) > Fixed(2);
std::cout << "5 > 2 = " << x << std::endl;
x = Fixed(5) != Fixed(2);
std::cout << "5 != 2 = " << x << std::endl;
x = Fixed(5) == Fixed(2);
std::cout << "5 == 2 = " << x << std::endl;


Fixed test = Fixed::min(Fixed(5), Fixed(2));
std::cout << "Fixed::min = " << test << std::endl;

Fixed test2 = Fixed::min(static_cast<const Fixed>(Fixed(5)), static_cast<const Fixed>(Fixed(2)));
std::cout << "const Fixed::min = " << test << std::endl;
return 0;
}