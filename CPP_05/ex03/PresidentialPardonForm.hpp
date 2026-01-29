#pragma once
#include "AForm.hpp"



class PresidentialPardonForm : public AForm
{
private:
	const std::string target;
public:
	PresidentialPardonForm(const std::string &target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &source);
	PresidentialPardonForm &operator = (const PresidentialPardonForm &source);

	void	execute(const Bureaucrat &executor) const override;
};
