/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:30:18 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/25 15:44:21 by ssaadaou         ###   ########.fr       */
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

void ScalarConverter::convert(std::string &literal)
{
    if ((literal.length() == 1 && !isdigit(literal[0])) ||
        (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && !isdigit(literal[1])))
    {
        char c = literal[0];
        if (std::isprint(c))
        {
            std::cout << "char: '" << c << "'" << std::endl;
            std::cout << "int: " << static_cast<int>(c) << std::endl;
            std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
        }
        else
            std::cout << "char: Non displayable" << std::endl;
        return;
    }
        
    else if (literal == "nan" || literal == "nanf")
     {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    else if (literal == "+inf" || literal == "inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << ((literal[0] == '-') ? "-inff" : "+inff") << std::endl;
        std::cout << "double: " << ((literal[0] == '-') ? "-inf" : "+inf") << std::endl;
        return;
    }
    
    else if((literal[literal.length() - 1] == 'f' && literal.find('.')) && (literal.length() > 1) )
    {
        literal = literal.substr(0, literal.length() - 1);
        std::cout << "literaaal: " << literal << std::endl;
        
    }
    
    std::stringstream ss(literal.c_str());
    long double value;
    if (!(ss >> value) || !ss.eof())
    {
        std::cout << "Error: Invalid input" << std::endl;
        return;
    }
    else
    {
        char c = static_cast<char>(value);
        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    if(value <= std::numeric_limits<int>::min() || value >= std::numeric_limits<int>::max() )
        std::cout << "int: Out of range" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value)  << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
    
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }
    std::string literal = av[1];
    ScalarConverter::convert(literal);
    return 0;
}