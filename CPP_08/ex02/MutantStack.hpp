/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:09:23 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/01 18:05:26 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iostream>


template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack()
    {
    }

    MutantStack(const MutantStack &obj)
    {
        *this = obj;
    }

    MutantStack &operator=(const MutantStack &obj)
    {
        if (this != &obj)
            this->c = obj.c;
        return *this;
    }

    ~MutantStack(){};

    typedef typename std::deque<T>::iterator iterator;
    iterator begin()
    {
        return this->c.begin();
    }

    iterator end()
    {
        return this->c.end();
    }
};

#endif
