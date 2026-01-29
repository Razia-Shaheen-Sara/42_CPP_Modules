#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;//forward declaration to avoid circular dependency

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToSign;
	const int			gradeToExecute;
public:
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	virtual ~AForm(); //virtual destructor for base class because otherwise derived class destructor won’t be called
	AForm(const AForm &source);
	AForm &operator = (const AForm &source);


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
	class FormNotSignedException : public std::exception //new exception for execute
	{
	public:
		virtual const char *what() const throw();
	};

	virtual void	execute(Bureaucrat const &executor) const = 0;

};

std::ostream &operator <<(std::ostream &out, const AForm &source);



