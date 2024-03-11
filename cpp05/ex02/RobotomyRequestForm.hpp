/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:23:55 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 14:13:30 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"


class Bureaucrat;

class RobotomyRequestForm: public AForm{
	private:
		const std::string _target;
	public:
		//Constructors
		RobotomyRequestForm(const std::string);
		RobotomyRequestForm(const RobotomyRequestForm &ref);

		//overload copy assigment
		RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);
		
		//Destructors
		~RobotomyRequestForm(void);

		//getters
		std::string getTarget(void) const;

		//Method
		void execute(Bureaucrat const &executor) const;
		
};

#endif