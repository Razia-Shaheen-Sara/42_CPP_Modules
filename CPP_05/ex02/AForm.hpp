#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToSign;
	const int			gradeToExecute;
public:
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	~AForm();
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
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	virtual void	execute(Bureaucrat const &executor) const = 0;

};

std::ostream &operator <<(std::ostream &out, const AForm &source);

//WHY execute is virtual?
//it means same function call will have different behavior depending on the "CALLER" 
//this phenomenon is polymorphism

//WHY 0??
//It means this function has no implementation here and MUST be implemented by child classes.
//= 0 → pure virtual function
//Pure virtual ⇒ the class becomes abstract
//AForm is a blueprint only
//You cannot do AForm f;
//Any class inheriting AForm must implement execute()
//Otherwise that class is also abstract

