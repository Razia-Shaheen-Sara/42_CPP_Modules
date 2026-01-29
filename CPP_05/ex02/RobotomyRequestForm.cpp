#include "RobotomyRequestForm.hpp"

//srand()→ from <cstdlib> function (sets the seed for random numbers)
//rand() → also <cstdlib>(returns a pseudo-random int)
//time() → from <ctime>(returns current time)

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
		: AForm(target, 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm " << target << " constructed" << std::endl;
	srand(time(0));//seed the random number generator with the current time
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << target << " destructed" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source)
		: AForm(source), target(source.target)
{
	srand(time(0));
	std::cout << "RobotomyRequestForm " << target << " copy constructed" << std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &source)
{
	AForm::operator=(source);
	std::cout << "RobotomyRequestForm " << target << " assigned" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor); //check base conditions
	std::cout << "\n*******some drilling noises*******" << std::endl;//from subject
	if ((std::rand() % 2) == 0)//gives either 0 or 1 randomly, 50% of the time
	{
		std::cout << getName() << " has been robotomized successfully!" << std::endl;
		return;
	}
	std::cout << getName() << " has been failed to robotomized!" << std::endl;
}

