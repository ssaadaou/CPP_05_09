/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:40:14 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/04 14:42:22 by ssaadaou         ###   ########.fr       */
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
#include <ctime>


class PmergeMe
{
private:
    std::vector<int> vc;
    std::deque<int> dq;
    
    std::vector<int> chainV;
    std::vector<int> pendV;
    std::deque<int> chainD;
    std::deque<int> pendD;

    std::vector<int> combinaisonIdx;

    int holder;


public:
    PmergeMe(int ac, char **av);
    ~PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);
    void vectorPair(std::vector<int> &vc);
    void dequePair(std::deque<int> &dq);
    void generate_combination();  

    void largeElements(std::deque<std::pair<int, int> > &str);
    void largeElements(std::vector<std::pair<int, int> > &str);
    bool checkDuplicate(std::deque<int> container);
    bool checkDuplicate(std::vector<int> container);
    
    template <typename T>
    void displayData(const T& data,const std::string& msg)
    {
        std::cout << msg << ": ";
        for(size_t i = 0; i < data.size(); i++)
		    std::cout << data[i] << " ";
	    std::cout << std::endl;
    } 
    
};

#endif
