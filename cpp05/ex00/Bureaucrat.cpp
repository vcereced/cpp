/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:51:20 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/16 12:42:21 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//Constructors
Bureaucrat::Bureaucrat(void):_name("trainee"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade):_name(name), _grade(grade)
{
	if (grade < 1)
        throw(Bureaucrat::GradeTooLowException());
	else if (grade > 150)
        throw(Bureaucrat::GradeTooHighException());
	else
		std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref):_name( ref.getName()), _grade(ref.getGrade())
{
	if (this->_grade < 1)
        throw(Bureaucrat::GradeTooLowException());
	else if (this->_grade > 150)
        throw(Bureaucrat::GradeTooHighException());
	else
		std::cout << "Bureaucrat copy constructor called" << std::endl;
}

//overload copy assigment
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &ref)
{
	if (this != &ref)
	{
		//this->_name = ref.getName();
		if (ref.getGrade() < 1)
        	throw(Bureaucrat::GradeTooLowException());
		else if (ref.getGrade() > 150)
        	throw(Bureaucrat::GradeTooHighException());
		this->_grade = ref.getGrade();
	}
	std::cout << "Bureaucrat operator constructor called" << std::endl;
	return(*this);
}

//Destructors
Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//Method
std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

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

//outside of the class Fixed
std::ostream &operator<<(std::ostream& stream, const Bureaucrat& ref)
{
   stream << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl;
   return (stream);
}

//Exceptions
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}