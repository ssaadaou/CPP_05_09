/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:30:21 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/25 00:36:36 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>

class ScalarConverter
{
private:
    ScalarConverter(); //prevent instanciation

public:
    // ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

    static void convert(const std::string &literal);
};

#endif
