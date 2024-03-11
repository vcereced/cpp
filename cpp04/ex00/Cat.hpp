/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:43:33 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/18 19:51:21 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat: public Animal
{
	protected:
		std::string type;
	
	public:
		//Constructors
		Cat(void);
		Cat(const std::string name);
		Cat(const Cat &ref);

		//Destructors
		~Cat(void);
		
		//overload copy assigment
		Cat &operator=(const Cat &ref);

		//Method
		void makeSound(void) const;
		std::string getType(void) const;
		void		setType(std::string type);
};

#endif