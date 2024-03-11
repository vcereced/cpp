/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:41:52 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 20:14:00 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

//Method
AForm *Intern::newShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
AForm *Intern::newRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}
AForm *Intern::newPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string forms[] = {
		"robotomy request",
		"presidential request",
		"shrubbery request"};
	AForm *(Intern::*createForms[])(std::string) = {
		&Intern::newRobotomyRequestForm,
		&Intern::newPresidentialPardonForm,
		&Intern::newShrubberyCreationForm,
	};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form)
		{
			std::cout << GREEN"Intern creates " << forms[i] << " form" << RESET << std::endl;
			return (this->*createForms[i])(target);
		}
	}

	
	std::cout << RED"Intern form called not exist " << form << RESET << std::endl;
	return  NULL;
}
