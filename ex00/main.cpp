//TEST1: CReation simple (grade valid)

#include "Bureaucrat.hpp"

int         main()
{
    try
    {
        Bureaucrat b1("Alice", 42);

        std::cout << b1 << std::endl;
        // std::cout << b1.getName() << std::endl;
        // std::cout << b1.getGrade() << std::endl;

    }
    // std::cout << "Ligne 15" << std::endl;
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl; 
    }

    return (0);
}