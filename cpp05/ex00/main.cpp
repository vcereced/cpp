/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:27:02 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/16 12:27:20 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>

int main(void)
{
	std::string buff;
	try{
		buff = "test buffer!";
		Bureaucrat test("soyTEST1 ", 150);
		test.upGrade();
		test.upGrade();
		test.upGrade();

		std::cout << test << std::endl;
	}
	catch (std::exception &err){
	 	std::cout << err.what() << std::endl;
	}
	std::cout << buff << std::endl;
}
