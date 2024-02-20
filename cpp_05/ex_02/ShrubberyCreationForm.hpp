/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:31:35 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/19 16:02:26 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string Target;
    
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string Target); // used to declare them but  (, int gradeToSign, int gradeToExecute);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    std::string getTarget() const;
    
    void execute(Bureaucrat const &executor) const;
};

#endif