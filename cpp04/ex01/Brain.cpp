/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:00:41 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/19 12:29:18 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

//Constructors
Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}
Brain::Brain(const Brain &ref)
{
	std::cout << "Brain default constructor called" << std::endl;
	std::copy(std::begin(ref.ideas), std::end(ref.ideas), std::begin(this->ideas));
}

//Destructors
Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

//overload copy assigment
Brain &Brain::operator=(const Brain &ref)
{
	std::cout << "Brain operator constructor called" << std::endl;
	if (this != &ref)
       std::copy(std::begin(ref.ideas), std::end(ref.ideas), std::begin(this->ideas));
    return (*this);
}

//getters & setters
const std::string Brain::getIdea(const int index) const
{
	return (this->ideas[index]);
}

void Brain::setIdea(const std::string idea, const int index)
{
	this->ideas[index] = idea;
}
