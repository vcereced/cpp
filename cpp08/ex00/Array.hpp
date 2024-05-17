/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:44:27 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/12 19:34:14 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <vector>  // Para vectores
# include <list>    // Para listas
# include <algorithm>  // Para algoritmos de ordenamiento y otros algoritmos
# include <iostream> 
# include <set>
# include <map>

class ValueNotFound: public std::exception
{
	const char * what() const throw()
	{
		return "Value not found in container";
	}
};

template<typename T_container, typename T> 
typename T_container::iterator easyfind(T_container &container, T n)
{
	typename T_container::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw ValueNotFound();
	return it;
}

#endif