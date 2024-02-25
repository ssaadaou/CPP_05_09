/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:35:27 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/24 22:49:31 by ssaadaou         ###   ########.fr       */
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
        AForm* form = NULL;
        std::cout << std::endl;
        
        form = intern.makeForm("shrubbery creation", "garden");
        if (form)
        {
            X.signForm(*form);
            X.executeForm(*form);
            delete form;
        }
        std::cout << std::endl;
        form = intern.makeForm("robotomy request", "robotomy");
        if (form)
        {
            X.signForm(*form);
            X.executeForm(*form);
            std::cout << std::endl;
            delete form;
        }
        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}