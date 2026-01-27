#include "Form.hpp"
#include "Bureaucrat.hpp"


const char *Form::GradeTooHighException::what() const throw() 
{ 
    return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() 
{ 
    return "grade is too low to sign form";
}

//Use nested/custom exception class(custom for Form here) if not needed by multiple classes
void Form::validateGrade(int grade)
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
    std::cout << "Form " << name << " constructed" << std::endl;
}

Form::~Form()
{
    std::cout << "Form " << name << " destructed" << std::endl;
}

Form::Form(const Form &source)
	: name(source.name), isSigned(source.isSigned), gradeToSign(source.gradeToSign), gradeToExecute(source.gradeToExecute)
{
    std::cout << "copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &source)
{
	std::cout << "copy assignment operator called" << std::endl;
    if (this != &source)
		this->isSigned = source.isSigned;
	return (*this);
}

std::string	Form::getName() const { return name;}
bool		Form::getIsSigned() const { return isSigned;}
int			Form::getGradeToSign() const { return gradeToSign;}
int			Form::getGradeToExecute() const { return gradeToExecute;}


void	Form::beSigned(const Bureaucrat &source)
{
	if (getGradeToSign() < source.getGrade())
    {
		throw Form::GradeTooLowException();
	}
	isSigned = true;
}

std::ostream &operator << (std::ostream &out, const Form &f)
{
	out << "Form " << f.getName()
        << " is " << (f.getIsSigned() ? "signed" : "not signed")
        << ", sign grade " << f.getGradeToSign()
        << ", execute grade " << f.getGradeToExecute() << "\n";
    return out;
}