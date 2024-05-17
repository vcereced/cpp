/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:01:37 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/12 19:34:24 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"
# include <iostream>
# include <array>

int main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try
	{
   		std::vector<int>::iterator it = easyfind<std::vector<int>, int >(vec, 5);
		std::cout << *it;
	}catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


    return 0;

}

