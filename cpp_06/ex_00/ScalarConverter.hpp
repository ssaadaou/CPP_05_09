/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:30:21 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/22 05:39:24 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

// #include <iostream>
#include <sstream>
// #include <string>
// #include <limits>
// #include <cstdlib>

#include <iostream>
#include <string>
#include <limits> // For std::numeric_limits
#include <cmath>  // For std::floor and other math functions
#include <cctype> // For std::isprint
#include <cstdlib> // For std::strtod
#include <cerrno>
#include <typeinfo>
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
