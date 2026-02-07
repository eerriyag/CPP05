#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat alice("Alice", 1);
    Bureaucrat bob("Bob", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("John");
    PresidentialPardonForm pardon("Marvin");

    try { alice.signForm(shrub); alice.executeForm(shrub); } catch (...) {}
    try { alice.signForm(robot); alice.executeForm(robot); } catch (...) {}
    try { alice.signForm(pardon); alice.executeForm(pardon); } catch (...) {}

    try { bob.signForm(shrub); bob.executeForm(shrub); } catch (...) {}
    return 0;
}
