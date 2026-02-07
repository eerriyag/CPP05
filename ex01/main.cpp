#include "Bureaucrat.hpp"
#include "Form.hpp"

int         main()
{
    std::cout << "TEST01" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 50);
        Form txtForm("TaxForm", 40, 30);

        std::cout << bob << std::endl;
        std::cout << txtForm << std::endl;

        bob.signForm(txtForm);
        std::cout << txtForm << std::endl;
    }
    
    catch(const  std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return (0);
}
