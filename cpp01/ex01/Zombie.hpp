/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:05:11 by vcereced          #+#    #+#             */
/*   Updated: 2023/12/09 17:58:25 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>
# include <unistd.h>

class Zombie{
	public:
		void announce(void);
		Zombie();
		Zombie(std::string name);
		void setName(std::string name);
		~Zombie(void);
	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);
#endif