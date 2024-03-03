/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:40:25 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/03 00:24:53 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"



PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    *this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    if (this != &obj)
    {
        vc = obj.vc;
        dq = obj.dq;
    }

    return *this;
}


