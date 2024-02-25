/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:12:59 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/24 21:56:36 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("someone", 1);
        // bureaucrat.incrementGrade();
        // // bureaucrat.incrementGrade();
        // bureaucrat.incrementGrade();
        // bureaucrat.decrementGrade();
        // std::cout << bureaucrat << std::endl;
        std::cout << bureaucrat.getGrade() << std::endl;
exit(1);
        Bureaucrat Bureaucrat2("someone2", 150);
        Bureaucrat2.incrementGrade();

        Bureaucrat bureaucrat3(Bureaucrat2);
        std::cout << "copy: " << bureaucrat3.getName() << std::endl;

        
        std::cout << "this line shows that everything work perfectly and there is no exception thrown. " << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}