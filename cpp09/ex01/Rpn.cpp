/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:51:50 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/20 19:02:56 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rpn.hpp"

std::stack<int> Rpn::_stack;

std::stack<int> &Rpn::getstack(void)
{
	return (Rpn::_stack);
}

static void operand(char c)
{
	int value1;
	int value2;
	int result;
	
	if (Rpn::getstack().size() >= 2)
	{
		value2 = Rpn::getstack().top();
		Rpn::getstack().pop();
		value1 = Rpn::getstack().top();
		Rpn::getstack().pop();
	}
	
	if (c == '+')
		result = value1 + value2;
	else if (c == '-')
		result = value1 - value2;
	else if (c == '*')
		result = value1 * value2;
	else if (c == '/')
		result = value1 / value2;
	else
		throw std::runtime_error("Error");
	Rpn::getstack().push(result);
}

int Rpn::operate(char *str)
{
	int i = 0;
	for(int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			continue;
		else if (std::isdigit(str[i]))
			Rpn::getstack().push(static_cast<int>(str[i] - '0'));
		else
			operand(str[i]);
	}
	return Rpn::getstack().top();
}
