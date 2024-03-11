/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:50:49 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 20:17:11 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap " << this->getName() << " derived default constructor called" << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap " << this->getName() << " derived constructor called" << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(50);
	this->setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap &ref): ClapTrap(ref)
{
	std::cout << "ScavTrap " << this->getName() << " derived copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& ref)
{
	std::cout <<"ScavTrap " << this->getName() << " derived copy assigment called" << std::endl;
	if (this != &ref)
		ClapTrap::operator= (ref);
    return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->getName() << " derived destructor called" << std::endl;
}

//Method
void ScavTrap::attack(const std::string &tarjet)
{
	if (this->getEnergyPoint() > 0 && this->getHitPoint() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << tarjet << ", causing 1 points of damage!" << std::endl;
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
	else
		std::cout << "ScavTrap " << this->getName() << "can´t attack!, " << this->getEnergyPoint() << " energy, " << this->getHitPoint() << " hit points." << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->getHitPoint() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;	
	}
	else
		std::cout << "ScavTrap " << this->getName() << "can´t gate keep because is dead!" << std::endl;
}

