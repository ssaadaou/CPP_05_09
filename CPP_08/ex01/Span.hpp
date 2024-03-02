/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:27:53 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/01 15:30:43 by ssaadaou         ###   ########.fr       */
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
    unsigned int N;
    std::vector<int> lst;

public:
    Span();
    Span(unsigned int size);
    void addNumber(int nbr);
    Span(const Span &obj);
    Span &operator=(const Span &obj);
    ~Span();
    
    
    size_t shortestSpan() const;
    size_t longestSpan() const;
    
    void addSpan(std::vector<int> v);
    
};

#endif
