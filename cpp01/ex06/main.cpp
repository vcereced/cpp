/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:06:15 by vcereced          #+#    #+#             */
/*   Updated: 2023/12/15 17:52:05 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// void checks_leaks(void)
// {
// 	system("leaks harlFilter");
// }

int main (int argc, char *argv[])
{
	Harl harl;

	if (argc !=2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		//atexit(checks_leaks);
		return (1);
	}
	
	harl.complain(argv[1]);
	//atexit(checks_leaks);
	return(0);
}