/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:04:59 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/16 21:05:28 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
# define BUREAUCRAT
# include "Form.hpp"
# include <string>
# include <iostream>
# include <stdexcept>

class Form;

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
		void		signForm(Form &ref); 

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