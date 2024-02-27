/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 06:14:07 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/25 22:30:00 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

typedef struct s_data
{
    std::string name;
    int i;
} Data;

class Serializer
{

private:
    Serializer();

public:
    Serializer(Serializer &obj);
    Serializer &operator=(Serializer &obj);
    ~Serializer();

    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t dataptr);
};

#endif