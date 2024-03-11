/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:47:24 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 23:43:19 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//Constructors
Cat::Cat(void): Animal(), type("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const std::string name): Animal("none"), type(name)
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &ref): Animal(ref)
{
	this->setType(ref.getType());
	std::cout << "Cat copy constructor called" << std::endl;
}

//Destructors
Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}
		
//overload copy assigment
Cat &Cat::operator=(const Cat &ref)
{
	if(this != &ref)
	{
		Animal::operator= (ref);
		this->setType(ref.getType());
	}
	return *this;
}

//Method
void Cat::makeSound(void) const
{
	std::cout << "Miau Miau rrrrrr!!" << std::endl;
}

std::string Cat::getType(void) const
{
	return(this->type);
}

void Cat::setType(std::string type)
{
	this->type = type;
}
