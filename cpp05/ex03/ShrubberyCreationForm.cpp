/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:13:11 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 14:14:01 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref): AForm(ref), _target(ref._target)
{
	std::cout << this->getName() << " copy  constructor called" << std::endl;
}

//Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

//overload copy assigment
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	if (this != &ref)
	{
		ShrubberyCreationForm::AForm::operator=(ref);
	}
	std::cout << "Form" << this->getName() << " operator constructor called" << std::endl;
	return *this;
}

//getters
std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

//Method
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExeGrade())
		throw(AForm::GradeTooLowException());
	else if (this->getSigned() == false)
		throw(AForm::FormNotSignedException());
	std::ofstream outfile(this->getTarget() + "_shrubbery");
	outfile <<
			"       /|\\ " << std::endl <<
			"      / | \\ " << std::endl <<
			"     /  |  \\ " << std::endl <<
			"    /   |   \\ " << std::endl <<
			"   *    |    * " << std::endl <<
			"  /|\\   |   /|\\ " << std::endl <<
			" / | \\  |  / | \\ " << std::endl <<
			"*  |  * | *  |  * " << std::endl <<
			"|  |   \\|/|  |  | " << std::endl <<
			"       ###" << std::endl <<
			"       ###" << std::endl <<
			"       ###" << std::endl;
		outfile.close();
}