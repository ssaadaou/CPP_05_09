/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:27:19 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/01 15:30:28 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

Span::Span() : N(0), lst()
{
}

Span::Span(unsigned int size) : lst(std::vector<int>()), N(size)
{
}

Span::Span(const Span &obj)
{
    *this = obj;
}

Span &Span::operator=(const Span &obj)
{
    if (this != &obj)
    {
        this->N = obj.N;
        this->lst = obj.lst;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int nbr)
{
    if (lst.size() < this->N)
        lst.push_back(nbr);
    else
        throw std::runtime_error("Container is full");
}

// shortest span
size_t Span::shortestSpan() const
{
    if (lst.size() < 2)
        throw std::runtime_error("Not enough elements to find a span");

    std::vector<int> tmp = lst;
    std::sort(tmp.begin(), tmp.end());
    size_t shortSpan = tmp[1] - tmp[0];
    
    for (size_t i = 1; i < tmp.size(); i++)
    {
        if (tmp[i] - tmp[i - 1] < shortSpan)
            shortSpan = tmp[i] - tmp[i - 1];
    }
    return shortSpan;
}

// longest span
size_t Span::longestSpan() const
{
    if (lst.size() < 2)
        throw std::runtime_error("Not enough elements to find a span");
    
    std::vector<int> tmp = lst;
    std::sort(tmp.begin(), tmp.end());
    size_t longSpan = tmp[tmp.size() - 1] - tmp[0];
    return longSpan;
}

// add span
void Span::addSpan(std::vector<int> v)
{
    if (lst.size() + v.size() > N)
        throw std::runtime_error("Container is full");
    lst.insert(lst.end(), v.begin(), v.end());
}


