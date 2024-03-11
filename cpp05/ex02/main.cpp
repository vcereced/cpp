/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:27:02 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 14:12:18 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


int main(void)
{
	// std::string buff;
	// try{
		
	// 	Bureaucrat test;
	// 	Form testForm;
	// 	std::cout << test << std::endl;
	// }
	// catch (std::exception &err){
	//  	std::cout << err.what() << std::endl;
	// }
	// std::cout << buff << std::endl;
	// try{
	// Form actaaaa;
	// Bureaucrat yo("victor", 150);
	// Form acta("acta", 120, 120);
	// yo.signForm(acta);
	// std::cout << acta << std::endl;
		
	// }
	//  catch (std::exception &err){
	//   	std::cout << err.what() << std::endl;
	//  }
	try{
		
		//ShrubberyCreationForm park("park");
		PresidentialPardonForm robot("IDIOT!");
		Bureaucrat Victor("victor", 1);
		Victor.signForm(robot);
		std::cout << robot << std::endl;
		//Victor.executeForm(park);
		
		Victor.executeForm(robot);
	}
	catch (std::exception &err){
	  	std::cout << err.what() << std::endl;
	}
	
	
}
