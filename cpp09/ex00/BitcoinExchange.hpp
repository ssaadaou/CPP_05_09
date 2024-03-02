/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:15:31 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/02 18:18:14 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <map>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

class BitcoinExchange
{
private:
    // create map
    std::map<std::string, float> ExchangeMap;
    void Exchange(std::string inputFile);
    void fillMap();
    bool Errorfile(std::ifstream &fin, std::string line);
    std::string strim(std::string str);
    bool checkDate(std::string date);
    bool checkYear(std::string year);
    bool checkMonthDay(std::string month, std::string day, std::string year);
    // bool checkDay(std::string day);
    bool checkPrice(double price);
    bool isLeapYear(int year);
    float calculPriceForDate(const std::string &date, float price);

public:
    BitcoinExchange();
    BitcoinExchange(std::string inputFile);
    BitcoinExchange(BitcoinExchange const &src);
    BitcoinExchange &operator=(BitcoinExchange const &obj);

    ~BitcoinExchange();
};

#endif