/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:50:29 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/20 20:34:10 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(void): type("none")
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string name): type(name)
{
	std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &ref)
{
	this->type = ref.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

//overload copy assigment
AAnimal &AAnimal::operator=(const AAnimal &ref)
{
	if (this != &ref)
        this->type = ref.getType();
	std::cout << "Animal operator constructor called" << std::endl;
    return (*this);
}
//Destructors
AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}
		
//Method
std::string AAnimal::getType(void) const
{
	return(this->type);
}

void AAnimal::setType(std::string type)
{
	this->type = type;
}
