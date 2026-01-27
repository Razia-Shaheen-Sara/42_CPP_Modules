#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToSign;
	const int			gradeToExecute;
public:
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(const Form &source);
	Form &operator = (const Form &source);


	std::string	getName() const;
	bool		getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	void		beSigned(const Bureaucrat &source);
	void		validateGrade(int grade);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	
    class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

};

std::ostream &operator <<(std::ostream &out, const Form &source);

