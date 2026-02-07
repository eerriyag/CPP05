#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp" // important pour executor.getGrade()
#include <string>

class PresidentialPardonForm : public AForm
{
private:
    std::string target;

public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
    ~PresidentialPardonForm();

    // ❌ retirer override pour C++98
    void execute(Bureaucrat const & executor) const;
};

#endif
