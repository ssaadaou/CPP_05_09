/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:18:24 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/24 22:36:26 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

// #include "AForm.cpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat MaxPower("milo", 1);                // Create a bureaucrat with highest grade
        ShrubberyCreationForm gardenForm("garden"); // Create form targeting garden
        RobotomyRequestForm robotomyForm("robotomy");
        PresidentialPardonForm pardonForm("pardon");

        MaxPower.signForm(gardenForm); // MaxPower sign the form
        MaxPower.executeForm(gardenForm);  // Execute the form to create ASCIIart file.
        std::cout <<  std::endl;
        std::cout << "+++++++++++++++++++" << std::endl;
        std::cout <<  std::endl;
        MaxPower.signForm(robotomyForm);
        MaxPower.executeForm(robotomyForm);
        MaxPower.executeForm(robotomyForm);
        std::cout <<  std::endl;
        std::cout << "+++++++++++++++++++" << std::endl;
        std::cout <<  std::endl;
        MaxPower.signForm(pardonForm);
        MaxPower.executeForm(pardonForm);

    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}