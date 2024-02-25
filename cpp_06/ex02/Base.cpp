/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 04:52:32 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/25 05:07:03 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Base.hpp"

Base::~Base() {}

Base* generate(void)
{
	int random = std::rand() % 3;

	switch (random)
	{
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return new A;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class type A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class type B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class type C." << std::endl;
	else
		std::cout << "unknown Class." << std::endl;
}

void identify(Base& p)
{
    A a;
    B b;
    C c;
	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << "Class type A." << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
    {
		try
		{
			b = dynamic_cast<B&>(p);
			std::cout << "Class type B." << std::endl;
		}
		catch(const std::exception& e)
        {
			try
			{
				c = dynamic_cast<C&>(p);
				std::cout << "Class type C." << std::endl;
			}
			catch(const std::exception& e)
            {
				std::cout << "unknown Class." << std::endl;
			}
		}
		
	}
}

int main()
{
    Base* obj = generate();
    identify(obj);
    identify(*obj);
    delete obj;
    return 0;
}