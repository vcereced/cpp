/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:14:01 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 22:37:14 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamond("X");
	diamond.whoIam();
	std::cout << "\nSTATS : \n";
	std::cout << "hitpoint = " << diamond.getHitPoint() << " energyPoint = " << diamond.getEnergyPoint() << " attackDamage = " << diamond.getAttackDamage() << std::endl; 
	
	std::cout << "\nPOLIMORPHIMS : \n";
	ClapTrap clap;
	ScavTrap scav;
	FragTrap frag;
	std::cout << "\nCOPY ASSIGMENT OVERLOAD : \n";
	clap = scav;
	clap = frag;
	clap = diamond;
	
return 0;
}
