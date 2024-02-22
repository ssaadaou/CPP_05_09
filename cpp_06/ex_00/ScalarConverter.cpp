/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:30:18 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/22 05:42:13 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"
#include <limits.h>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

// bool isChar(const std::string &literal)
// {
//     // if (literal.length() == 1 && !isdigit(literal[0]))
//     //     return true;
//     if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && !isdigit(literal[1]))
//         return true;
//     return false;
// }

// void convertAndPrint(const std::string& input) 
// {
//     char* endPtr;
//     errno = 0;
    
//     if(input.empty())
//     {
//         std::cout << "Error: Empty input" << std::endl;
//         return;
//     }

//     if(isChar(input))
//     {
//         std::cout << "As int: " << static_cast<int>(input[0]) << std::endl;
//         std::cout << "As char: " << input[0] << std::endl;
//         std::cout << "As float: " << static_cast<float>(input[0]) << 'f' << std::endl;
//         std::cout << "As double: " << static_cast<double>(input[0]) <<  std::endl;
//         return;
//     }
      
//     double num = std::strtod(input.c_str(), &endPtr);
//     if (*endPtr != '\0' || errno == ERANGE) 
//     {
//         std::cout << "Error: Invalid input or out of range" << std::endl;
//         return;
//     }

//     if (num >= INT_MIN && num <= INT_MAX)
//         std::cout << "As int: " << static_cast<int>(num) << std::endl;
//     else
//         std::cout << "As int: Overflow" << std::endl;
    
//     if (num >= std::numeric_limits<char>::min() && num <= std::numeric_limits<char>::max() && std::floor(num) == num)
//     {
//         char character = static_cast<char>(num);
//         if (std::isprint(character))
//             std::cout << "As char: " << character << std::endl;
//         else
//             std::cout << "As char: Non-displayable" << std::endl;
//     }
//     else
//         std::cout << "As char: Not a valid char value" << std::endl;
    
//     std::cout << "As float: " << static_cast<float>(num) << 'f' << std::endl;
//     std::cout << "As double: " << num << std::endl;
// }

void ScalarConverter::convert(const std::string &literal)
{
    if ((literal.length() == 1 && !isdigit(literal[0])) || (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && !isdigit(literal[1])))
    {
        char c = literal[0];
        if (std::isprint(c)) {
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
            // The rest of the conversions
        }
        return;
    }
    std::stringstream ss(literal.c_str());
    long double value;

    // Attempt to parse the literal as a long double
    if (!(ss >> value) || !ss.eof())
    {
        std::cout << "input: " << literal << "type: " << typeid(literal).name() << std::endl;
        std::cout << "Error: Invalid input format." << std::endl;
        return;
    }

    // Check for special cases: nan, inf
     if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    if (literal == "+inf" || literal == "inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << ((literal[0] == '-') ? "-inff" : "+inff") << std::endl;
        std::cout << "double: " << ((literal[0] == '-') ? "-inf" : "+inf") << std::endl;
        return;
    }

    // Convert and print as char
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max() || std::isnan(value) || std::isinf(value))
        std::cout << "char: impossible" << std::endl;
    else
    {
        char c = static_cast<char>(value);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    // Convert and print as int
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value) || std::isinf(value))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    // Convert and print as float and double
    std::cout << "float: " << static_cast<float>(value) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        ScalarConverter::convert(av[1]);
    }
    else
        std::cout << "Usage: ./convert [literal]" << std::endl;
}