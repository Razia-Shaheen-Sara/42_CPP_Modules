#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void printElement(T const & x) { std::cout << x << std::endl; }

void toUpper(char & c) { c = toupper(c); }

int main() 
{
    // Test 1: Int array (Non-const)
    int tab[] = { 0, 1, 2, 3, 4 };
    iter(tab, 5, printElement<int>);

    // Test 2: String array (Const)
    const std::string strs[] = { "apple", "banana" };
    iter(strs, 2, printElement<std::string>);

    // Test 3: Modifying values (Non-const reference)
    char word[] = "hello";
    iter(word, 5, toUpper); // No <char> needed here because toUpper isn't a template
    iter(word, 5, printElement<char>);

    return 0;
}

//Why <int> or <char>? 
//Because printElement is a template function, and the compiler needs to know 
//which version to create before passing it as a parameter.
//so <> is being used for the template function here
//ALSO it proves that iter works for all types 