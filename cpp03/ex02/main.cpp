/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:14:01 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 21:58:41 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap clap("CLAP");
	ScavTrap scav("SCAV");
	FragTrap frag("FRAG");

	clap.attack("X");
	scav.ClapTrap::attack("X");
	scav.attack("X");
	frag.ClapTrap::attack("X");
	frag.attack("X");
	
	frag.highFivesGuys();
	scav.guardGate();
return 0;
}