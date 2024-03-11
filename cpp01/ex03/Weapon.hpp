/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:57:53 by vcereced          #+#    #+#             */
/*   Updated: 2023/12/09 20:18:11 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>
# include <iostream>

class Weapon{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		const std::string &getType(void);
		void setType(std::string type);
		~Weapon(void);
};

#endif