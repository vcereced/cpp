/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:01:37 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/13 13:06:28 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
# include <random>

int main(void)
{
	try
	{
		Span test1(0);

		Span test = test1;
		
		test.fill(10);
		
		//test.addNumber(-1);
		//test.addNumber(0);
		//test.addNumber(10);
		//std::cout << test.shortestSpan() << std::endl;
		//std::cout << test.longestSpan() << std::endl;
	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    return 0;

}

