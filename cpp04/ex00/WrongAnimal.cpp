/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:11:47 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/20 00:16:56 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("none")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string name): type(name)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	this->setType(ref.getType());
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

//overload copy assigment
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &ref)
{
	if (this != &ref)
        this->setType(ref.getType());
	std::cout << "WrongAnimal operator constructor called" << std::endl;
    return *this;
}
//Destructors
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
		
//Method
std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::setType(std::string type)
{
	this->type = type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "wrrrooonnggg Animal sound" << std::endl;
}