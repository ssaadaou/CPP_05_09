/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:56:40 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/17 23:22:31 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy)
    : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
    // The member variables are already initialized with `copy`'s values.
    // No further action needed here.
    *this = copy;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->isSigned = other.getIsSigned();
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return (name); }

bool AForm::getIsSigned() const { return (isSigned); }

int AForm::getGradeToSign() const { return (gradeToSign); }

int AForm::getGradeToExecute() const { return (gradeToExecute); }

void AForm::BeSigned(const Bureaucrat &Bureaucrat)
{
    if (Bureaucrat.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
} 

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *AForm::NotSignedException::what() const throw()
{
    return "Not Signed Form!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "AForm: " << form.getName()
        << ", Signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", Grade required to sign: " << form.getGradeToSign()
        << ", Grade required to execute: " << form.getGradeToExecute() << std::endl;
    return out;
}