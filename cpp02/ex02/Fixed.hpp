/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:08:10 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 17:01:09 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

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
		
		//overload operator assigment 
		Fixed &operator=(const Fixed& ref);
		
		//overload class comparison operators
		bool operator>(const Fixed& ref) const;
		bool operator<(const Fixed& ref) const;
		bool operator>=(const Fixed& ref) const;
		bool operator<=(const Fixed& ref) const;
		bool operator==(const Fixed& ref) const;
		bool operator!=(const Fixed& ref) const;

		//overload class arithmetic operators
		Fixed operator+(const Fixed& ref) const;
		Fixed operator-(const Fixed& ref) const;
		Fixed operator*(const Fixed& ref) const;
		Fixed operator/(const Fixed& ref) const;

		// //overload class increment/decrement operators
		Fixed &operator++(void);
		Fixed &operator--(void );
		Fixed operator++(int);
		Fixed operator--(int);

		//static class methods
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);	
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
};

//overload operators outside of the class
std::ostream &operator<<(std::ostream& stream, const Fixed& ref);

#endif
