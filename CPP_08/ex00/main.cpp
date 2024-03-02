/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:02:31 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/01 15:11:21 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

class NotFoundException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Value not found in container";
    }
};

template <typename T>

void easyfind(T &container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        std::cout << "Value >> " << value << " << found in container" << std::endl;
    else
        std::cout << "Value " << value << " not found in container" << std::endl;
}

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try
    {
        easyfind(vec, 30);
        easyfind(vec, 5);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
