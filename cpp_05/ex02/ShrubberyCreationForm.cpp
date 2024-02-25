/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:31:52 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/25 15:29:27 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(Target, 145, 137), Target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target) : AForm(Target, 145, 137), Target(Target) {}

 
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), Target(copy.Target) {}

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
        std::string filename = (this->getTarget() + "_shrubbery");
        std::cout << "name: " << filename << "          target: " << this->getTarget() << std::endl;
        std::ofstream file(filename.c_str());
        if(!file.is_open())
        {
            std::cout << "Error: could not open file " << filename << std::endl;
            return;
        }
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
        file.close();
    }
}