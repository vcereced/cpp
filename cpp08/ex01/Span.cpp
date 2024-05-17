/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:03:52 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/13 13:06:17 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span(void): _size(0) {}

Span::Span(int num): _size(num) {}

Span::Span(Span &ref):  _size(ref._size), _vector(ref._vector) {}

Span &Span::operator=(const Span &ref)
{
	if (this != &ref)
	{
		this->_vector = ref._vector;
		this->_size = ref._size;
	}
	return *this;
}

void Span::addNumber(int num)
{
	if (this->_vector.size() >= this->_size)
		throw std::runtime_error("Stopped addNumber function, No left space");
	this->_vector.push_back(num);
}

void Span::fill(int n)
{
	std::vector<int>::iterator itBegin;
	std::vector<int>::iterator itLast;

	itBegin = this->_vector.begin();
	itLast = this->_vector.end();
	if ((size_t)(std::distance(itBegin, itLast) + n) > this->_size)
		throw std::runtime_error("Stopped fill function, resize vector");
	
	std::srand(static_cast<int>(std::time(nullptr)));
	for (int i = 0; i  < n; i++)
	{	
		this->addNumber(std::rand());
	}
}

int Span::shortestSpan()
{
	std::vector<int> 	tmp;
	
	tmp = this->_vector;
	if (tmp.size() <= 1)
		throw std::runtime_error("Stopped shortesSpan function");
		
	std::sort(tmp.begin(), tmp.end());
	for (size_t i = 0; i < tmp.size(); i++)
	{
		if (tmp[0] != tmp[i])
			return tmp[i] - tmp[0];
	}
	return 0;
}

int Span::longestSpan()
{
	std::vector<int> tmp;

	tmp = this->_vector;
	if (tmp.size() <= 1)
		throw std::runtime_error("Stopped longestSpan function");

	std::sort(tmp.begin(), tmp.end());
	return tmp.back() - tmp.front();	
}
