/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:03:47 by vcereced          #+#    #+#             */
/*   Updated: 2023/12/15 17:43:56 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

// void checks_leaks(void)
// {
// 	system("leaks executable");
// }

int main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << "The memory address of the string variable;	" << &string << std::endl;
	std::cout << "The memory address held by stringPTR;		" << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF;		" << &stringREF << std::endl << std::endl;
	
	std::cout << "The value of the string variable;		" << string << std::endl;
	std::cout << "The value pointed to by stringPTR;		" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF;		" << stringREF << std::endl;
	
	//atexit(checks_leaks);
	return (0);
}