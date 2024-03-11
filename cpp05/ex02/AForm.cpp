/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:01:45 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 14:19:02 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//Constructors
AForm::AForm(void): _name("default"), _signed(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int x, const int y): _name(name), _signed(false), _gradeRequiredToSign(x), _gradeRequiredToExecute(y)
{
	if (x < 1 || y < 1)
        throw(AForm::GradeTooHighException());
	else if (x > 150 || y > 150)
        throw(AForm::GradeTooLowException());
	else
		std::cout << "Form " << this->_name << " constructor called" << std::endl;
}

AForm::AForm(const AForm &ref): _name(ref.getName()), _signed(ref.getSigned()), _gradeRequiredToSign(ref.getSignGrade()), _gradeRequiredToExecute(ref.getExeGrade())
{
	if (this->_gradeRequiredToSign < 1 || this->_gradeRequiredToExecute < 1)
        throw(AForm::GradeTooHighException());
	else if (this->_gradeRequiredToSign > 150 || this->_gradeRequiredToExecute > 150)
        throw(AForm::GradeTooLowException());
	else
		std::cout << "Form " << this->_name << " copy constructor called" << std::endl;
}

//overload copy assigment
AForm &AForm::operator=(const AForm &ref)
{
	if (this != &ref)
		this->_signed = ref.getSigned();
	std::cout << "Form" << this->_name << " operator constructor called" << std::endl;
	return (*this);
}

//Destructors
AForm::~AForm(void)
{
	std::cout << "Form destructor called" << std::endl;
}

//Getters
std::string AForm::getName(void) const
{
	return (this->_name);
}

int AForm::getSigned(void) const
{
	return (this->_signed);
}

int AForm::getSignGrade(void) const
{
	return (this->_gradeRequiredToSign);
}

int AForm::getExeGrade(void) const
{
	return (this->_gradeRequiredToExecute);
}

//Setters
void AForm::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > this->getSignGrade())
		throw(AForm::GradeTooLowException());	
	this->_signed = true;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form grade is too high");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form grade is too low");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form is not signed, cant execute it");
}

//outside of the Class Form
std::ostream &operator<<(std::ostream& stream, const AForm& ref)
{
	stream << "FORM;" << RED" name= " << ref.getName() << BLUE << ", sign= " << ref.getSigned() << GREEN << ", grade to signed= " << ref.getSignGrade() << YELLOW << ", grade to execute= " << ref.getExeGrade() << RESET << std::endl;
	return (stream);
}



