/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 01:22:32 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/26 02:38:45 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Base.hpp"

Base::~Base()
{
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "unknown Class" << std::endl;
}

// void identify(Base &p)
// {
    
// }

int main()
{
    srand(time(NULL));
    Base *base = NULL;
    int i = rand() % 3;

    if (i == 0)
        base = new A;
    else if (i == 1)
        base = new B;
    else
        base = new C;
        
    identify(base);
    // identify(*base);
    delete base;
    // return 0;
}

