/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:40:14 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/04 00:32:23 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <climits>
#include <sstream>
#include <stdexcept>
#include <stdio.h>


class PmergeMe
{
private:
    std::vector<int> vc;
    std::deque<int> dq;
    
    std::vector<int> chain;
    std::vector<int> pend;

    std::vector<int> combinaisonIdx;

    int holder;


public:
    PmergeMe(int ac, char **av);
    ~PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    void vectorPair(std::vector<int> &vc);
    // void dequePair(std::deque<int> &dq);
    void generate_combination();
    

    template <typename T>
    void largeElements(T &str)
    {
        for (size_t i = 0; i < str.size(); i++)
        {
            if (chain.empty())
            {
                chain.push_back(str[i].second);
                chain.push_back(str[i].first);
            }
            else
                chain.push_back(str[i].first);
            pend.push_back(str[i].second); 
        }    
        
    }
};

#endif
