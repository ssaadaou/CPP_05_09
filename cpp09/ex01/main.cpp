/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:49:54 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/03 22:39:48 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac != 2)
    {
        std::cerr << "Error: wrong argument." << std::endl;
        return 1;
    }
    RPN rpn;
    rpn.excecute(av[1]);    
}

