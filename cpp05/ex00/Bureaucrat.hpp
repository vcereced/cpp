/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:04:59 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/16 12:28:27 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT
# define BUREAUCRAT
# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat{
	private:
		const std::string _name;
		int			_grade;
	
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

//outside of the class Fixed
std::ostream &operator<<(std::ostream& stream, const Bureaucrat& ref);

#endif