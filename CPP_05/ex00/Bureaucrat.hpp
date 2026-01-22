#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    private:
        const std::string name;//have to use initializer cause of const
        int               grade;
        void  validateGrade(int grade);

    public:

        Bureaucrat(const std::string &name, int inputGrade);//pass by const ref to avoid copying 
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        const std::string& getName() const;//& is better to avoid copying string
        int			getGrade() const;
    
        void		incrementGrade();
        void		decrementGrade();

        class GradeTooHighException : public std::exception //nested class cause it is only used by Burocrat
        {
	        public:
		        virtual const char *what() const throw();//+98 style
        };
        class GradeTooLowException : public std::exception
        {
	        public:
	        	virtual const char *what() const throw();
        };
};



std::ostream &operator<<(std::ostream &output, const Bureaucrat &b);






//New Concepts:
//1. Error handling with exception class and objects (Not strings) 
//2. Exception class inherit from std::exception
//3. Use nested exception class if not needed by multiple classes
//3. throw- try/catch for error instead of return
//4. Initializer list -- explanation:.cpp
//5. Polymorphism- used in exception --

//what() is a function inherited from std::exception class library

// what() is virtual in std::exception → enables polymorphism.
//EXAMPLE:
// NOT polymorphism (no virtual):
// Base* b = new Derived();
// b->func();        // calls Base::func()
//
// Polymorphism (virtual):
// Base* b = new Derived();
// b->func();        // calls Derived::func()
