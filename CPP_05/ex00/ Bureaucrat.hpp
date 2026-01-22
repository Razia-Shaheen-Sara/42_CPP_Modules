#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    private:
        const std::string name;
        int               grade;
        void  validateGrade(int grade);

    public:

        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string	getName() const;
        int			getGrade() const;
    
        void		incrementGrade();
        void		decrementGrade();
}

class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();//+98 style
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b);




//New Concepts:
//1. Exceptions - exeption classes inherit from std::exception
//2. throw- try/catch for error instead of return
//3. Polymorphism- used in exception --

// what() is virtual in std::exception → enables polymorphism.
//EXAMPLE:
// NOT polymorphism (no virtual):
// Base* b = new Derived();
// b->func();        // calls Base::func()
//
// Polymorphism (virtual):
// Base* b = new Derived();
// b->func();        // calls Derived::func()
