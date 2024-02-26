/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 01:23:03 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/26 01:23:37 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>
#include <exception>

class Base
{
	public: 
		virtual ~Base();
};

class A : public Base {};

class B : public Base{};

class C : public Base {};

#endif