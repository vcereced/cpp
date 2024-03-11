/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:26:48 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 23:42:52 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//Constructors
Dog::Dog(void): Animal(), type("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const std::string name): Animal("none"), type(name)
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &ref): Animal(ref)
{
	this->setType(ref.getType());
	std::cout << "Dog copy constructor called" << std::endl;
}

//Destructors
Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}
		
//overload copy assigment
Dog &Dog::operator=(const Dog &ref)
{
	std::cout << "Dog derived copy assigment called" << std::endl;
	if (this != &ref)
	{
		Animal::operator= (ref);
		this->setType(ref.getType());
	}
    return *this;
}

//Method
void Dog::makeSound(void) const
{
	std::cout << "Guau Guau GGRRR!!" << std::endl;
}

std::string Dog::getType(void) const
{
	return this->type ;
}

void Dog::setType(std::string type)
{
	this->type = type;
}