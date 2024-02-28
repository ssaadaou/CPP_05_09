/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:09:23 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/28 15:29:20 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template <class T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>()
    {
    }

    MutantStack(const MutantStack &obj) : std::stack<T>(obj)
    {
        // *this = obj;
    }

    MutantStack &operator=(const MutantStack &obj)
    {
        if (this != &obj)
            std::stack<T>::operator=(obj);
        return *this;
    }

    ~MutantStack(){};

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin()
    {
        return std::stack<T>::c.begin();
        // return this->c.begin();
    }

    iterator end()
    {
        return std::stack<T>::c.end();
    }
};

#endif
