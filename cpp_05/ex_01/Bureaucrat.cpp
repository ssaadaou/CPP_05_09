/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:28:49 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/20 18:29:22 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->grade = other.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    ++grade;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

std::ostream &operator<<(std::ostream &out_stream, const Bureaucrat &bureaucrat)
{
    out_stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out_stream;
}

void Bureaucrat::signForm(Form &curr)
{
    try
    {
        curr.BeSigned(*this);
        std::cout << this->getName() << " signed " << curr.getName() << std::endl;
    }
    catch (const std::exception &reason)
    {
        std::cout << this->getName() << " couldn’t sign "
            << curr.getName() << " because " << reason.what() << std::endl ;
    }
}
