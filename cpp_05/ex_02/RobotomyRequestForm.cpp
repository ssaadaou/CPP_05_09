/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:33:25 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/21 20:36:38 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), Target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string Target) : AForm("RobotomyRequestForm", 72, 45), Target(Target) {}

// copy all the base class data(AForm ) and all specific data of derived class in this case Target
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), Target(copy.Target) {}
// When copying an object that inherits from another class, use the base class's copy constructor to ensure all base class data is correctly copied.
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->Target = other.Target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const { return (Target); }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    else if (!this->getIsSigned())
        throw NotSignedException();
    else
    {
        static int i = 0;
        if (i % 2 == 0)
            std::cout << Target << " has been robotomized successfully" << std::endl;
        else
            std::cout << Target << " the robotomy failed." << std::endl;
        i++;
    }
}