/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:33:46 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/28 17:48:00 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <cstdint>

typedef struct s_data
{
	int value;
}Data;


class Serializer
{
	private:
		Serializer(void) {};
	
	public:
		static uintptr_t 	serializer(Data* ptr);
		static Data* 		deserializer(uintptr_t raw);
};


#endif