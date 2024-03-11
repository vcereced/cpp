/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:28:49 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 22:13:11 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		//Constructors
		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &ref);

		//Destructors
		~ScavTrap(void);
		
		//overload copy assigment
		ScavTrap &operator=(const ScavTrap &ref);
		
		//Methods
		void attack(const std::string &name);
		void guardGate(void);

};

#endif