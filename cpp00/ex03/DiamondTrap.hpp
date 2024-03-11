/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:56:22 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 22:31:15 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	protected:
		std::string name;
	
	public:
		//Constructors
		DiamondTrap(void);
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap &ref);

		//Destructors
		~DiamondTrap(void);
		
		//overload copy assigment
		DiamondTrap &operator=(const DiamondTrap &ref);

		//Methods
		void whoIam(void) const;
		void attack(const std::string &);
};

#endif
