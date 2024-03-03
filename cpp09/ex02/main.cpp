/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:40:34 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/03 05:40:25 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

void PmergeMe::merge(std::vector<int>& elements, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = elements[start + i];
    for (int j = 0; j < n2; j++) R[j] = elements[mid + 1 + j];

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j])
        {
            elements[k] = L[i];
            i++;
        }
        else
        {
            elements[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
        elements[k++] = L[i++];
    while (j < n2) 
        elements[k++] = R[j++];

    
}


void PmergeMe::recursiveSortLarge(std::vector<int> &chain, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;
    recursiveSortLarge(chain, start, mid);
    recursiveSortLarge(chain, mid + 1, end); 
    merge(chain, start, mid, end);
}



void PmergeMe::vectorPair(std::vector<int> &vc)
{
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> chain;
    if(vc.size() % 2 != 0)
        vc.pop_back();
    
    for (size_t i = 0; i < vc.size(); i += 2)
    {        
        if (vc[i] > vc[i + 1])
            pairs.push_back(std::make_pair(vc[i], vc[i + 1]));
        else
            pairs.push_back(std::make_pair(vc[i + 1], vc[i]));
    }    
    chain = largeElements(pairs);
    recursiveSortLarge(chain, 0, chain.size() - 1);    
}

void PmergeMe::dequePair(std::deque<int> &dq)
{
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> chain;
     
     
    if(dq.size() % 2 != 0)
        dq.pop_back();
    
    for (size_t i = 0; i < dq.size(); i += 2)
    {        
        if (dq[i] > dq[i + 1])
            pairs.push_back(std::make_pair(dq[i], dq[i + 1]));
        else
            pairs.push_back(std::make_pair(dq[i + 1], dq[i]));
    }
    chain = largeElements(pairs);
    recursiveSortLarge(chain, 0, chain.size() - 1);
    

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
    dequePair(dq);
   
}


int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Incorrect input. " << std::endl;
        return 1;
    }
    try
    {
        PmergeMe pm(ac, av);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
