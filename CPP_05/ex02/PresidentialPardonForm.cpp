#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
		: AForm(target, 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm" << target << "constructed" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm" << target << "destructed" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source)
		: AForm(source), target(source.target)
{
	std::cout << "PresidentialPardonForm" << target << "copy constructed" << std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &source)
{
	AForm::operator=(source);
	std::cout << "PresidentialPardonForm" << target << "assigned" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned()) 
	{
		throw FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) 
	{
		throw GradeTooLowException();
	}
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}