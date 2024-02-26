/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:21:43 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/26 15:25:43 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename Type>
void swap(Type &a, Type &b)
{
    Type tmp = a;
    a = b;
    b = tmp;
}

template <typename Type1>
Type1 min(Type1 a, Type1 b)
{
    return (a < b) ? a : b;
}

template <typename Type2>
Type2 max(Type2 a, Type2 b)
{
    return (a > b) ? a : b;
}

#endif