/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 00:39:33 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/29 02:52:54 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>

#include <vector>

int main()
{
    std::vector<int> v ;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    // std::vector<int>::iterator it;
    // it = v.end() - 1 ;
    // std::cout << *it << std::endl;
    // std::cout << v.back() << std::endl;
    
    std::vector<int>::iterator it2;
    it2 = std::find(v.begin(), v.end(), 3);
    std::cout << *it2+1 << std::endl;
}

