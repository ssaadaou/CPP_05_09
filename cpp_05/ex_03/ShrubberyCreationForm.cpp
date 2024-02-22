/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:31:52 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/21 20:58:18 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), Target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target) : AForm("ShrubberyCreationForm", 145, 137), Target(Target) {}

// copy all the base class data(AForm ) and all specific data of derived class in this case Target
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), Target(copy.Target) {}
// When copying an object that inherits from another class, use the base class's copy constructor to ensure all base class data is correctly copied.
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->Target = other.Target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const { return (Target); }

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSigned())
        throw NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    else
    {
        // std::string filename = (this->getName() + "_shrubbery").c_str();
        // std::ofstream file(filename);
        std::ofstream file((this->getName() + "_shrubbery").c_str());
        file << "    ccee88oo" << std::endl
             << "  C8O8O8Q8PoOb o8oo" << std::endl
             << " dOB69QO8PdUOpugoO9bD" << std::endl
             << "CgggbU8OU qOp qOdoUOdcb" << std::endl
             << "    6OuU  /p u gcoUodpP" << std::endl
             << "      \\\\_//  /douUP" << std::endl
             << "        \\\\////" << std::endl
             << "         |||/\\" << std::endl
             << "         |||\\/" << std::endl
             << "         |||||" << std::endl
             << "   .....//||||\\...." << std::endl;
    }
}