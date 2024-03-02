/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:31:25 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/01 15:37:08 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        
        
        
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}
