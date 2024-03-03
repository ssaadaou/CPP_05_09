/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:40:14 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/03 05:20:53 by ssaadaou         ###   ########.fr       */
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


public:
    PmergeMe(int ac, char **av);
    ~PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    void vectorPair(std::vector<int> &vc);
    void dequePair(std::deque<int> &dq);
    void sortPair(std::vector<std::pair<int, int> > &pairs);
    void recursiveSortLarge(std::vector<int> &chain, int start, int end);
    void merge(std::vector<int>& elements, int start, int mid, int end);
    void insertSmallerElements(std::vector<int>& sortedLarger, const std::vector<int>& smaller);
    

    template <typename T>
    std::vector<int> largeElements(T &str)
    {
        std::vector<int> chain;
        for (size_t i = 0; i < str.size(); i++)
        {
            if (chain.empty())
            {
                chain.push_back(str[i].second);
                chain.push_back(str[i].first);
            }
            else
                chain.push_back(str[i].first);  
        }    
        return chain;
        
    }
};

#endif
