/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:45:03 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/28 19:17:37 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "iter.hpp"

template <typename T>
void print(T &value)
{
    std::cout << value << std::endl;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    std::string str[] = {"hello", "world"};
    iter(array, 5, print);
    iter(str, 2, print);
    return 0;
}
