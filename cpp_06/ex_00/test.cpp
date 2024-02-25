/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 23:48:06 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/25 02:05:35 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ScalarConverter.hpp"

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

bool isChar(const std::string &literal)
{
    if (literal.length() == 1 && !isdigit(literal[0]))
        return true;
    return false;
}

bool isInt(const std::string &literal)
{
    if (isdigit(literal[0]) || (literal[0] == '-' && isdigit(literal[1])) || (literal[0] == '+' && isdigit(literal[1])))
        return true;
    return false;
}

bool isFloat(const std::string &literal)
{
    if (literal.find('.') != std::string::npos)
        return true;
    return false;
}

bool isSpecial(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "inf" || literal == "-inf")
        return true;
    return false;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (isChar(literal))
    {
        char c = literal[0];
        if(std::isprint(c))
        {
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << std::endl;
            std::cout << "double: " << static_cast<double>(c) << std::endl;           
        }
        else
            std::cout << "Error : not printable" << std::endl;
        return;       
    }
    else if(isFloat(literal))
    {
        puts("float");
        std::stringstream ss(literal);
        double f;
        ss >> f;
        std::cout << "f: " << f << std::endl;
        if (ss.fail() || !ss.eof())
        {
            std::cout << "Error : impossible" << std::endl;
            return;
        }
        std::cout << "char: " << static_cast<char>(f) << std::endl;
        std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << "float: " << f << 'f' << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else if(isSpecial(literal))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal + 'f' << std::endl;
        std::cout << "double: " << literal << std::endl;
    }
    
    else if(isInt(literal))
    {
        puts("int" );
        std::stringstream ss(literal);
        double i;
        ss >> i;
        if (ss.fail() || !ss.eof())
        {
            std::cout << "Error : impossible" << std::endl;
            return;
        }
        std::cout << "char: " << static_cast<char>(i) << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "0.f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    }
    
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}