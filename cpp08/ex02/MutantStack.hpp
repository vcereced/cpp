/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:50:47 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/13 20:07:49 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <vector>  
# include <list>   
# include <algorithm> 
# include <iostream> 
# include <set>
# include <map>
# include <stack>


template<typename T>
class MutantStack: public std::stack<T>
{
 	public:

		typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack(void): std::stack<T>() {}
 		MutantStack(MutantStack const & ref) : std::stack<T>(ref) {}
		MutantStack	&operator=(MutantStack const &ref)
		{
			if (this != &ref)
			{
				std::stack<T>::operator=(ref);
			}
			return *this;
		}

		typename std::stack<T>::container_type::iterator begin()
		{
			return (this->c.begin());
		}

		typename std::stack<T>::container_type::iterator end()
		{
			return (this->c.end());
		}

};


#endif