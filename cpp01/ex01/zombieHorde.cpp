/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:00 by vcereced          #+#    #+#             */
/*   Updated: 2023/12/08 20:32:32 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *hordeZombies = new Zombie[N];

	for (int i = 0; i < N; ++i)
	{
   		hordeZombies[i].setName(name + std::to_string(i));
	}
	return (hordeZombies);
}
