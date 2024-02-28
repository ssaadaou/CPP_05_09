/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:02:31 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/28 14:06:59 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

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

int main()
{
    //vector
    // std::vector<int> v = {1,4,3,5,6,7,8,9,10};

    std::vector<int> v(100);
    for (int i = 0; i < 100; i++)
        v[i] = 0;
    
    
    easyfind(v, 0);
    
    // easyfind(arr, 2);
    // easyfind(arr, 7);
}
