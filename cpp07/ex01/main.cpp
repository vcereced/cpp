/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:01:37 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/02 15:41:30 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"
# include <iostream>
# include <array>

int main(void)
{
	std::string 		arr1 = "abcdefgh";
	std::array<int, 10> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	::iter<char>(&arr1[0], arr1.length(), increment);
	::iter<int>(&arr2[0], arr2.size(), increment);
	
	//printing arrays
	std::cout << arr1 << std::endl;
	for (size_t i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
	
	return 0;
}