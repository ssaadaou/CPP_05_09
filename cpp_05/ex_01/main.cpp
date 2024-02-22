/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:43:05 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/20 23:41:33 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        
        // creating Bureaucrat
        Bureaucrat chef_1("XXX", 1);// i should check if the both assignment of che1/2 are good
        Bureaucrat chef_2 = Bureaucrat("YYY", 60);
        std::cout << chef_1 << std::endl;

        // creating Form
        Form file = Form("file1", 2, 2);
        Form file2 = Form("file2", 3, 150);

        chef_1.signForm(file);
        chef_2.signForm(file);
        std::cout << std::endl;
        std::cout << "++++++++++++++++++++++++++++++" << std::endl;
        std::cout << file << std::endl;
        std::cout << file2;
        
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    

}