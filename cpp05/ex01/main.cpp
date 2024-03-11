/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:27:02 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/17 20:40:27 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>

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
	try{
	Bureaucrat yo("victor", 151);
	Form acta("acta", 120, 120);
	yo.signForm(acta);
		
	}
	 catch (std::exception &err){
	  	std::cout << err.what() << std::endl;
	 }
	
	
}
