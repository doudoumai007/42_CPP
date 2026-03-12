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
    a.attack("Enemy");

    std::cout << BOLD << BLUE << "\n--- Damage test ---" << RESET << std::endl;
    a.takeDamage(3);  // should be 0

    std::cout << BOLD << BLUE << "\n--- Repair test ---" << RESET << std::endl;
    a.beRepaired(5);

    std::cout << BOLD << BLUE << "\n--- Kill test ---" << RESET << std::endl;
    a.takeDamage(100);  // should be 0

    std::cout << BOLD << BLUE << "\n--- Try to attack when dead ---" << RESET << std::endl;
    a.attack("Enemy"); // should dead

    std::cout << BOLD << BLUE << "\n--- Try to repair when dead ---" << RESET << std::endl;
    a.beRepaired(5);

    /////////// Slope finished ////////////
    std::cout << BOLD << BLUE << "\n--- End of program ---" << RESET << std::endl;

    return 0;
}