/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:02:01 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/01 15:07:19 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class NotFoundException : public std::exception
{
public:
    const char* what() const throw() 
    {
        return "Value not found in container";
    }
};

template <typename T>

void	easyfind(T &container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        std::cout << "Value >> " << value << " << found in container" << std::endl;
    else
        std::cout << "Value " << value << " not found in container" << std::endl;
}

#endif