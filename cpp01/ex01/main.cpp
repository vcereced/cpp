/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:03:47 by vcereced          #+#    #+#             */
/*   Updated: 2023/12/15 17:41:24 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// void checks_leaks(void)
// {
// 	system("leaks zombie");
// }

int main() {
	Zombie *horde;
	int n = 5;

	horde = zombieHorde(n, "Zombie nº");
	for (int i = 0; i < n; i++) {
		horde[i].announce();
	}
	delete [] horde;
	//atexit(checks_leaks);
	return (0);
}