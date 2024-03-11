/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:08:40 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 14:15:12 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "AForm.hpp"
# include <fstream>

class Bureaucrat;

class ShrubberyCreationForm: public AForm{
	private:
		const std::string _target;
	public:
		//Constructors
		ShrubberyCreationForm(const std::string);
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);

		//overload copy assigment
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);
		
		//Destructors
		~ShrubberyCreationForm(void);

		//getters
		std::string getTarget(void) const;

		//Method
		void execute(Bureaucrat const &executor) const;
		
};


#endif