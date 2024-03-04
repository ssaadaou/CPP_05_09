/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:40:25 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/04 15:02:45 by ssaadaou         ###   ########.fr       */
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
        chainV = obj.chainV;
        pendV = obj.pendV;
        combinaisonIdx = obj.combinaisonIdx;
        holder = obj.holder;
    }
    return *this;
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
    if (checkDuplicate(vc))
        throw std::invalid_argument("Error: Duplicate values.");

    displayData(vc, "Before Sorting");
    vectorPair(vc);
    displayData(dq, "Before Sorting");
    dequePair(dq);
}

void PmergeMe::PmergeMe::generate_combination()
{
    size_t size = pendV.size();
    int jacobsthalSequence[size + 3];

    jacobsthalSequence[0] = 0;
    jacobsthalSequence[1] = 1;
    int limit = 2;

    for (size_t i = 2; combinaisonIdx.size() < size; i++)
    {
        jacobsthalSequence[i] = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2]; // 0 1 1 3 5 11

        combinaisonIdx.push_back(jacobsthalSequence[i]); // 1 5

        for (int j = jacobsthalSequence[i] - 1; j > limit; j--)
            combinaisonIdx.push_back(j);

        limit = jacobsthalSequence[i];
    }
}

/********************************************************************************/
bool PmergeMe::checkDuplicate(std::vector<int> container)
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

void PmergeMe::largeElements(std::vector<std::pair<int, int> > &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (chainV.empty())
        {
            chainV.push_back(str[i].second);
            chainV.push_back(str[i].first);
        }
        else
            chainV.push_back(str[i].first);
        pendV.push_back(str[i].second);
    }
}


void PmergeMe::vectorPair(std::vector<int> &vc)
{
    holder = -1;
    std::vector<int> test = vc;
    std::sort(test.begin(), test.end());
    std::clock_t start = std::clock();

    if (vc.size() % 2 != 0)
    {
        holder = vc[vc.size() - 1];
        vc.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
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

    for (size_t i = 0; i < pendV.size(); i++)
    {
        std::vector<int>::iterator it1;
        if (combinaisonIdx[i] >= (int)pendV.size())
            combinaisonIdx[i] = i;
        it1 = std::lower_bound(chainV.begin(), chainV.end(), pendV[combinaisonIdx[i]]);
        if (std::find(chainV.begin(), chainV.end(), pendV[combinaisonIdx[i]]) != chainV.end())
            continue;
        chainV.insert(it1, pendV[combinaisonIdx[i]]);
    }

    if (holder != -1)
    {
        std::vector<int>::iterator it2;
        it2 = std::lower_bound(chainV.begin(), chainV.end(), holder);
        if (holder == test[0])
            chainV.insert(chainV.begin(), holder);
        else
            chainV.insert(it2, holder);
    }
    if (holder != -1)
        vc.push_back(holder);
    std::clock_t end = std::clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000000;
    displayData(chainV, "After Sorting");
    std::cout << "Time to process a range of " << vc.size() << " elements with std::vector: " << elapsed_time << std::endl;
}

/***********************dequePart*****************************/

bool PmergeMe::checkDuplicate(std::deque<int> container)
{
    for (std::deque<int>::iterator it = container.begin(); it != container.end(); it++)
    {
        for (std::deque<int>::iterator it2 = container.begin(); it2 != container.end(); it2++)
        {
            if (it != it2 && *it == *it2)
                return true;
        }
    }
    return false;
}

void PmergeMe::largeElements(std::deque<std::pair<int, int> > &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (chainD.empty())
        {
            chainD.push_back(str[i].second);
            chainD.push_back(str[i].first);
        }
        else
            chainD.push_back(str[i].first);
        pendD.push_back(str[i].second);
    }
}

void PmergeMe::dequePair(std::deque<int> &dq)
{
    holder = -1;
    std::deque<int> test = dq;
    std::sort(test.begin(), test.end());
    std::clock_t start = std::clock();
    
    std::deque<std::pair<int, int> > pairs;
    if (dq.size() % 2 != 0)
    {
        holder = dq[dq.size() - 1];
        dq.pop_back();
    }

    for (size_t i = 0; i < dq.size(); i += 2)
    {
        if (dq[i] > dq[i + 1])
            pairs.push_back(std::make_pair(dq[i], dq[i + 1]));
        else
            pairs.push_back(std::make_pair(dq[i + 1], dq[i]));
    }
    std::sort(pairs.begin(), pairs.end());

    largeElements(pairs);
    generate_combination();

    for (size_t i = 0; i < pendD.size(); i++)
    {
        std::deque<int>::iterator it1;
        if (combinaisonIdx[i] >= (int)pendD.size())
            combinaisonIdx[i] = i;
        it1 = std::lower_bound(chainD.begin(), chainD.end(), pendD[combinaisonIdx[i]]);
        if (std::find(chainD.begin(), chainD.end(), pendD[combinaisonIdx[i]]) != chainD.end())
            continue;
        chainD.insert(it1, pendD[combinaisonIdx[i]]);
    }

    if (holder != -1)
    {
        std::deque<int>::iterator it2;
        it2 = std::lower_bound(chainD.begin(), chainD.end(), holder);
        if (holder == test[0])
            chainD.insert(chainD.begin(), holder);
        else
            chainD.insert(it2, holder);
    }
    if (holder != -1)
        dq.push_back(holder);
    std::clock_t end = std::clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000000;
    displayData(chainD, "After Sorting");
    std::cout << "Time to process a range of " << dq.size() << " elements with std::vector: " << elapsed_time << std::endl;
}
