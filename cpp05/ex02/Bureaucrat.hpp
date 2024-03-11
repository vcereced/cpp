/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:04:59 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 14:19:53 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
# define BUREAUCRAT
# include "AForm.hpp"
# include <string>
# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat{
	private:
		const std::string 	_name;
		int					_grade;
	
	public:
		//Constructors
		Bureaucrat(void);
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &ref);

		//Destructors
		~Bureaucrat(void);
		
		//overload copy assigment
		Bureaucrat &operator=(const Bureaucrat &ref);

		//Getters
		std::string getName(void) const;
		int 		getGrade(void) const;
		
		//Setters
		void		upGrade(void);
		void		downGrade(void);
		
		//Method
		void		signForm(AForm &ref); 
		void 		executeForm(AForm const & form);

		//Exception class
		class GradeTooHighException: public std::exception{
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				const char *what(void) const throw();
		};

};

//outside of the class Form
std::ostream &operator<<(std::ostream& stream, const Bureaucrat& ref);

#endif