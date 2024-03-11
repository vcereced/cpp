/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:25:41 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/29 17:25:47 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Dog test;
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << "\n\nCALL GETTYPE METHOD\n";
	std::cout << "________________________\n";
	std::cout << meta->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << "\n\nCALL MAKESOUND METHOD\n";
	std::cout << "________________________\n";
	cat->makeSound(); //will output the cat sound!
	dog->makeSound(); //will output the dog sound!
	meta->makeSound();////will output no sound!
	std::cout << "\n\nMORE TEST with Dog object\n";
	std::cout << "________________________\n";
	std::cout << "test.Dog::getType() or test.getType() 	= " << test.Dog::getType() << "\ntest.Animal::getType() 			= " << test.Animal::getType() << "\n\n";
	std::cout << "\n\nWRONG ANIMALS\n";
	std::cout << "________________________\n";
	const WrongAnimal* wrongAnimal = new WrongCat();
	wrongAnimal->makeSound(); //will output the cat sound!
	std::cout << "\n";
	delete  meta; delete dog; delete cat; delete wrongAnimal;
	return 0;
}