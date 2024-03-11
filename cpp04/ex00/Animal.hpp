/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:58:57 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 23:51:48 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal{
	protected:
		std::string type;
	
	public:
		//Constructors
		Animal(void);
		Animal(const std::string name);
		Animal(const Animal &ref);

		//Destructors
		virtual ~Animal(void);
		
		//overload copy assigment
		Animal &operator=(const Animal &ref);
		
		//Method
		std::string getType(void) const;
		void		setType(std::string type);
		virtual void makeSound(void) const;
};

#endif