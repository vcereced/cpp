/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:13:28 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 22:13:05 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define  FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		//Constructors
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap &ref);

		//Destructors
		~FragTrap(void);
		
		//overload copy assigment
		FragTrap &operator=(const FragTrap &ref);

		//Methods
		void attack(const std::string &name);
		void highFivesGuys(void);
};

#endif