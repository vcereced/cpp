/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:58:57 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/20 20:33:48 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <string>
# include <iostream>

class AAnimal{
	protected:
		std::string type;
	
	public:
		//Constructors
		AAnimal(void);
		AAnimal(const std::string name);
		AAnimal(const AAnimal &ref);

		//Destructors
		virtual ~AAnimal(void);
		
		//overload copy assigment
		AAnimal &operator=(const AAnimal &ref);
		
		//Method
		std::string getType(void) const;
		void		setType(std::string type);
		virtual void makeSound(void) const = 0;
		/*virtual*/
};

#endif