/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:15:34 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/20 00:18:07 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//Constructors
WrongCat::WrongCat(void): WrongAnimal(), type("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string name): WrongAnimal("none"), type(name)
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &ref): WrongAnimal(ref)
{
	this->setType(ref.getType());
	std::cout << "WrongCat copy constructor called" << std::endl;
}

//Destructors
WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}
		
//overload copy assigment
WrongCat &WrongCat::operator=(const WrongCat &ref)
{
	if(this != &ref)
	{
		WrongAnimal::operator= (ref);
		this->setType(ref.getType());
	}
	return *this;
}

//Method
void WrongCat::makeSound(void) const
{
	std::cout << "WRONG Miuauu!!" << std::endl;
}

std::string WrongCat::getType(void) const
{
	return(this->type);
}

void WrongCat::setType(std::string type)
{
	this->type = type;
}
