/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:05:07 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 20:08:13 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref): AForm(ref), _target(ref._target)
{
	std::cout << this->getName() << " copy  constructor called" << std::endl;
}

//Destructor
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

//overload copy assigment
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	if (this != &ref)
	{
		PresidentialPardonForm::AForm::operator=(ref);
	}
	std::cout << "Form" << this->getName() << " operator constructor called" << std::endl;
	return *this;
}

//getters
std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

//Method
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExeGrade())
		throw(AForm::GradeTooLowException());
	else if (this->getSigned() == false)
		throw(AForm::FormNotSignedException());
	std::cout << GREEN << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}