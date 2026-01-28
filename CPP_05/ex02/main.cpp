#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	try 
	{
		std::cout << "\n--- HIGH GRADE: all success ---\n";
		Bureaucrat boss("Boss", 1);

		ShrubberyCreationForm shrub("Garden");
		RobotomyRequestForm robot("Bob");
		PresidentialPardonForm pardon("Charlie");

		boss.signForm(shrub);
		boss.signForm(robot);
		boss.signForm(pardon);

		boss.executeForm(shrub);
		boss.executeForm(robot);
		boss.executeForm(pardon);

		std::cout << "\n--- ROBOTOMY RANDOMNESS ---\n";
		boss.executeForm(robot);
		boss.executeForm(robot);

		std::cout << "\n--- NOT SIGNED ---\n";
		ShrubberyCreationForm notSigned("Home");
		boss.executeForm(notSigned);

	} 
	catch (const std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n--- GRADE TOO LOW ---\n";
		Bureaucrat low("Low", 150);
		PresidentialPardonForm pardon("Zaphod");

		low.signForm(pardon);
		low.executeForm(pardon);

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
		try {
		std::cout << "\n--- CAN SIGN, CANNOT EXECUTE ---\n";
		Bureaucrat signerOnly("Signer", 70); // enough to sign Robotomy (72)
		RobotomyRequestForm robot("Target");

		signerOnly.signForm(robot);
		signerOnly.executeForm(robot); // needs 45 → should fail
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}


//Header (.hpp) → forward declare
//Source (.cpp) → include real headers