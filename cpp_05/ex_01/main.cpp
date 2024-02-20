/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:43:05 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/19 16:39:49 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // creating Bureaucrat
    Bureaucrat chef_1("XXX", 1);// i should check if the both assignment of che1/2 are good
    Bureaucrat chef_2 = Bureaucrat("YYY", 60);

    // creating Form
    Form file = Form("file1", 2, 2);
    Form _file = Form("file2", 150, 150);

    chef_1.signForm(file);
    chef_2.signForm(file);
    chef_2.signForm(_file);
}