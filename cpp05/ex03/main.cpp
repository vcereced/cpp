/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:27:02 by vcereced          #+#    #+#             */
/*   Updated: 2024/02/19 20:43:55 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


int main(void)
{
	Intern becario;
	//Bureaucrat jefe("BOSS", 120);
	AForm *robot;
	//AForm *presi;
	//AForm *three;
	robot = becario.makeForm("robotomy request", "Bender");
	// three = becario.makeForm("shrubbery request", "Bender");
	// presi = becario.makeForm("presidential request", "Bender");
	// if (robot)
	// {
	// 	jefe.signForm(*robot);
	// 	jefe.executeForm(*robot);
	// 	delete robot;
	// }
	// if (presi)
	// {
	// 	jefe.signForm(*presi);
	// 	jefe.executeForm(*presi);
	// 	delete presi;
	// }
	// if (three)
	// {
	// 	jefe.signForm(*three);
	// 	jefe.executeForm(*three);
	// 	delete three;
	// }
	
}
