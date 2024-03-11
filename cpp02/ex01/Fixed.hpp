/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:08:10 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 14:10:24 by vcereced         ###   ########.fr       */
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
		Fixed(const int _fixedValue);
		Fixed(const float _fixedValue);
		Fixed(Fixed const &ref);
		
		//Destructors
		~Fixed(void);
		
		//Methods
		float toFloat( void ) const;
		int toInt( void ) const;
		
		//setters & getters
		int getRawBits(void) const;
		void setRawBits(const int raw);
		
		//overload class operators
		Fixed &operator=(const Fixed& ref);
		
};

//overload operators outside of the class
std::ostream &operator<<(std::ostream& stream, const Fixed& ref);

#endif
