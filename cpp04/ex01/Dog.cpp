/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:26:48 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/20 17:19:36 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

//Constructors
Dog::Dog(void): Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &ref): Animal(ref)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*ref.brain);
}

//Destructors
Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}
		
//overload copy assigment
Dog &Dog::operator=(const Dog &ref)
{
	std::cout << "Dog derived copy assigment called" << std::endl;
	if (this != &ref)
	{
		Animal::operator= (ref);
		*this->brain = *ref.brain;
	}
    return (*this);
}

//Method
void Dog::makeSound(void) const
{
	std::cout << "Guau Guau GGRRR!!" << std::endl;
}

void Dog::setBrain(const std::string idea, const int index)
{
	this->brain->setIdea(idea, index);
}

Brain &Dog::getBrain(void) const
{
	return (*this->brain);
}