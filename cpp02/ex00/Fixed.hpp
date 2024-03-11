/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:08:10 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 14:02:02 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed{
	private:
		int _fixedValue;
		static const int _fractionalBits = 8;
		
	public:
		//Constructors
		Fixed(void);
		Fixed(Fixed const &ref);
		
		//Destructors
		~Fixed(void);
		
		//Overload assigment operator
		Fixed &operator=(const Fixed& ref);
		
		//Methods	
		int getRawBits(void) const;
		void setRawBits(const int raw);
		static int getFrationalBits(void);
};

#endif