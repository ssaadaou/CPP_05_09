/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:11:38 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/22 15:56:57 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& copy) {(void)copy;}

Intern& Intern::operator=(const Intern& other) 
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* ShrubberyCreation(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* RobotomyRequest(std::string target) 
{
    return new RobotomyRequestForm(target);
}

AForm* PresidentialPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) const
{
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon" };
    
    AForm* (*creatForm[])(std::string) = {ShrubberyCreation, RobotomyRequest, PresidentialPardon};
    
    for (int i = 0; i < 3; ++i)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return creatForm[i](target);
        }
    }
    std::cout << "Intern cannot create " << formName << ": Form not recognized." << std::endl;
    return NULL;
}