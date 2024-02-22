/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:35:27 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/22 16:08:13 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat X("X", 1);
        Intern intern;
        AForm* form;
        form = intern.makeForm("shrubbery creation", "garden");
        X.signForm(*form);
        X.executeForm(*form);
        delete form;
        form = intern.makeForm("robotomy request", "robotomy");
        X.signForm(*form);
        X.executeForm(*form);
        delete form;
        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}