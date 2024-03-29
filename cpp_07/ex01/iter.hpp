/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:28:35 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/28 19:18:14 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int length, void (*function)(T &))
{
    if (!array || !function)
        return;
    if(length <= 0)
    {
        std::cout << "Not a valid length" << std::endl;
        return ;
    }
    for (int i = 0; i < length; i++)
        function(array[i]);
}

#endif
