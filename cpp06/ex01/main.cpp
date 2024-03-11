/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:01:37 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/28 19:47:05 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"
# include <iostream>


int main(void)
{
	Data* 		ptr_original = new(Data);
	uintptr_t 	ptr_value_serialized;
	Data*		ptr_deserialized;

	ptr_original->value = 42;
	ptr_value_serialized = Serializer::serializer(ptr_original);
	ptr_deserialized 	 = Serializer::deserializer(ptr_value_serialized);
	
	std::cout << "Original value pointer of structure: " << std::right << std::setw(50) << ptr_original << std::endl;
	std::cout << "pointer value of structure casted to uintptr_t: " << std::right << std::setw(40) << ptr_value_serialized << std::endl;
	std::cout << "pointer value of structure casted to Data*: " << std::right << std::setw(43) << ptr_original << std::endl;
	std::cout << "turn in the files ptr original	    ->" << std::right << std::setw(50) << ptr_deserialized->value << std::endl;
	//(aka 'unsigned long') is not a pointer
	//std::cout << ptr_value_serialized->value << std::endl; ERROR
	std::cout << "turn in the files again deserialized->" << std::right << std::setw(50) << ptr_deserialized->value << std::endl;
}