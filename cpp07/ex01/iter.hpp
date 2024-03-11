/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:01:49 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/02 15:24:04 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <cstddef>


template<typename T> void increment(T &ref)
{
	ref += 1;
}

template<typename T> void iter(T *arr, size_t len, void (*f)(T &param))
{
	for(size_t i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

#endif