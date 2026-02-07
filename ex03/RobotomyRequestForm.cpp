// #include "RobotomyRequestForm.hpp"
// #include <iostream>
// #include <cstdlib> // rand
// #include <ctime>   // time

// RobotomyRequestForm::RobotomyRequestForm(const std::string& t)
//     : AForm("RobotomyRequestForm", 72, 45), target(t)
// {
//     std::srand(std::time(nullptr)); // init random
// }

// void RobotomyRequestForm::execute(Bureaucrat const & executor) const
// {
//     if (!getIsSigned())
//         throw AForm::FormNotSignedException();
//     if (executor.getGrade() > getGradeToExecute())
//         throw AForm::GradeTooLowException();

//     std::cout << "Drilling noises... 🔊" << std::endl;
//     if (std::rand() % 2)
//         std::cout << target << " has been robotomized successfully 🤖" << std::endl;
//     else
//         std::cout << "Robotomy failed ❌" << std::endl;
// }


#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib> // srand, rand
#include <ctime>   // time

// Constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& t)
    : AForm("RobotomyRequestForm", 72, 45), target(t)
{
    std::srand(std::time(0)); // C++98 compatible, init random
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), target(src.target)
{
}

// Assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    if (this != &src)
        target = src.target;
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// Execute function
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}
