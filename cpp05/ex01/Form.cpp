/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:01:45 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/17 20:36:58 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Constructors
Form::Form(void): _name("default"), _signed(false), _gradeRequiredToSign(150), _gradeRequiredToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int x, const int y): _name(name), _signed(false), _gradeRequiredToSign(x), _gradeRequiredToExecute(y)
{
	if (x < 1 || y < 1)
        throw(Form::GradeTooHighException());
	else if (x > 150 || y > 150)
        throw(Form::GradeTooLowException());
	else
		std::cout << "Form " << this->_name << " constructor called" << std::endl;
}

Form::Form(const Form &ref): _name(ref.getName()), _signed(ref.getSigned()), _gradeRequiredToSign(ref.getSignGrade()), _gradeRequiredToExecute(ref.getExeGrade())
{
	if (this->_gradeRequiredToSign < 1 || this->_gradeRequiredToExecute < 1)
        throw(Form::GradeTooHighException());
	else if (this->_gradeRequiredToSign > 150 || this->_gradeRequiredToExecute > 150)
        throw(Form::GradeTooLowException());
	else
		std::cout << "Form " << this->_name << " copy constructor called" << std::endl;
}

//overload copy assigment
Form &Form::operator=(const Form &ref)
{
	if (this != &ref)
		this->_signed = ref.getSigned();
	std::cout << "Form" << this->_name << " operator constructor called" << std::endl;
	return (*this);
}

//Destructors
Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

//Getters
std::string Form::getName(void) const
{
	return (this->_name);
}

int Form::getSigned(void) const
{
	return (this->_signed);
}

int Form::getSignGrade(void) const
{
	return (this->_gradeRequiredToSign);
}

int Form::getExeGrade(void) const
{
	return (this->_gradeRequiredToExecute);
}

//Setters
void Form::beSigned(Bureaucrat &ref)
{
	if (ref.getGrade() > this->getSignGrade())
		throw(Form::GradeTooLowException());	
	this->_signed = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form grade is too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form grade is too low");
}

//outside of the Class Form
std::ostream &operator<<(std::ostream& stream, const Form& ref)
{
	stream << "name form=" << ref.getName() << " sign= " << ref.getSigned() << "grade to signed= " << ref.getSignGrade() << " grade to execute= " << ref.getExeGrade() << std::endl;
	return (stream);
}



