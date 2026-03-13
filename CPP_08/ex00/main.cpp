#include <iostream>
#include "easyfind.hpp"

struct MyContainer
{
    int data[5] = {10, 20, 30, 40, 50};
    using iterator = int*;
    iterator begin() { return &data[0]; }
    iterator end() { return &data[5]; }
};

int main()
{
    MyContainer c;
    std::cout << "Container elements: ";
    for (int* it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // Test 1: element exists
    int search = 30;
    MyContainer::iterator found = easyfind(c, search);
    if (found != c.end())
        std::cout << "Found: " << *found << std::endl;
    else
        std::cout << search << " not found." << std::endl;

    // Test 2: element does NOT exist
    search = 51;
    found = easyfind(c, search);
    if (found != c.end())
        std::cout << "Found: " << *found << std::endl;
    else
        std::cout << search << " not found." << std::endl;

    return 0;
}