/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:10:03 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/02 19:48:24 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &obj)
{
    *this = obj;
}

RPN &RPN::operator=(const RPN &obj)
{
    if (this != &obj)
        this->_stack = obj._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::checkError(std::string input)
{
    int i = 0;
    if (input.empty())
    {
        std::cerr << "Error: empty string." << std::endl;
        return false;
    }

    while (input[i])
    {
        char c = input[i];
        if (!isdigit(c) && c != ' ' && c != '+' && c != '-' && c != '*' && c != '/')
        {
            std::cerr << "Error: invalid character => " << c << std::endl;
            return false;
        }
        i++;
    }

    return true;
}

bool RPN::isOperator(std::string token)
{
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return true;
    return false;
}

void RPN::excecute(std::string input)
{
    int num = 0;
    std::istringstream iss(input);
    std::string token;
    std::istringstream tokStream(input);
    
    if (!checkError(input))
        return;
        
    while (getline(iss, token, ' '))
    {
        if (isdigit(token[0]))
        {
            tokStream >> num;
            if (num < 0 || num > 9)
            {
                std::cerr << "Error: invalid number => " << token << std::endl;
                return;
            }
            _stack.push(num);
        }
        else if(isOperator(token))
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error: not enough operands." << std::endl;
                return;
            }
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            std::cout << "a: " << a << " b: " << b << std::endl;

            if (token == "+")
                _stack.push(b + a);
            else if (token == "-")
                _stack.push(b - a);
            else if (token == "*")
                _stack.push(b * a);
            else if (token == "/")
            {
                if (a == 0)
                {
                    std::cerr << "Error: division by zero." << std::endl;
                    return;
                }
                _stack.push(b / a);
            }
            // iterate through the stack
            std::stack<int> tmp = _stack;
            while (!tmp.empty())
            {
                std::cout << "-----" << tmp.top() << " ";
                tmp.pop();
            }
            
        }
    }
    if (_stack.size() != 1)
        std::cerr << "Error: invalid RPN expression." << std::endl;
    else 
        std::cout << _stack.top() << std::endl;
}
