/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:40:25 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/04 00:33:16 by ssaadaou         ###   ########.fr       */
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


bool    checkDuplicates(std::vector<int> container)
{
    for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++)
    {
        for (std::vector<int>::iterator it2 = container.begin(); it2 != container.end(); it2++)
        {
            if (it != it2 && *it == *it2)
                return true;
        }
    }
    return false;
}

void PmergeMe::vectorPair(std::vector<int> &vc)
{
    if (checkDuplicates(vc))
        throw std::invalid_argument("Error: Duplicate values.");
    
    holder = -1;
    std::vector<int> test = vc;
    std::sort(test.begin(), test.end());
    
    std::vector<std::pair<int, int> > pairs;
    if(vc.size() % 2 != 0)
    {
        holder = vc[vc.size() - 1];
        vc.pop_back();
    }
    
    for (size_t i = 0; i < vc.size(); i += 2)
    {        
        if (vc[i] > vc[i + 1])
            pairs.push_back(std::make_pair(vc[i], vc[i + 1]));
        else
            pairs.push_back(std::make_pair(vc[i + 1], vc[i]));
    } 
    std::sort(pairs.begin(), pairs.end());
    

   largeElements(pairs);
   generate_combination();
  
    for (size_t i = 0; i < pend.size(); i++)
    {
        std::vector<int>::iterator it1;
        if (combinaisonIdx[i] >= (int)pend.size())
            combinaisonIdx[i] = i;
        it1 = std::lower_bound(chain.begin(), chain.end(), pend[combinaisonIdx[i]]);
        if (std::find(chain.begin(), chain.end(), pend[combinaisonIdx[i]]) != chain.end())
            continue;
        chain.insert(it1, pend[combinaisonIdx[i]]);
    }
   
    if (holder != -1)
    {
        std::vector<int>::iterator it2;
        it2 = std::lower_bound(chain.begin(), chain.end(), holder);
        if (holder == test[0])
            chain.insert(chain.begin(), holder);
        else
            chain.insert(it2, holder);
    }
    chain.insert(chain.begin(), test[0]);

    if(holder != -1)
        vc.push_back(holder);
    // for (size_t i = 0; i < vc.size(); i++)
    // {
    //     std::cout << vc[i] << " ";
    // }
    // std::cout << std::endl;
    // for (size_t i = 1; i < chain.size(); i++)
    // {
    //         std::cout << chain[i] << " ";
    // }

}

PmergeMe::PmergeMe(int ac, char **av)
{
    std::vector<int> vc;
    std::deque<int> dq;
    int number;

    for (int i = 1; i < ac; i++)
    {
        std::stringstream ss(av[i]);
        if (!(ss >> number) || !ss.eof())
            throw std::invalid_argument("Error: Invalid input. ");
        if (number < 0 || number > INT_MAX)
            throw std::out_of_range("Error: Input out of range.");
        vc.push_back(number);
        dq.push_back(number);
    }
    
    vectorPair(vc);
    // dequePair(dq);
   
}

void PmergeMe::PmergeMe::generate_combination()
{
    size_t size = pend.size();
    int jacobsthalSequence[size + 3];

    jacobsthalSequence[0] = 0;
    jacobsthalSequence[1] = 1;
    int limit = 2;

    for (size_t i = 2; combinaisonIdx.size() < size; i++)
    {
        jacobsthalSequence[i] = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2];// 0 1 1 3 5 11

        combinaisonIdx.push_back(jacobsthalSequence[i]);//1 5

        for (int j = jacobsthalSequence[i] - 1; j > limit; j--)// j = 10; 10> 5; j--
            combinaisonIdx.push_back(j);

        limit = jacobsthalSequence[i];
    }
}

/***********************dequePart*****************************/



// void PmergeMe::dequePair(std::deque<int> &dq)
// {
//     std::vector<std::pair<int, int> > pairs;
//     std::vector<int> chain;
     
     
//     if(dq.size() % 2 != 0)
//         dq.pop_back();
    
//     for (size_t i = 0; i < dq.size(); i += 2)
//     {        
//         if (dq[i] > dq[i + 1])
//             pairs.push_back(std::make_pair(dq[i], dq[i + 1]));
//         else
//             pairs.push_back(std::make_pair(dq[i + 1], dq[i]));
//     }
//     largeElements(pairs);
//     recursiveSortLarge(chain, 0, chain.size() - 1);
    

// }