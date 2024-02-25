/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:11:33 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/02/24 22:42:21 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern 
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(std::string formName, std::string target) const;
};

#endif
