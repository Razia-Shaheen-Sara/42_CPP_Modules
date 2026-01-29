#pragma once
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>


class Intern
{
	private:

	AForm*		makeShrubbery(const std::string &target) const;
	AForm*		makeRobotomy(const std::string &target) const;
	AForm*		makePresidentialPardon(const std::string &target) const;

	public:

	Intern();
	~Intern();
	Intern(const Intern &source);
	Intern &operator = (const Intern &source);
	
	AForm *makeForm(const std::string &formName, const std::string &target) const;

	class UnknownFormException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

};

//FormMaker is a type that represents a pointer to a member function of Intern
//That function:take const std::string & as parameter; return AForm*; be marked const (won’t change Intern)
typedef AForm* (Intern::*FormMaker)(const std::string &target) const;



// Each “card” links a form name to the function that makes it
struct FormCard
{
    FormMaker 		createForm;
    std::string 	formTitle;
    FormCard(FormMaker func, const std::string &title) : createForm(func), formTitle(title) {}
};