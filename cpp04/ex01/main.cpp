/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:03:02 by vcereced          #+#    #+#             */
/*   Updated: 2024/01/20 20:32:26 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
# define DEFAULT "\001\033[0;39m\002"
# define MAGENTA "\001\033[1;95m\002"

int main()
{
	Animal *arrAnimal[10];
	Animal* dog1 = new Dog();
	Dog* dog2 = new Dog();

	for (int i = 0; i < 10; i++)
	{
		if (i < 10 / 2)
		{
			arrAnimal[i] = new Dog();
			arrAnimal[i]->getBrain().setIdea("grr.. ", 0);
		}
		else
		{
			arrAnimal[i] = new Cat();
			arrAnimal[i]->getBrain().setIdea("miau.. ", 0);
		}
	}
	std::cout << "-------------------------------------\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << arrAnimal[i]->getType() << "--> ";
		std::cout << arrAnimal[i]->getBrain().getIdea(0) << std::endl;
	}
	std::cout << "-------------------------------------\n";
	
	//Setting ideas to dogs
	for(int i = 0; i < 100; i++)
		dog1->getBrain().setIdea("Dog1,  ", i);
	for(int i = 0; i < 100; i++)
		dog2->getBrain().setIdea("Dog2,  ", i);

	
	std::cout << MAGENTA << "\nDog1 Brain Ideas = \n" << DEFAULT;
	for(int i = 0; i < 100; i++)
		std::cout << dog1->getBrain().getIdea(i);

	std::cout << MAGENTA << "\n\nDog2 Brain Ideas = \n" << DEFAULT;
	for(int i = 0; i < 100; i++)
		std::cout << dog2->getBrain().getIdea(i);
	
	//									TEST
	//Call overload copy assigment and then check if its a shallow copy or deep copy
	*dog1 = *dog2;
	//
	//std::cout << MAGENTA << "\n\nDog1 SET Brain Ideas = CHANGED\n" << DEFAULT;
	//for(int i = 0; i < 100; i++)
	//	dog1->getBrain().setIdea("CHANGED,  ", i);
	
	std::cout << MAGENTA << "\n\nDog1 Brain Ideas = \n" << DEFAULT;
	for(int i = 0; i < 100; i++)
		std::cout << dog1->getBrain().getIdea(i);

	std::cout << MAGENTA << "\n\nDog2 Brain Ideas = \n" << DEFAULT;
	for(int i = 0; i < 100; i++)
		std::cout << dog2->getBrain().getIdea(i);

	for (int i = 0; i < 10; i++)
		delete arrAnimal[i];
	delete dog1;
	delete dog2;

	system("leaks Animal");
	return 0;
}