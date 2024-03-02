/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:03:47 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/02 18:18:31 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
    
}

BitcoinExchange::BitcoinExchange(std::string inputFile)
{
    fillMap();

    Exchange(inputFile);   
}


BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj)
{
    *this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &obj)
{
    (void)obj;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: wrong number of arguments." << std::endl;
        return (1);
    }
    BitcoinExchange exchange (av[1]);
}