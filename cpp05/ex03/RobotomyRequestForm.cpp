/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:26:27 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 20:08:39 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref): AForm(ref), _target(ref._target)
{
	std::cout << this->getName() << " copy  constructor called" << std::endl;
}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

//overload copy assigment
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	if (this != &ref)
	{
		RobotomyRequestForm::AForm::operator=(ref);
	}
	std::cout << "Form" << this->getName() << " operator constructor called" << std::endl;
	return *this;
}

//getters
std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

//Method
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExeGrade())
		throw(AForm::GradeTooLowException());
	else if (this->getSigned() == false)
		throw(AForm::FormNotSignedException());
	/* Set Seed  for ramdon n*/
	srand(time(NULL));
	if (rand() % 2)
		std::cout << GREEN"XWRXWXWRXWR " << this->getTarget() << " have been robotomized!" << RESET << std::endl;
	else
		std::cout << GREEN"XWRXWXWRXWR " << this->getTarget() << " have not been robotomized! XWRXWXWRXWR" << RESET << std::endl;
}