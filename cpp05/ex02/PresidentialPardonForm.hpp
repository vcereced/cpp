/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:02:10 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 14:12:45 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "AForm.hpp"


class Bureaucrat;

class PresidentialPardonForm: public AForm{
	private:
		const std::string _target;
	public:
		//Constructors
		PresidentialPardonForm(const std::string);
		PresidentialPardonForm(const PresidentialPardonForm &ref);

		//overload copy assigment
		PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);
		
		//Destructors
		~PresidentialPardonForm(void);

		//getters
		std::string getTarget(void) const;

		//Method
		void execute(Bureaucrat const &executor) const;
		
};

#endif