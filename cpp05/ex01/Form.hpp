/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:46:09 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/17 20:33:43 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form{
	private:
		const std::string 	_name;
		bool				_signed;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;
	
	public:
		//Constructors
		Form(void);
		Form(const std::string, const int, const int);
		Form(const Form &ref);

		//Destructors
		~Form(void);
		
		//overload copy assigment
		Form &operator=(const Form &ref);

		//Getters
		std::string getName(void) const;
		int 		getSigned(void) const;
		int 		getSignGrade(void) const;
		int 		getExeGrade(void) const;

		//Setters
		void beSigned(Bureaucrat &ref);

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
std::ostream &operator<<(std::ostream& stream, const Form& ref);

#endif