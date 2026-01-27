#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

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
	    void		signForm(Form &source);//For this exercise

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

