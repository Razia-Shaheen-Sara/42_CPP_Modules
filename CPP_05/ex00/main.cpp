#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- TEST 1: INCREAMENT ---" << std::endl;
	try 
    {
		Bureaucrat a("JIM", 2);
		std::cout << a;
        std::cout << "Increamenting " << a << std::endl;;
		a.incrementGrade();
		std::cout << a;
        std::cout << "Increamenting " << a << std::endl;;
		a.incrementGrade(); // should throw GradeTooHigh
	}
	catch (const Bureaucrat::GradeTooHighException &e) //“Catch the exception as a reference to the real object that was thrown.
    {
		std::cout << "Caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e) 
    {
		std::cout << "Caught: " << e.what() << std::endl;
	}
    std::cout << "--- TEST 2: DECREMENT ---" << std::endl;
    try 
    {
		Bureaucrat b("PAM", 150);
        std::cout << "decrementing " << b;
		b.decrementGrade(); // should throw GradeTooLow
        std::cout << "decrementing " << b;
	}
	catch (const std::exception &e) 
    {
		std::cout << "Caught: " << e.what() << std::endl;
	}
    std::cout << "--- TEST 3: COPY & ASSIGN ---" << std::endl;
	Bureaucrat c("Angela", 42);
	Bureaucrat d = c;          // copy constructor
	Bureaucrat e("Andy", 10);
	e = c;                     // assignment operator

	std::cout << "copy constructed: " << d << std::endl;
	std::cout << "assigned: " << e << std::endl;

	return 0;
}
