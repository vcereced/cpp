/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:08:14 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/29 17:20:19 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	protected:
		std::string type;
	
	public:
		//Constructors
		WrongCat(void);
		WrongCat(const std::string name);
		WrongCat(const WrongCat &ref);

		//Destructors
		~WrongCat(void);
		
		//overload copy assigment
		WrongCat &operator=(const WrongCat &ref);

		//Method
		void makeSound(void) const;
		std::string getType(void) const;
		void		setType(std::string type);
};

#endif