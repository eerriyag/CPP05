#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>   // pour ofstream
#include <string>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;

public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
    ~ShrubberyCreationForm();

    // ✅ C++98 : on n'utilise pas override
    void execute(Bureaucrat const & executor) const;

};

#endif
