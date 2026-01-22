
#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat(const std::string &name, int initialGrade) : name(name)
{
	validateGrade(initialGrade);
	grade = initialGrade; 
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &source)
{
	if (this != &source)
		this->grade = source.grade;
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}



const std::string &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::incrementGrade()
{
	checkGrade(grade - 1);
	grade -= 1;
	std::cout << "The grade incremented!" << std::endl;;
}

void Bureaucrat::decrementGrade()
{
	checkGrade(grade + 1);
	grade += 1;
	std::cout << "The grade decremented!" << std::endl;
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << ".\n";
	return out;
}





Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_setGrade(other.getGrade());
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}



std::string	Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	_setGrade(_grade - 1);
}

void	Bureaucrat::decrementGrade()
{
	_setGrade(_grade + 1);
}

const char	*Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Bureaucrat grade is too high (must be >= 1)");
}

const char	*Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Bureaucrat grade is too low (must be <= 150)");
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b)
{
	output << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (output);
}