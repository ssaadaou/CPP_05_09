/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:11:16 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/02 23:07:42 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>


class RPN
{
private:
    std::stack<int> _stack;

public:
    RPN();
    RPN(const RPN &obj);
    RPN &operator=(const RPN &src);
    ~RPN();
    void excecute(std::string input);
    bool checkError(std::string input);
    bool isOperator(std::string token);

    bool isNumber(std::string token);
};



#endif
