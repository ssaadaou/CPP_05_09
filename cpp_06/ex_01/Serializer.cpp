/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 06:13:55 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/25 23:11:17 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer &obj)
{
    *this = obj;
}

Serializer &Serializer::operator=(Serializer &obj)
{
    (void)obj;
    return *this;
}  

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// uniptr_t is a type that is capable of storing a data pointer into an integer type

Data *Serializer::deserialize(uintptr_t dataptr)
{
    return reinterpret_cast<Data *>(dataptr);
}

int main()
{
    // Data data;
    // data.name = "someone";
    // data.i = 4; 

    // uintptr_t dataptr = Serializer::serialize(&data);
    // Data *ptr = Serializer::deserialize(dataptr);

    // std::cout << "name: " << ptr->name << std::endl;
    // std::cout << "n: " << ptr->i << std::endl;

    // lets test uninptr_t
    int *ptr = new int(42);
    uintptr_t intptr = reinterpret_cast<uintptr_t>(ptr);
    std::cout << "intptr: " << intptr << std::endl;
    
    uintptr_t intptr2 = intptr + 1; 
    std::cout << "intptr2: " << intptr2 << std::endl;
    exit(0);
    // std::string c = "hello";
    // uintptr_t cptr = reinterpret_cast<uintptr_t>(c);
    // std::cout << "cptr: " << cptr << std::endl;
    

    return 0;
}
