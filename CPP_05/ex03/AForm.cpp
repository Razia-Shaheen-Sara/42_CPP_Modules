#include "AForm.hpp"
#include "Bureaucrat.hpp"


const char *AForm::GradeTooHighException::what() const throw() 
{ 
    return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() 
{ 
    return "grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() 
{ 
	return "Form is not signed";
}

//Use nested/custom exception class(custom for A
//Form here) if not needed by multiple classes
void AForm::validateGrade(int grade)
{
	if (grade < 1)
		throw AForm::GradeTooHighException();
	if (grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
    std::cout << "AForm " << name << " constructed" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm " << name << " destructed" << std::endl;
}

AForm::AForm(const AForm &source)
	: name(source.name), isSigned(source.isSigned), gradeToSign(source.gradeToSign), gradeToExecute(source.gradeToExecute)
{
    std::cout << "copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &source)
{
	std::cout << "copy assignment operator called" << std::endl;
    if (this != &source)
		this->isSigned = source.isSigned;
	return (*this);
}

std::string	AForm::getName() const { return name;}
bool		AForm::getIsSigned() const { return isSigned;}
int			AForm::getGradeToSign() const { return gradeToSign;}
int			AForm::getGradeToExecute() const { return gradeToExecute;}


void	AForm::beSigned(const Bureaucrat &source)
{
	if (getGradeToSign() < source.getGrade())
    {
		throw AForm::GradeTooLowException();
	}
	isSigned = true;
}

std::ostream &operator << (std::ostream &out, const AForm &f)
{
	out << "AForm " << f.getName()
        << " is " << (f.getIsSigned() ? "signed" : "not signed")
        << ", sign grade " << f.getGradeToSign()
        << ", execute grade " << f.getGradeToExecute() << "\n";
    return out;
}


//base behavior centralized here
void AForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
}