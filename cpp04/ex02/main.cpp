/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:03:02 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/29 17:27:29 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	//Animal animal; error cuz Animal is abstract class;
	
	Dog dog;
	Cat cat;
	
	AAnimal *ptr = &dog;
	ptr->makeSound();
	ptr = &cat;
	ptr->makeSound();
	return 0;
}