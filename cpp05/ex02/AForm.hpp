/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:46:09 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 14:08:55 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# define RESET   "\033[0m"
# define RED     "\033[31m"      /* Red */
# define GREEN   "\033[32m"      /* Green */
# define YELLOW  "\033[33m"      /* Yellow */
# define BLUE    "\033[34m"      /* Blue */
# include "Bureaucrat.hpp"
# include <string>
# include <iostream>
# include <stdexcept>


class Bureaucrat;

class AForm{
	private:
		const std::string 	_name;
		bool				_signed;
		const int			_gradeRequiredToSign;
		const int			_gradeRequiredToExecute;
	
	public:
		//Constructors
		AForm(void);
		AForm(const std::string, const int, const int);
		AForm(const AForm &ref);

		//Destructors
		virtual ~AForm(void);
		
		//overload copy assigment
		AForm &operator=(const AForm &ref);

		//Getters
		std::string getName(void) const;
		int 		getSigned(void) const;
		int 		getSignGrade(void) const;
		int 		getExeGrade(void) const;

		//Setters
		void beSigned(Bureaucrat &ref);
		virtual void execute(Bureaucrat const &executor) const = 0;

		//Exception class
		class GradeTooHighException: public std::exception{
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				const char *what(void) const throw();
		};
		class FormNotSignedException: public std::exception{
			public:
				const char *what(void) const throw();
		};
};

//outside of the class AForm
std::ostream &operator<<(std::ostream& stream, const AForm& ref);

#endif