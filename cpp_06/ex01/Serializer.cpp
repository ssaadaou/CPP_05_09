/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 06:13:55 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/27 03:19:51 by ssaadaou         ###   ########.fr       */
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

Data *Serializer::deserialize(uintptr_t dataptr)
{
    return reinterpret_cast<Data *>(dataptr);
}

int main()
{
    Data data;
    data.name = "hello";
    data.i = 4;

    uintptr_t dataptr = Serializer::serialize(&data);
    Data *ptr = Serializer::deserialize(dataptr);

    std::cout << "name: " << ptr->name << std::endl;
    std::cout << "n: " << ptr->i << std::endl;
    

    return 0;
}
