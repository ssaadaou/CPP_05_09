/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:35:45 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/24 22:37:24 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm(Target, 25, 5), Target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string Target) : AForm(Target, 25, 5), Target(Target) {}

 
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), Target(copy.Target) {}
 PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->Target = other.Target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const { return (Target); }

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    else if (!this->getIsSigned())
        throw NotSignedException();
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}