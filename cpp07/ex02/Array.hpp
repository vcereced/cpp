/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:44:27 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/02 19:42:17 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <stdexcept>

template<typename T>
class Array
{
	private:
		T * 			_arr;
		unsigned int 	_len;
		
	//Constructor
	public:
		Array(void): 			 _arr(new T[0]), 		_len(0) 		{}
		Array(unsigned int len): _arr(new T[len]),		_len(len) 		{}
		Array(Array &ref):		 _arr(new T[ref._len]), _len(ref._len)
		{
			this->operator= (ref);
		}
		
		Array &operator=(const Array &ref)
		{
			if (this != &ref)
			{
				delete [] this->_arr;
				this->_arr 	= new T[ref._len];
				this->_len 	= ref._len;
				std::copy(ref._arr, ref._arr + this->_len, this->_arr);
			}
			return *this;
		}
		
		T &operator[](const unsigned int index)
		{
			if (index >= this->_len)
				throw (std::out_of_range("Err: index out of bounds."));
			return this->_arr[index];
		}

		unsigned int size(void) {return this->_len;}
		
		~Array(void) {delete [] this->_arr;}
		
};


#endif