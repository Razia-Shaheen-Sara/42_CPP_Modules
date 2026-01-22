
#include "Bureaucrat.hpp"

////what() is a function inherited from std::exception class library
//const after what() means- this function does NOT modify the exception object
//throw in the end means - this function will not throw another exception

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

void Bureaucrat::vlidateGrade(int grade)
{
	if (grade < 1)
    {
		throw Bureaucrat::GradeTooHighException();//throw is a keyword giving error/exception
	}
	if (grade > 150)
    {
		throw Bureaucrat::GradeTooLowException();
	}

}

Bureaucrat::Bureaucrat(const std::string &name, int initialGrade)
{
	validateGrade(initialGrade);
	grade = initialGrade; 
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = source;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source)
{
	std::cout << "copy assignment operator called" << std::endl;
    if (this != &source)
		this->grade = source.grade;
	return *this;
}

// void Bureaucrat::incrementGrade()
// {
// 	validateGrade(grade - 1);
// 	grade -= 1;
// 	std::cout << "The grade incremented!" << std::endl;;
// }

// void Bureaucrat::decrementGrade()
// {
// 	checkGrade(grade + 1);
// 	grade += 1;
// 	std::cout << "The grade decremented!" << std::endl;
// }

void	Bureaucrat::incrementGrade()
{
	validateGrade(_grade - 1);
}

void	Bureaucrat::decrementGrade()
{
	validateGrade(_grade + 1);
}

const std::string &Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b)
{
	output << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (output);
}