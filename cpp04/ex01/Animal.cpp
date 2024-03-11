/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:50:29 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/20 20:56:56 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): type("none")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string name): type(name)
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &ref)
{
	this->type = ref.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

//overload copy assigment
Animal &Animal::operator=(const Animal &ref)
{
	if (this != &ref)
	{
        this->type = ref.getType();
		this->getBrain() = ref.getBrain();
	}
	std::cout << "Animal operator constructor called" << std::endl;
    return (*this);
}
//Destructors
Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}
		
//Method
std::string Animal::getType(void) const
{
	return(this->type);
}

void Animal::setType(std::string type)
{
	this->type = type;
}

void Animal::makeSound(void) const
{
	std::cout << "I DONT KNOW WHAT I AM!, CUAK" << std::endl;
}
