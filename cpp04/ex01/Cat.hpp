/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:43:33 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/29 17:17:03 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *brain;
	
	public:
		//Constructors
		Cat(void);
		Cat(const Cat &ref);

		//Destructors
		~Cat(void);
		
		//overload copy assigment
		Cat &operator=(const Cat &ref);

		//Method
		void makeSound(void) const;
		void setBrain(const std::string idea, const int index);
		Brain &getBrain(void) const;
};

#endif