/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:28:45 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/17 22:08:58 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
    
        std::string getName() const;
        int getGrade() const;
    
        void incrementGrade();
        void decrementGrade();

        void signForm(Form &curr);
    
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
