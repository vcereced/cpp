/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:47:24 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/20 17:19:45 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//Constructors
Cat::Cat(void): Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &ref): Animal(ref)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*ref.brain);
}

//Destructors
Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}
		
//overload copy assigment
Cat &Cat::operator=(const Cat &ref)
{
	if(this != &ref)
	{
		Animal::operator= (ref);
		*this->brain = *ref.brain;
	}
	return (*this);
}

//Method
void Cat::makeSound(void) const
{
	std::cout << "Miau Miau rrrrrr!!" << std::endl;
}

void Cat::setBrain(const std::string idea, const int index)
{
	this->brain->setIdea(idea, index);
}

Brain &Cat::getBrain(void) const
{
	return (*this->brain);
}