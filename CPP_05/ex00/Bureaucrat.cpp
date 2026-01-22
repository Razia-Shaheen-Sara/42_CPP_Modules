
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

void Bureaucrat::validateGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();//throw is a keyword giving error/exception
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}


// :name(name)  == :the member variable of the class(parameter passed to the constructor)
//: name(name) initializes the member variable name with the value of the constructor parameter name before the constructor body runs.
//have to use initializer cause name is const
//cannot assign inside {} because const members can’t be assigned after creation.
Bureaucrat::Bureaucrat(const std::string &name, int inputGrade):name(name), grade(inputGrade)
{
	validateGrade(grade);
	std::cout << "Bureaucrat " <<name<< " grade:" << grade << " constructed!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source): name(source.name), grade(source.grade)//cause name is const
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source)
{
	std::cout << "copy assignment operator called" << std::endl;
    if (this != &source)
		this->grade = source.grade;
	return *this;
}

void	Bureaucrat::incrementGrade()
{
	validateGrade(grade - 1);
    grade = grade - 1;
}

void	Bureaucrat::decrementGrade()
{
	validateGrade(grade + 1);
    grade = grade + 1;
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