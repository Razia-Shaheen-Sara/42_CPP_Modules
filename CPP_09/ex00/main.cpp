//What the program does
//It reads a CSV database (bitcoin prices by date) and an input file (dates + amounts), 
//then multiplies each amount by the bitcoin price on or before that date

//The core challenge — std::map + lower_bound
//std::map stores key-value pairs sorted by key. Since dates are strings in YYYY-MM-DD format,
//alphabetical order = chronological order. This is perfect.
//The trick for finding the closest lower date is upper_bound / lower_bound:

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange btc("data.csv");  // the provided DB file
        btc.processInput(argv[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}









/** # Normal cases
2011-01-03 => 3 = 0.9          ← uses 2011-01-03 rate from DB
2011-01-09 => 1 = 0.32         ← uses closest lower date
2012-01-11 => 1 = 7.1          ← normal
Error: too large a number.     ← 2147483648 > 1000
Error: not a positive number.  ← -1
Error: bad input => 2001-42-42 ← no " | " separator
2011-01-03 => 1.2 = 0.36       ← float value
2011-01-03 => 0 = 0            ← edge: zero is valid
2011-01-03 => 1000 = 300       ← edge: 1000 is valid
2011-01-03 => 0 = 0            ← 0.0 is valid

# Date edge cases
2008-12-31 => 10 = ...         ← depends if your DB has a date this early
Error: bad input => 2011-13-01 ← month 13 invalid
Error: bad input => 2011-00-10 ← month 0 invalid
Error: bad input => 2011-01-32 ← day 32 invalid
Error: bad input => abcd-ef-gh ← non-numeric date

# Value edge cases
Error: bad input => 2011-01-03 ← "abc" is not a number
Error: bad input => 2011-01-03 ← "1.2.3" two dots
Error: bad input => 2011-01-03 ← "--" not a number
Error: not a positive number.  ← -5
Error: too large a number.     ← 1001

# Separator edge cases — all should be bad input
Error: bad input => 2011-01-03|10        ← no spaces around |
Error: bad input => 2011-01-03  | 10     ← double space before |
Error: bad input => 2011-01-03 |10       ← no space after |
Error: bad input =>  2011-01-03 | 10     ← leading space in date
Error: bad input => 2011-01-03 | 10      ← trailing space after value (debatable*)
Error: bad input => 2011-01-03 | 10 | extra ← multiple separators

# Partial / empty lines
Error: bad input =>            ← line is just a space
Error: bad input => 2011-01-03 ← value missing after " | "
Error: bad input => | 10       ← date missing
Error: bad input => |          ← both missing

# Huge numbers
Error: too large a number.     ← 9999999999
Error: not a positive number.  ← -9999999999

# Tricky float values — behavior depends on your validation strictness
Error: bad input => 2011-01-03 ← ".5" starts with dot (no leading digit)
Error: bad input => 2011-01-03 ← "5." ends with dot (no trailing digit)
2011-01-03 => 5 = ...          ← "0005" = 5, likely valid (atof handles it)
2011-01-03 => 0 = 0            ← "000" = 0, valid
Error: not a positive number.  ← "-0" debatable, atof gives 0.0 so valid OR error*/