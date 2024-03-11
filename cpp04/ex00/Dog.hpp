/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:04:59 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 23:39:55 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"

class Dog: public Animal
{
	protected:
		std::string type;
	
	public:
		//Constructors
		Dog(void);
		Dog(const std::string name);
		Dog(const Dog &ref);

		//Destructors
		~Dog(void);
		
		//overload copy assigment
		Dog &operator=(const Dog &ref);

		//Method
		void makeSound(void) const;
		 std::string getType(void) const;
		 void		setType(std::string type);
};

#endif