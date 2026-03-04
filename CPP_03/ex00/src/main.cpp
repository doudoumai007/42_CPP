#include "ClapTrap.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int main()
{
    ///////// Create Class //////////
    std::cout << BOLD << BLUE << "--- Class created ---" << RESET << std::endl;
    ClapTrap a("A");
    ClapTrap b("B");

    /////////// Test /////////////
    std::cout << BOLD << BLUE << "\n--- Basic attack test ---" << RESET << std::endl;
    a.attack("B");
    b.takeDamage(3);

    std::cout << BOLD << BLUE << "\n--- Repair test ---" << RESET << std::endl;
    b.beRepaired(5);

    std::cout << BOLD << BLUE << "\n--- Kill test ---" << RESET << std::endl;
    b.takeDamage(100);  // 应该直接变 0

    std::cout << BOLD << BLUE << "\n--- Try to attack when dead ---" << RESET << std::endl;
    b.attack("A"); // 应该提示 dead

    std::cout << BOLD << BLUE << "\n--- Energy drain test ---" << RESET << std::endl;
    for (int i = 0; i < 12; i++)
    {
        a.attack("B");
        std::cout << std::endl;
    }

    std::cout << BOLD << BLUE << "\n--- Try repair without energy ---" << RESET << std::endl;
    a.beRepaired(5);

    /////////// Slope finished ////////////
    std::cout << BOLD << BLUE << "\n--- End of program ---" << RESET << std::endl;

    return 0;
}