/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:01:37 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/29 13:48:46 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <iostream>


std::string identifierPtr(Base *ptr)
{
	if (dynamic_cast<A*>(ptr) != NULL)
   		return ("A");
	else if (dynamic_cast<B*>(ptr) != NULL)
    	return ("B");
	else if (dynamic_cast<C*>(ptr) != NULL)
    	return ("C");
	else
		return ("other type!");
}

std::string identifierRef(Base ref)
{
	try {
		A& refA = dynamic_cast<A&>(ref);
		(void)refA;
		return "A";
	}catch(const std::bad_cast& err) {}
	
	try {
		B& refB = dynamic_cast<B&>(ref);
		(void)refB;
		return "B";
	}catch(const std::bad_cast& err) {}
	
	try {
		C& refC = dynamic_cast<C&>(ref);
		(void)refC;
		return "C";
	}catch(const std::bad_cast& err) {}
	
	return "cannot identify any class of this reference";
}

int main(void)
{
	A a;

	std::cout << identifierPtr(&a) << std::endl;
	std::cout << identifierRef(a);
	
}