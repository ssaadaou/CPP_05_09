/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:33:30 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/19 17:41:38 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <fstream>
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string Target;
    
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string Target); // used to declare them but  (, int gradeToSign, int gradeToExecute);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    std::string getTarget() const;
    
    void execute(Bureaucrat const &executor) const;
};

#endif