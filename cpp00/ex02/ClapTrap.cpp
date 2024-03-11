/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:05:17 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 22:25:56 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//Constructors
ClapTrap::ClapTrap(void): _name("default"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->getName() << " Default constructor called" << std::endl;	
}

ClapTrap::ClapTrap(const std::string name): _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->getName() << " Constructor called" << std::endl;	
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	std::cout << "ClapTrap " << "Copy constructor called" << std::endl;
	this->setName(ref._name);
	this->setHitPoint(ref._hitPoint);
	this->setEnergyPoint(ref._energyPoint);
	this->setAttackDamage(ref._attackDamage);
}

//overload copy assigment
ClapTrap &ClapTrap::operator=(const ClapTrap& ref)
{
	std::cout << "ClapTrap " << this->getName() << " Copy assigment called" << std::endl;
	if (this != &ref)
	{
        this->setName(ref._name);
		this->setHitPoint(ref._hitPoint);
		this->setEnergyPoint(ref._energyPoint);
		this->setAttackDamage(ref._attackDamage);
    }
    return *this;
}

//Destructors
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->getName() << " destructor called" << std::endl;
}

//Methods
void ClapTrap::attack(const std::string &tarjet)
{
	if (this->getEnergyPoint() > 0 && this->getHitPoint() > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << tarjet << ", causing 1 points of damage!" << std::endl;
		this->setEnergyPoint(this->getEnergyPoint() - 1);
	}
	else
		std::cout << "ClapTrap " << this->getName() << "can´t attack!, " << this->getEnergyPoint() << " energy, " << this->getHitPoint() << " hit points." << std::endl;
	
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoint() > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " take " << amount << " damage!" << std::endl;
		
		this->setHitPoint(this->getHitPoint() - amount);
	}
	if (this->getHitPoint() <= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is dead! " << std::endl;
		this->setHitPoint(0);
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoint() > 0 && this->_hitPoint > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " repairs itself " << amount << " hit points!" << std::endl;
		this->setEnergyPoint(this->getEnergyPoint() - 1);
		this->setHitPoint(this->getHitPoint() + amount);
	}
	else
		std::cout << "ClapTrap" << this->getName() << "can´t repair!, " << this->getEnergyPoint() << " energy, " << this->getHitPoint() << " hit points." << std::endl;
}

//getters & setters
std::string ClapTrap::getName(void) const
{
	return this->_name;	
}
int ClapTrap::getHitPoint(void) const
{
	return this->_hitPoint;	
}
int ClapTrap::getEnergyPoint(void) const
{
	return this->_energyPoint;	
}
int ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;	
}
void ClapTrap::setName(std::string name)
{
	this->_name = name;
}
void ClapTrap::setHitPoint(int n)
{
	this->_hitPoint = n;
}
void ClapTrap::setEnergyPoint(int n)
{
	this->_energyPoint = n;
}
void ClapTrap::setAttackDamage(int n)
{
	this->_attackDamage = n;
}
