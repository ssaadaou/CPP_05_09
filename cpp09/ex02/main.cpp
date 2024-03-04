/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:40:34 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/04 00:26:00 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"



int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Incorrect input. " << std::endl;
        return 1;
    }
    try
    {
        PmergeMe pm(ac, av);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
