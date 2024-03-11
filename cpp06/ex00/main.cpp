/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:01:37 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/28 13:29:39 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		std::string string_literal = argv[1];
		ScalarConverter::convert(string_literal);
	}
	
}