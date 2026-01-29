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
		Bureaucrat boss("Mike", 1);//boss- object (variable) name; Mike- name stored/given in the object
		ShrubberyCreationForm shrub("Garden");//shrub is object name and Garden is target/stored in the object
		RobotomyRequestForm robot("Bob");
		PresidentialPardonForm pardon("Charlie");

		boss.signForm(shrub);
		boss.signForm(robot);
		boss.signForm(pardon);

		boss.executeForm(shrub);
		boss.executeForm(robot);
		boss.executeForm(pardon);

		std::cout << "\n--- NOT SIGNED ---\n";
		ShrubberyCreationForm unchecked("Home");
		boss.executeForm(unchecked);

	} 
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try 
	{
		std::cout << "\n--- GRADE TOO LOW ---\n";
		Bureaucrat intern("Ryan", 150);
		PresidentialPardonForm pardon("Zaphod");
		intern.signForm(pardon);
		intern.executeForm(pardon);

	} 
	catch (const std::exception& e) 
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try 
	{
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