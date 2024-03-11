/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:22:09 by vcereced          #+#    #+#             */
/*   Updated: 2023/12/09 19:50:37 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}
const std::string &Weapon::getType(void)
{
	return (this->type);
}
void Weapon::setType(std::string type)
{
	this->type = type;
}
Weapon::~Weapon(void)
{
	
}