/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:28:35 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/26 15:50:26 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*function)(T &))
{
    if (!array || !function)
        return;
    
    for (size_t i = 0; i < length; i++)
        function(array[i]);
}

#endif
