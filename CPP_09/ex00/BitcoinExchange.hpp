#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>


//Syntax ---- std::map<KeyType, ValueType> name;

class BitcoinExchange
{
    private:
        std::map<std::string, float> DtRtMap;

        void        loadHistory(const std::string& HistoryFile);
        bool        isValidDate(const std::string& date) const;
        bool        isValidValue(const std::string& value) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string& HistoryFile);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void processInput(const std::string& inputFile);
};

#endif

//std::map stores key-value pairs sorted by key like a dictionary.
//In this case, the key is the date (string) and the value is the bitcoin price (float).
//Syntax ---- std::map<KeyType, ValueType> name;


//Encapsulation principle: hide internal details and only expose what’s necessary via public
//So only public is whatever's needed by main. Rest is private. 
