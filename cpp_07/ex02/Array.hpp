/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:48:50 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/27 16:42:40 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array
{
private:
    T *array;
    unsigned int _size;

public:
    // Constructors
    Array() ;
    Array(unsigned int n) ;
    
    // copy constructor
    Array(const Array &other);
    
   Array &operator=(const Array &other);
   // subscript operator
    T& operator[](unsigned int i);
    unsigned int size() const { return _size;};
   ~Array();

}

#endif