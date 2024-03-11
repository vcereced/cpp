/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:15:33 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 22:49:24 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//Constructors
DiamondTrap::DiamondTrap(void): ClapTrap("default_clap_name"), FragTrap("default_clap_name"), ScavTrap("default_clap_name")
{
	std::cout << "DiamondTrap " << this->name << " default constructor called" << std::endl;
	this->_name = "DefaultDiamondTrap";
	this->_hitPoint = FragTrap().getHitPoint();
	this->_energyPoint = ScavTrap().getEnergyPoint();
	this->_attackDamage = FragTrap().getAttackDamage();
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap " << this->name << " derived constructor called" << std::endl;
	this->name = name;
	this->_hitPoint = FragTrap().getHitPoint();
	this->_energyPoint = ScavTrap().getEnergyPoint();
	this->_attackDamage = FragTrap().getAttackDamage();
	
}

DiamondTrap::DiamondTrap(const DiamondTrap &ref): ClapTrap(ref), FragTrap(ref), ScavTrap(ref)
{
	std::cout << "DiamondTrap " << this->name << " derived copy constructor called" << std::endl;

	this->name = ref.name;
	this->_hitPoint = ref._hitPoint;
	this->_energyPoint = ref._energyPoint;
	this->_attackDamage = ref._attackDamage;
}

//overload copy assigment
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &ref)
{
	std::cout << "DiamondTrap " << this->name << " derived copy assigment called" << std::endl;
	if (this != &ref)
	{
		ClapTrap::operator= (ref);
		ScavTrap::operator= (ref);
		FragTrap::operator= (ref);
		this->name = ref.name;
		this->_hitPoint = ref._hitPoint;
		this->_energyPoint = ref._energyPoint;
		this->_attackDamage = ref._attackDamage;
	}
    return (*this);
}

// //Destructors
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->name << " derived destructor called" << std::endl;
}

//Method
void DiamondTrap::whoIam(void) const
{
	if(this->_hitPoint <= 0)
	{
		std::cout << "Not posible whoIam because DiamonTrap " << this->name << " is dead!" << std::endl;
	}
	else
	{
		std::cout << "DiamonTrap name = " << this->name << std::endl;
		std::cout << "ClapTrap name = " << ClapTrap::_name << std::endl;
	}
}

void DiamondTrap::attack(const std::string &tarjet) 
{
	ScavTrap::attack(tarjet);
}
