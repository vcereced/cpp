/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:36:59 by vcereced          #+#    #+#             */
/*   Updated: 2023/12/10 20:56:15 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

class Replace
{
	private:
		std::string const 	filename;
		std::string const 	s1;
		std::string const 	s2;
	public:
		Replace(std::string  filename, std::string  s1, std::string  s2);
		~Replace();
		void				infile(std::ifstream &infile);
		void 				outfile(std::ofstream &outfile);
		void				read(std::string &text, std::ifstream &infile);
		void				replace(std::string &text);
		void				write(std::string &text, std::ofstream &output);
};

void msg_err(std::string err);