/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:09:12 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/20 00:11:36 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	
	public:
		//Constructors
		WrongAnimal(void);
		WrongAnimal(const std::string name);
		WrongAnimal(const WrongAnimal &ref);

		//Destructors
		virtual ~WrongAnimal(void);
		
		//overload copy assigment
		WrongAnimal &operator=(const WrongAnimal &ref);
		
		//Method
		std::string getType(void) const;
		void		setType(std::string type);
		virtual void makeSound(void) const;
};


#endif
