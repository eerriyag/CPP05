#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp" // ✅ pour executor.getGrade()
#include <iostream>
#include <fstream>
#include <string>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& tgt)
    : AForm("ShrubberyCreationForm", 145, 137), target(tgt)
{
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src), target(src.target)
{
}

// Assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    if (this != &src)
        target = src.target;
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// ✅ Execute function
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    // Vérifier que le form est signé
    if (!getIsSigned())
        throw AForm::FormNotSignedException();

    // Vérifier le grade de l'executor
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    // Créer le fichier ASCII tree
    std::ofstream file((target + "_shrubbery").c_str()); // C++98 safe
    if (!file.is_open())
    {
        std::cerr << "Erreur: impossible de créer le fichier !" << std::endl;
        return;
    }

    // ASCII tree 🌳
    file << "       /\\\n";
    file << "      /  \\\n";
    file << "     / /\\ \\\n";
    file << "    / /  \\ \\\n";
    file << "   /_/____\\_\\\n";
    file << "      ||||\n";
    file << "      ||||\n";

    file.close();
}
