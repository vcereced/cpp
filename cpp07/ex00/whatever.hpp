/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:01:49 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/02 14:10:25 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T> void swap(T &a, T &b)
{
	T tmp;

	tmp = a;
	a = b;
	b =  tmp;
}

template<typename T> T min(T a, T b)
{
	if (a < b)
		return a;
	else
		return b;
}

template<typename T> T max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}

#endif