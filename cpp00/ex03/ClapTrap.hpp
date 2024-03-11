/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:42:49 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 19:53:12 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class ClapTrap{
	protected:
		std::string _name;
		int			_hitPoint;
		int			_energyPoint;
		int			_attackDamage;
	
	public:
		//Constructors
		ClapTrap(void);
		ClapTrap(const std::string );
		ClapTrap(const ClapTrap &);
		
		//overload copy assigment
		ClapTrap &operator=(const ClapTrap&);
		
		//Destructors
		~ClapTrap(void);
		
		//Methods
		void attack(const std::string &);
		void takeDamage(unsigned int);
		void beRepaired(unsigned int);

		//getters & setters
		std::string getName() const ;
		int getHitPoint()  const;
		int getEnergyPoint() const;
		int getAttackDamage() const;
		void setName(std::string);
		void setHitPoint(int);
		void setEnergyPoint(int);
		void setAttackDamage(int);
};

#endif
