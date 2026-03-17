#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>//for ifstream
#include <sstream>
#include <stdexcept>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& HistoryFile)
{
    loadHistory(HistoryFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : DtRtMap(other.DtRtMap) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        DtRtMap = other.DtRtMap;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


//std::ifstream is a C++ class for "opening" and reading files.from <fstream>
// i → input// f → file// stream → stream of data
//std::istringstream is a class that reads from a string from:<sstream>
// It treats a string like input data and extract parts from it using the space or a custom delimiter


//load the CSV database into the DtRtMap (date → rate)
void BitcoinExchange::loadHistory(const std::string& HistoryFile)
{
    std::ifstream file(HistoryFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string line;
    std::getline(file, line); // skip header "date,exchange_rate"

    while (std::getline(file, line))//read line by line until end of file
    {
        std::istringstream iss(line);//prepare current line to extract date and rate
        std::string date, rateStr;//variable to store date and rate as string

        if (!std::getline(iss, date, ',') || !std::getline(iss, rateStr))
            continue; //skip unnecessary lines
        DtRtMap[date] = std::atof(rateStr.c_str());//turn rate string into float and store in map with date as key
    }
    
}
//c_str() converts C++ string to C-style string (const char*) for atof
//key = date// value = rate
//Example:// DtRtMap["2009-01-02"] = 0.5

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    
    if (date.length() != 10)// must be exactly YYYY-MM-DD
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    int month = std::atoi(date.substr(5, 2).c_str());//c_str() converts C++ string to C-style string (const char*) for atoi
    int day   = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31)     return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) const
{
    // check for non-numeric characters (allow one dot and leading minus)
    bool hasDot = false;
    for (size_t i = 0; i < value.length(); i++)
    {
        if (i == 0 && value[i] == '-') continue;
        if (value[i] == '.' && !hasDot) { hasDot = true; continue; }
        if (!std::isdigit(value[i]))
            return false;
    }
    return true;
}

void BitcoinExchange::processInput(const std::string& inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line); // skip header "date | value"

    while (std::getline(file, line))//getline from std::string
    {
        //find from std::string, returns the index of the first occurrence of the substring " | " 
        //in line, or std::string::npos if not found
        size_t separator = line.find(" | ");
        if (separator == std::string::npos)//npos = not found
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date  = line.substr(0, separator);//substr(start, length) - from std::string
        std::string valueStr = line.substr(separator + 3);
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;//skip to next line
        }
        if (!isValidValue(valueStr))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        float value = std::atof(valueStr.c_str());
        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string, float>::iterator it = DtRtMap.lower_bound(date);
        if (it == DtRtMap.end() || it->first != date)
        {
            if (it == DtRtMap.begin())
            {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }
            --it;//Move iterator one step backward to the closest lower date.
        }
        std::cout << date << " => " << value << " = "
                  << value * it->second << std::endl;
    }
}
// it->first → key (date in DtRtMap)
// it->second → value (rate corresponding to that date)
// Multiply input value by the rate and print the result.
//DtRtMap is a std::map (key = date, value = rate).
//lower_bound(date) finds the first key in the map that is ≥ date.
//Returns an iterator pointing to that element.
//it == DtRtMap.end() → no key ≥ date exists (we are past the last element)
//it->first != date → exact date wasn’t found, but it points to the next higher date
// If the first element in the map is already after the input date, then there’s no valid earlier date.
// Print error and skip this line.

//An iterator is like a pointer that can move through a container.