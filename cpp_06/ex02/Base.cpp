/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 01:22:32 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/26 15:00:12 by ssaadaou         ###   ########.fr       */
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

void identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unknown class" << std::endl;
    }

    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unknown class" << std::endl;
    }

    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unknown class" << std::endl;
    }
}

Base * generate(void)
{
    int i = rand() % 3;
    std::cout << "i = " << i << std::endl;

    if (i == 0)
        return new A;
    else if (i == 1)
        return new B;
    else if(i == 2)
        return new C;
    return NULL;
}

int main()
{
    // srand(time(NULL));
    Base *base = NULL;
    base = generate();        
    identify(base);
    identify(*base);
    delete base;
}

