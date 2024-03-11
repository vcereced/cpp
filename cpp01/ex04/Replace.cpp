/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:50:33 by vcereced          #+#    #+#             */
/*   Updated: 2023/12/10 20:53:53 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2) : filename(filename), s1(s1), s2(s2)
{
	if (this->filename.empty() || this->s1.empty())
		msg_err("empty argument");
}

Replace::~Replace()
{
	std::cout << "destructor Replace object";
}

void	Replace::infile(std::ifstream &infile)
{
	infile.open(this->filename, std::fstream::out);
	
	if (!infile.is_open())
		msg_err("can´t open infile");
}

void 	Replace::outfile(std::ofstream &outfile)
{
	outfile.open(this->filename + ".replace", std::fstream::in | std::ifstream::trunc);
	if (!outfile.is_open())
		msg_err("can´t open outfile");
}

void	Replace::read(std::string &text, std::ifstream &infile)
{
	std::string line;
	
	while (std::getline(infile, line))
	{
		line += '\n';
		text.append(line);
    }
}

void	Replace::replace(std::string &text)
{
	int index;
	
	while(true)
	{
		index =	text.find(this->s1);
		if (index != -1)
		{
			text.erase(index, this->s1.length());
			text.insert(index, this->s2);
		}
		else
			break;
	}
}

void	Replace::write(std::string &text, std::ofstream &output)
{
	output << text;
}
