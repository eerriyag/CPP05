#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructeurs / destructeur
Intern::Intern() {}
Intern::Intern(const Intern& src) { *this = src; }
Intern::~Intern() {}
Intern& Intern::operator=(const Intern& src) { (void)src; return *this; }

// Méthodes privées pour créer les forms
AForm* Intern::createShrubbery(const std::string& target) const
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) const
{
    return new PresidentialPardonForm(target);
}

// makeForm : crée un form selon son nom
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (Intern::*formCreators[3])(const std::string&) const = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }

    std::cout << "❌ Error: form name does not exist" << std::endl;
    return NULL; // C++98 compatible
}

