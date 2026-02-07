#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& src);
    ~Intern();
    Intern& operator=(const Intern& src);

    // Fonction pour créer un form
    AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
    // Méthodes privées pour créer chaque type de form
    AForm* createShrubbery(const std::string& target) const;
    AForm* createRobotomy(const std::string& target) const;
    AForm* createPresidential(const std::string& target) const;
};

#endif

