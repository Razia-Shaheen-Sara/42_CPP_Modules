#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    Intern someIntern;

    try
    {
        std::cout << "\n--- VALID FORMS ---\n";
        AForm* shrub = someIntern.makeForm("shrubbery creation", "Garden");
        AForm* robot = someIntern.makeForm("robotomy request", "Bender");
        AForm* pardon = someIntern.makeForm("presidential pardon", "Zaphod");

        if (shrub) delete shrub;
        if (robot) delete robot;
        if (pardon) delete pardon;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- UNKNOWN FORM ---\n";
        AForm* unknown = someIntern.makeForm("time travel request", "DocBrown");
        if (unknown) delete unknown; // will be nullptr
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "\n--- EMPTY TARGET EDGE CASE ---\n";
        AForm* pardon2 = someIntern.makeForm("presidential pardon", "");
        if (pardon2) delete pardon2;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
