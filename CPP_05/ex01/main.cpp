#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "--- TEST 1: FORM CREATION ---" << std::endl;
    try
    {
        Form f1("TaxForm", 50, 20);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception &e)//catch by reference
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "--- TEST 2: SIGN FORM (SUCCESS) ---" << std::endl;
    try
    {
        Bureaucrat b("Alice", 10);
        Form f("Permit", 20, 5);

        std::cout << f;
        b.signForm(f);
        std::cout << f;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "--- TEST 3: SIGN FORM (FAIL) ---" << std::endl;
    try
    {
        Bureaucrat b("Bob", 100);
        Form f("Secret", 50, 10);

        b.signForm(f); // should throw
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "--- TEST 4: COPY & ASSIGN ---" << std::endl;
    Form f1("Original", 30, 10);
    Form f2 = f1;          // copy constructor
    Form f3("Temp", 100, 100);
    f3 = f1;               // assignment

    std::cout << f2;
    std::cout << f3;

    return 0;
}
