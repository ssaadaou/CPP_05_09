/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:04:24 by ssaadaou          #+#    #+#             */
/*   Updated: 2024/03/04 12:53:56 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

std::string BitcoinExchange::strim(std::string str)
{
    std::string::size_type start;
    std::string::size_type end;

    start = str.find_first_not_of(" \t");
    end = str.find_last_not_of(" \t");

    if (start == std::string::npos)
        return "";
    return (str.substr(start, end - start + 1));
}

void BitcoinExchange::fillMap()
{
    std::ifstream cvs("data.csv");
    std::string line;
    if (cvs.fail())
    {
        std::cerr << "Opening csv file." << std::endl;
        return;
    }
    while (std::getline(cvs, line))
    {
        std::istringstream iss(line);
        std::string date;
        float price;
        if (std::getline(iss, date, ',') && iss >> price)
            ExchangeMap[date] = price;
        
    }
    cvs.close();

}

bool BitcoinExchange::Errorfile(std::ifstream &input, std::string line)
{
    if (input.fail())
    {
        std::cerr << "Error :Opening input file." << std::endl;
        return false;
    }
    if (input.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "Errpr: Empty file." << std::endl;
        return false;
    }
    std::getline(input, line);
    if (line.compare("date | value") != 0)
    {
        std::cerr << "Error: Invalid input format." << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::checkYear(std::string year)
{
    if (year.length() != 4)
    {
        std::cerr << "Error: Invalid year format." << std::endl;
        return false;
    }
    if (atoi(year.c_str()) < 2008)
    {
        std::cerr << "Error: Year out of range" << std::endl;
        return false;
    }

    return true;
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::checkMonthDay(std::string month, std::string day, std::string year)
{
    int m = atoi(month.c_str());
    int d = atoi(day.c_str());
    int y = atoi(year.c_str());

    if (month.length() != 2)
    {
        std::cerr << "Error: Invalid month format." << std::endl;
        return false;
    }
    if (m < 1 || m > 12 || d < 1 || d > 31)
    {
        std::cerr << "Error: invalid date => " << year << "-" << month << "-" << day << std::endl;

        return false;
    }
    if (m == 2)
    {
        if (isLeapYear(y) && d > 29)
        {
            std::cerr << "Error: invalid date => " << year << "-" << month << "-" << day << std::endl;
            return false;
        }
        else if (!isLeapYear(y) && d > 28)
        {
            std::cerr << "Error: invalid date => " << year << "-" << month << "-" << day << std::endl;
            return false;
        }
    }
    else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
    {
        std::cerr << "Error: invalid date => " << year << "-" << month << "-" << day << std::endl;
        return false;
    }
    else if (d > 31)
    {
        std::cerr << "Error: invalid date => " << year << "-" << month << "-" << day << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::checkDate(std::string date)
{
    std::istringstream iss(date);
    std::string year, month, day;

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        std::cerr << "Error bad input => " << date << std::endl;
        return false;
    }
    std::getline(iss, year, '-');
    std::getline(iss, month, '-');
    std::getline(iss, day, '-');
    if (!checkYear(year) || !checkMonthDay(month, day, year))
        return false;
    return true;
}

bool BitcoinExchange::checkPrice(double price)
{
    if (price < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    else if (price > 1000)
    {
        std::cerr << "Error:  too large a number." << std::endl;
        return false;
    }
    
    return true;
}

float BitcoinExchange::calculPriceForDate(const std::string &date, float price)
{
    std::map<std::string, float>::iterator it = ExchangeMap.find(date);
    if (it != ExchangeMap.end())
    {
        return (price * it->second);
    }
    else
    {
        it = ExchangeMap.lower_bound(date);
        if (it != ExchangeMap.begin())
        {
            --it;
            return (price * it->second);
        }
    }
    return -1;
}


void BitcoinExchange::Exchange(std::string inputFile)
{
    std::ifstream input(inputFile.c_str());
    std::string line, date;
    float price = 0.0;

    if (!Errorfile(input, line))
    {
        input.close();        
        return;
    }

    while (std::getline(input, line))
    {
        if (line.empty() || line.find_first_not_of(" \t\n\r") == std::string::npos)
            continue;
        std::istringstream iss(line);
        if (!std::getline(iss, date, '|') || !(iss >> price) || !iss.eof() || iss.fail())
        {
            std::cerr << "Error: parsing line => " << line << std::endl;
            continue;
        }
        date = strim(date);
        if (!checkDate(date) || !checkPrice(price))
            continue;
        float result = calculPriceForDate(date, price);
        if (result >= 0)
            std::cout << date << " => " << price << " = "  << result << std::endl;
        else
            std::cout << "Error: No price available for date " << date << std::endl;
    }

    input.close();
}
