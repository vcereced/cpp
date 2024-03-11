/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:05:05 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 18:53:16 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <iostream>
# include <vector>

class AForm;

class Intern{	
	public:
		//Constructors
		Intern(void);

		//Destructors
		~Intern(void);
		
		//Method+
		AForm *newShrubberyCreationForm(std::string);
		AForm *newRobotomyRequestForm(std::string);
		AForm *newPresidentialPardonForm(std::string);
		AForm *makeForm(std::string, std::string);
};

#endif