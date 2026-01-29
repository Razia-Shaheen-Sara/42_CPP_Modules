#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

//Tests: form creation with a sign grade and execute grade
//successful and unsuccessful signing
//invalid form creation (too high/low grades)

int main()
{
    std::cout << "--- TEST 1: FORM CREATION ---" << std::endl;
    try 
	{
        Form f1("TaxForm", 50, 20);
        std::cout << "Created: " << f1 << std::endl;
    } 
	catch (const std::exception &e) 
	{
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: SUCCESSFUL SIGN ---" << std::endl;
    try 
	{
        Bureaucrat alice("Alice", 10);
        Form permit("Permit", 20, 5);

        std::cout << alice << std::endl;
        std::cout << permit << std::endl;

        alice.signForm(permit); // should succeed
        std::cout << "After signing: " << permit << std::endl;
    } 
	catch (const std::exception &e) 
	{
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: UNSUCCESSFUL SIGN ---" << std::endl;
    try 
	{
        Bureaucrat bob("Bob", 100);
        Form secret("Secret", 50, 10);

        std::cout << bob << std::endl;
        std::cout << secret << std::endl;

        bob.signForm(secret); // should throw GradeTooLow
    } 
	catch (const std::exception &e) 
	{
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: INVALID FORM CREATION ---" << std::endl;
    try 
	{
        Form tooHigh("InvalidHigh", 0, 100); // should throw GradeTooHigh
    } 
	catch (const std::exception &e) 
	{
        std::cout << "Caught: " << e.what() << std::endl;
    }

    try 
	{
        Form tooLow("InvalidLow", 151, 100); // should throw GradeTooLow
    } 
	catch (const std::exception &e) 
	{
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 5: COPY & ASSIGN ---" << std::endl;
    Form original("Original", 30, 10);
    Form copyForm = original;           // copy constructor
    Form temp("Temp", 100, 100);
    temp = original;                    // assignment

    std::cout << "Copy constructed: " << copyForm << std::endl;
    std::cout << "Assigned: " << temp << std::endl;

    return 0;
}



//Main point/concept:
//Interaction message print between two classes (Bureaucrat ↔ Form)
//who owns what()