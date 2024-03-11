/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:04:59 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/29 17:17:38 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
	private:
		Brain *brain;
	
	public:
		//Constructors
		Dog(void);
		Dog(const Dog &ref);

		//Destructors
		~Dog(void);
		
		//overload copy assigment
		Dog &operator=(const Dog &ref);

		//Method
		void makeSound(void) const;
		void setBrain(const std::string idea, const int index);
		const Brain &getBrain(void) const;

};

#endif
