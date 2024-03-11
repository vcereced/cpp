/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:01:37 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/02 19:57:00 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"
# include <iostream>
# include <array>

int main(void)
{
	try{
		Array<int> vacio;
		Array<int> arr1(5);
		
		arr1[0] = 42;
		arr1[arr1.size() - 1] = 42;
		
		std::cout << "arr nº1 size: " << arr1.size() << std::endl;
		for (unsigned int i = 0; i < arr1.size(); i++)
		{
			std::cout << "position " << i << " -> " << arr1[i] << std::endl;
		}
		std::cout << std::endl;

		Array<int> arr2(arr1);
		arr2[2] = 24;

		std::cout << "arr nº1 size: " << arr2.size() << std::endl;
		for (unsigned int i = 0; i < arr2.size(); i++)
		{
			std::cout << "position " << i << " -> " << arr2[i] << std::endl;
		}
		std::cout << std::endl;

		Array<int> arr3 = arr2;
		std::cout << "arr nº1 size: " << arr3.size() << std::endl;
		for (unsigned int i = 0; i < arr3.size(); i++)
		{
			std::cout << "position " << i << " -> " << arr3[i] << std::endl;
		}
		std::cout << std::endl;
		
		
		
		//Array<char> ola;
		
		//return 0;
	}catch(std::exception &err){
		std::cout << err.what() << std::endl;
	}

}

