/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:56:40 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/20 18:14:19 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy)
    : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->isSigned = other.getIsSigned();
    return *this;
}

Form::~Form() {}

std::string Form::getName() const { return (name); }

bool Form::getIsSigned() const { return (isSigned); }

int Form::getGradeToSign() const { return (gradeToSign); }

int Form::getGradeToExecute() const { return (gradeToExecute); }

void Form::BeSigned(const Bureaucrat &Bureaucrat)
{
    if (Bureaucrat.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
} 

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form: " << form.getName()
        << ", Signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", Grade required to sign: " << form.getGradeToSign()
        << ", Grade required to execute: " << form.getGradeToExecute() << std::endl;
    return out;
}