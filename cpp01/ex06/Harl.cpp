/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:57:15 by vcereced          #+#    #+#             */
/*   Updated: 2023/12/13 12:38:36 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-\
pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You\
didn’t put enough bacon in my burger! If you did, I wouldnt be asking for \
more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. Ive\
been coming for years whereas you started working here since last month."\
	 << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager \
now." << std::endl;
}

void to_switch(int n)
{
	switch (n) {
        case 0:
            std::cout << MAGENTA << "[ DEBUG ]\n" << DEFAULT;
			 break;
        case 1:
            std::cout << MAGENTA << "[ INFO ]\n" << DEFAULT;
			 break;
        case 2:
            std::cout << MAGENTA << "[ WARNING ]\n" << DEFAULT;
			 break;
		case 3:
            std::cout << MAGENTA << "[ ERROR ]\n" << DEFAULT;
			break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}

void Harl::complain(std::string level)
{
	int n;
	std::string levels[4] ={
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"};
	void (Harl::*f[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error};
		
	for(int i = -1; i < 4; i++)
	{
		if(levels[i] == level)
			n = i;
	}
	to_switch(n);
	if (n >= 0  && n <= 3)
			(this->*f[n])();
}
