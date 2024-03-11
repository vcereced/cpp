/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:42:15 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/27 20:18:17 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

bool isDouble(const std::string &string)
{
	unsigned long index = 0;
	unsigned long dot;
	//check ""
	if (string.empty())
 		return false;
 	//check if "-..." move next
	if (string[0] == '-' && string.length() > 1)
 		index++;
	//get index of .	
	dot = string.find(".");
	if (dot == std::string::npos)
		return false;
	//check "-.123"
	if (string[index] == '.')
		return false;
	//check int before "."	
	while(index < dot)
	{
		if (!std::isdigit(string[index]))
			return false;
		index++;
	}
	//move next of "."
	index++;
	//check if "-0.f"
	if (!std::isdigit(string[index]))
			return false;
	//check int before n_last
	while(index < string.length())
	{
		if (!std::isdigit(string[index]))
			return false;
		index++;
	}
	return true;
}

bool isFloat(const std::string &string)
{
	unsigned long index = 0;
	unsigned long dot;
	//check ""
	if (string.empty())
 		return false;
 	//check if "-..." move next
	if (string[0] == '-' && string.length() > 1)
 		index++;
	//get index of .	
	dot = string.find(".");
	if (dot == std::string::npos)
		return false;
	//check "-.123"
	if (string[index] == '.')
		return false;
	//check int before "."	
	while(index < dot)
	{
		if (!std::isdigit(string[index]))
			return false;
		index++;
	}
	//move next of "."
	index++;
	//check if "-0.f"
	if (!std::isdigit(string[index]))
			return false;
	//check int before n_last
	while(index < string.length() - 1)
	{
		if (!std::isdigit(string[index]))
			return false;
		index++;
	}
	if (string[index] != 'f')
		return false;
	return true;
}

bool isInt(const std::string &string)
{
	unsigned long x = 0;
	
	if (string.length() == 0)
		return false;
	if (string[0] == '-' && string.length() > 1)
		x++;	
	for (unsigned long i = x; i < string.length(); i++)
	{
		if (string[i] < '0' || string[i] > '9')
			return false;
	}
	return true;
}

bool isChar(const std::string &string)
{
	if (string.length() != 1)
		return false;
	if (string[0] > '0' || string[0] < '9')
		return false;
	return true;	
}

static void printChar( const std::string &s )
{
	char	c = s[0];

	if (static_cast<int>(c) < 32 || static_cast<int>(c) > 126)
        std::cout << "char : impossible" << std::endl;
    else
        std::cout << "char: " << "'" << c  << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void printInt( const std::string &s )
{
	int c = atoi(s.c_str());
    if (c < 32 || c > 126)
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << static_cast<char>(c) << "'" << std::endl;
    
    long long k = atol(s.c_str());
    if (k > INT_MAX || k < INT_MIN)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << c << std::endl;
    if (k > INT_MAX || k < INT_MIN)
        std::cout << "float : Impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    if (k > INT_MAX || k < INT_MIN)
        std::cout << "double : Impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void printFloat( const std::string &string)
{
	float c = atof(string.c_str());
	
    if (c < 32 || c > 126)
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << static_cast<char>(c) << "'" << std::endl;
    
    long long k = atol(string.c_str());
    if (k > INT_MAX || k < INT_MIN)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(c) << std::endl;
    if (k > INT_MAX || k < INT_MIN)
        std::cout << "float : Impossible" << std::endl;
    else
	{
        std::cout << "float: " << c;
		if (c - static_cast<int>(c) == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
    if (k > INT_MAX || k < INT_MIN)
        std::cout << "double : Impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void printDouble( const std::string &string )
{
	double c = atof(string.c_str());
    if (c < 32 || c > 126)
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char: " << "'" << static_cast<char>(c) << "'" << std::endl;
    
    long long k = atol(string.c_str());
    if (k > INT_MAX || k < INT_MIN)
        std::cout << "int: Impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(c) << std::endl;
    if (k > INT_MAX || k < INT_MIN)
        std::cout << "float : Impossible" << std::endl;
    else
	{
        std::cout << "float: " << c;
		if (c - static_cast<int>(c) == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
    if (k > INT_MAX || k < INT_MIN)
        std::cout << "double : Impossible" << std::endl;
    else
	{
        std::cout << "double: " << c;
		if (c - static_cast<int>(c) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
}

static void	printInfMinus()
{
	std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : -inff" << std::endl;
    std::cout << "double : -inf" << std::endl;
}

static void	printInfAdd()
{
	std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : +inff" << std::endl;
    std::cout << "double : +inf" << std::endl;
}

static void	printNan()
{
	std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    std::cout << "float : nanf" << std::endl;
    std::cout << "double : nan" << std::endl;
}

static void printSpecials( const std::string &string )
{
	std::string values[] = { "-inff", "+inff", "nanf", "-inf", "+inf", "nan" };
    void (*f[])(void)= { &printInfMinus, &printInfAdd, &printNan, &printInfMinus, &printInfAdd, &printNan };

    for (int i = 0; i < 6; i++)
    {
        if (string == values[i])
        {
            f[i]();
            return ;
        }
    }
    std::cout << "CONVERT ERROR" << std::endl;
}

void ScalarConverter::convert(std::string string)
{	
	bool (*f[])(const std::string &) = { &isChar, &isInt, &isFloat, &isDouble };
	void (*f2[])(const std::string &) = { &printChar, &printInt, &printFloat, &printDouble };
	for (int i = 0; i < 4; i++)
	{
		if (f[i](string))
			return (f2[i](string));
	
	}
	printSpecials(string);
}
