/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:51:20 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 20:10:22 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructors
Bureaucrat::Bureaucrat(void):_name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade):_name(name), _grade(grade)
{
	if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
	else if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
	else
		std::cout << "Bureaucrat " << this->_name << " constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref):_name(ref.getName()), _grade(ref.getGrade())
{
	if (this->_grade < 1)
        throw(Bureaucrat::GradeTooHighException());
	else if (this->_grade > 150)
        throw(Bureaucrat::GradeTooLowException());
	else
		std::cout << "Bureaucrat " << this->_name << " copy constructor called" << std::endl;
}

//overload copy assigment
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this != &ref)
	{
		//this->_name = ref.getName();
		if (ref.getGrade() < 1)
        	throw(Bureaucrat::GradeTooHighException());
		else if (ref.getGrade() > 150)
        	throw(Bureaucrat::GradeTooLowException());
		this->_grade = ref.getGrade();
	}
	std::cout << "Bureaucrat" << this->_name << " operator constructor called" << std::endl;
	return(*this);
}

//Destructors
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//Getters
std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

//Setters
void Bureaucrat::upGrade(void)
{
	if (this->getGrade() > 1)
		(this->_grade)--;
	else
		throw(Bureaucrat::GradeTooHighException());
}
void Bureaucrat::downGrade(void)
{
	if (this->getGrade() < 150)
		(this->_grade)++;
	else
		throw(Bureaucrat::GradeTooLowException());
}

//Method
void Bureaucrat::signForm(AForm &ref)
{
	try
	{
		ref.beSigned(*this);
		std::cout << GREEN"Bureaucrat " << this->_name << " signed " << ref.getName() << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED"Bureaucrat " << this->_name << " couldnt sign " << ref.getName() << " because " << e.what() << RESET << std::endl;
	}
} 

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		std::cout << GREEN"Bureaucrat " << this->_name << " execute " << form.getName() << RESET << std::endl;
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << RED"Bureaucrat " << this->_name << " couldnt execute " << form.getName() << " because " << e.what() << RESET<< std::endl;
	}
}

//outside of the class Bureaucrat
std::ostream &operator<<(std::ostream& stream, const Bureaucrat& ref)
{
   stream << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
   return (stream);
}

//Exceptions
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (RED"Bureaucrat grade is too high"RESET);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (RED"Bureaucrat grade is too low"RESET);
}