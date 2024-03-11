/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:46:42 by vcereced          #+#    #+#             */
/*   Updated: 2023/12/15 17:47:57 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

// void checks_leaks(void)
// {
// 	system("leaks executable");
// }

void msg_err(std::string err)
{
	std::cerr << "Error: " << err << std::endl;
	exit(1);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		msg_err("Invalid number of arguments.");

	Replace 		replace(argv[1], argv[2], argv[3]);
	std::ifstream 	infile;
	std::ofstream 	outfile;
	std::string		text;
	
	replace.infile(infile);
	replace.outfile(outfile);
	replace.read(text, infile);
	replace.replace(text);
	replace.write(text, outfile);
	infile.close();
	outfile.close();
	//atexit(checks_leaks);
	return 0;
}