#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ================= Constructor ================= */
AForm::AForm(const std::string& name, int gradeSign, int gradeExec)
    : name(name), isSigned(false),
      gradeToSign(gradeSign), gradeToExecute(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

/* ================= Copy ================= */
AForm::AForm(const AForm& src)
    : name(src.name), isSigned(src.isSigned),
      gradeToSign(src.gradeToSign),
      gradeToExecute(src.gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& src)
{
    if (this != &src)
        isSigned = src.isSigned;
    return *this;
}

/* ================= Destructor ================= */
AForm::~AForm()
{
}

/* ================= Getters ================= */
const std::string& AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

/* ================= Sign ================= */
void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

/* ================= Exceptions ================= */
const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

/* ================= Operator << ================= */
std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << "Form " << f.getName()
        << ", signed: " << f.getIsSigned()
        << ", grade sign: " << f.getGradeToSign()
        << ", grade exec: " << f.getGradeToExecute();
    return out;
}
