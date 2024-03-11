/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:39:32 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/29 17:20:48 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <algorithm>
# include <string>
# include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	
	public:
		//Constructors
		Brain(void);
		Brain(const Brain &ref);
		
		//Destructors
		~Brain(void);

		//overload copy assigment
		Brain &operator=(const Brain &ref);

		//getters & setters
		const std::string getIdea(const int index) const;
		void setIdea(const std::string idea, const int index);
		
};

#endif