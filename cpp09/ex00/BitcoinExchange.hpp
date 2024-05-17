/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:57:57 by vcereced          #+#    #+#             */
/*   Updated: 2024/03/19 19:54:48 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <stdexcept>
# include <iostream>
# include <fstream>
# include <string>
# include <map>

class BitcoinExchange
{
	private:
		static std::string 	_date;
		static float 		_rate;
		BitcoinExchange(void);
	
	public:
		static void 		convert(char *);
		static void 		setDate(std::string &);
		static void 		setRate(float );
		static std::string &getDate(void);
		static float 	   &getRate(void);
		
		class ErrorFile: public std::exception{
			public:
				const char* what(void) const throw()
				{
					return "Error: could not open file.";
				}
		};
		class ErrorHeader: public std::exception{
			public:
				const char* what(void) const throw()
				{
					return "Error: header csv wrong.";
				}

		};
		class ErrorFormat: public std::exception{
			public:
				const char* what(void) const throw()
				{
					return "Error: line format wrong.";
				}

		};
};

#endif