#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeSign, int gradeExec)
    : name(name), isSigned(false), gradeToSign(gradeSign), gradeToExecute(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& src)
    : name(src.name), isSigned(src.isSigned), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
}

Form& Form::operator=(const Form& src)
{
    if (this != &src)
        isSigned = src.isSigned;
    return *this;
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << "Form " << f.getName()
        << ", signed: " << f.getIsSigned()
        << ", grade to sign: " << f.getGradeToSign()
        << ", grade to execute: " << f.getGradeToExecute();
    return out;
}

