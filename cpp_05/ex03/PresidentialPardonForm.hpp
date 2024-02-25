/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:33:26 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/19 18:35:21 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <fstream>
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string Target;
    
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string Target); // used to declare them but  (, int gradeToSign, int gradeToExecute);
    PresidentialPardonForm(const PresidentialPardonForm &copy);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();

    std::string getTarget() const;
    
    void execute(Bureaucrat const &executor) const;
};

#endif