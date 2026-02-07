#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& n, int g) : name(n)
{
	if (g < 1)
		throw GradeTooHighException();
	if (g > 150)
		throw GradeTooLowException();
	grade = g;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	: name(src.name), grade(src.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		grade = src.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}



