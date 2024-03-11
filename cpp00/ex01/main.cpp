/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:14:01 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 21:51:28 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)						//Constructor ClapTrap hit 10,  energy 10, attack 0
{									//Constructor ScavTrap hit 100, energy 50, attack 20
	ClapTrap clap("CLAP");
	ScavTrap scav("SCAV");
	
	std::cout << "\nCLASS INHERIT THE METHOD." << std::endl;
	std::cout << scav.ClapTrap::getHitPoint() << std::endl;
	std::cout << scav.ScavTrap::getHitPoint() << std::endl;

	//Claptrap {				ScavTrap {
	//		    attack();   			  attack();
	//		    takeDamage();			  guardGate();}
	//		    beRepaired;}	
	std::cout << "\nBOTH CLASS HAVE SAME METHOD." << std::endl;		  
	clap.ClapTrap::attack("X");
	scav.ClapTrap::attack("X");
	scav.ScavTrap::attack("X");

	//Polimorphism
	std::cout << "\nPOLIMORPHISM" << std::endl;	
	std::cout << clap.ClapTrap::getHitPoint() << std::endl;
	//allow only up-casting BASE = DERIVED.
	clap = scav;
	//error not allow down-casting DERIVED = BASE
	//scav = clap;
	std::cout << clap.getHitPoint() << std::endl;
	
	return 0;
}