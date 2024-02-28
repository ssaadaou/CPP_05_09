/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:27:53 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/28 15:06:47 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef APAN_HPP
#define APAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
private:
    Span();
    unsigned int N;
    std::vector<int> lst;

public:
    Span(unsigned int size);
    void addNumber(int nbr);
    //copy constructor
    Span(const Span &obj);
    //assignment operator
    Span &operator=(const Span &obj);
    //destructor
    ~Span();
    
    //short span
    size_t shortestSpan() const;
    size_t longestSpan() const;
    
    // add span
    void addSpan(std::vector<int> v);
    
};

#endif
