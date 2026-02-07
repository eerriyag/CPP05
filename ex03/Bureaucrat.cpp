#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* ================== Constructor ================== */
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

/* ================== Copy constructor ================== */
Bureaucrat::Bureaucrat(const Bureaucrat& src)
    : name(src.name), grade(src.grade)
{
}

/* ================== Assignment operator ================== */
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if (this != &src)
        grade = src.grade;
    return *this;
}

/* ================== Destructor ================== */
Bureaucrat::~Bureaucrat()
{
}

/* ================== Getters ================== */
const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

/* ================== Grade management ================== */
void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

/* ================== Sign form ================== */
void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << name << " couldn’t sign "
                  << f.getName() << " because "
                  << e.what() << std::endl;
    }
}

/* ================== Execute form (NEW in ex02) ================== */
void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << name << " couldn’t execute "
                  << form.getName() << " because "
                  << e.what() << std::endl;
    }
}

/* ================== Exceptions ================== */
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade is too low";
}

/* ================== Operator << ================== */
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}
