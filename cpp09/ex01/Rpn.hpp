/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:48:10 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/20 13:40:46 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <string>
# include <stack>

class Rpn
{
	private:
		static std::stack<int> 	_stack;
		Rpn(void);
	
	public:
		static int  operate(char *);
		//static void 		setDate(std::string &);
		//static void 		setRate(float );
		static std::stack<int> &getstack(void);
		//static float 	   &getRate(void);
		
};

#endif