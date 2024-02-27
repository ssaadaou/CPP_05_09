/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:17:45 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/27 16:42:53 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) :_size(n)
{
    array = new T[n];
    for (unsigned int i = 0; i < n; i++)
        array[i] = T();
}

//copy constructor
template <typename T>
Array<T>::Array(const Array &other) : _size(other._size)
{
    this->array = NULL;
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] array;
        array = new T[other._size];
        _size = other._size;
        for (unsigned int i = 0; i < _size; i++)
        {
            array[i] = other.array[i];
        }
    }
    return *this;
}
// destructor
template <typename T>
Array<T>::~Array()
{
    delete[] array;
}

//subscript operator
template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw std::out_of_range("Index out of range");
    return array[i];
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
}

int main()
{
   

    Array<int> a(5);
    Array<int> b(5);
    Array<int> c(5);

    a = b;
    c = a;

    return 0;
}
