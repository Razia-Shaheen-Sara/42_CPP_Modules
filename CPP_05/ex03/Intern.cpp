#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "default Intern constructed" << std::endl;
}
Intern::~Intern()
{
	std::cout << "Intern destructed" << std::endl;
}
Intern::Intern(const Intern &source)
{
	std::cout << "Intern copy constructed" << std::endl;
	*this = source;
}
Intern &Intern::operator = (const Intern &source)
{
	(void)source;
	std::cout << "Intern assigned" << std::endl;
	return *this;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
    // Table of available forms
    FormCard cards[] = 
    {
        FormCard(&Intern::makeShrubbery, "shrubbery creation"),
        FormCard(&Intern::makeRobotomy, "robotomy request"),
        FormCard(&Intern::makePresidentialPardon, "presidential pardon")
    };

    for (int i = 0; i < 3; ++i)
    {
        if (cards[i].formTitle == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*cards[i].createForm)(target); // CALL the member function correctly
        }
    }
    throw Intern::UnknownFormException();
    return nullptr;
}

AForm*	Intern::makeShrubbery(const std::string &target) const
{
	return new ShrubberyCreationForm(target);//need to "delete" in main because of new
}
AForm*	Intern::makeRobotomy(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}
AForm*	Intern::makePresidentialPardon(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

const char *Intern::UnknownFormException::what() const throw() { return "Unknown form"; }