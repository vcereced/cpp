/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:50:47 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/13 12:54:58 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>  // Para vectores
# include <list>    // Para listas
# include <algorithm>  // Para algoritmos de ordenamiento y otros algoritmos
# include <iostream> 
# include <set>
# include <map>

class Span
{
	private:
		size_t			_size;
		std::vector<int> 	_vector;
	public:
		Span();
		Span(int);
		Span(Span &ref);
		Span &operator=(const Span &ref);
		void	addNumber(int);
		void	fill(int);
		int 	shortestSpan();
		int		longestSpan();
};

#endif