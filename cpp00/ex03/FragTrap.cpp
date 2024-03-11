/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:26:41 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 21:04:41 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap " << this->getName() << " derived default constructor called" << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	std::cout << "FragTrap " << this->getName() << " derived constructor called" << std::endl;
	this->setHitPoint(100);
	this->setEnergyPoint(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap &ref): ClapTrap(ref)
{
	std::cout << "FragTrap " << this->getName() << " derived copy constructor called" << std::endl;
}

//Destructors
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->getName() << " derived destructor called" << std::endl;
}

//overload copy assigment
FragTrap &FragTrap::operator=(const FragTrap& ref)
{
	std::cout << "FragTrap " << this->getName() << " derived copy assigment called" << std::endl;
	if (this != &ref)
		ClapTrap::operator= (ref);
    return (*this);
}

//Method
void FragTrap::attack(const std::string &tarjet)
{
	if (this->getEnergyPoint() > 0 && this->getHitPoint() > 0)
	{
		std::cout << "FragTrap " << this->getName() << " attacks " << tarjet << ", causing 1 points of damage!" << std::endl;
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
	else
		std::cout << "FragTrap " << this->getName() << "can´t attack!, " << this->getEnergyPoint() << " energy, " << this->getHitPoint() << " hit points." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->getHitPoint() > 0)
	{
		std::cout << "FragTrap " << this->getName() << " high five!! " << std::endl;
	}
}