#include "DiamondTrap.hpp"
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
    DiamondTrap a("A");

    /////////// Test /////////////
    std::cout << BOLD << BLUE << "\n--- Function test ---" << RESET << std::endl;

    std::cout << BOLD << YELLOW << "[WhoAmI test]" << RESET << std::endl;
    a.whoAmI();

    std::cout << BOLD << YELLOW << "\n[Basic attack test]" << RESET << std::endl;
    a.attack("Enemy");

    std::cout << BOLD << YELLOW << "\n[Repair test]" << RESET << std::endl;
    a.beRepaired(30);

    std::cout << BOLD << YELLOW << "\n[Damage test]" << RESET << std::endl;
    a.takeDamage(200);  // should be 0

    std::cout << BOLD << YELLOW << "\n[Attack when dead]" << RESET << std::endl;
    a.attack("Enemy"); // dead notif

    std::cout << BOLD << YELLOW << "\n[GuardGate test]" << RESET << std::endl;
    a.guardGate();

    std::cout << BOLD << YELLOW << "\n[HighFives test]" << RESET << std::endl;
    a.highFivesGuys();

    /////// Copy constructor ///////
    std::cout << BOLD << BLUE << "\n--- Copy constructor ---" << RESET << std::endl;
    DiamondTrap b(a);
    std::cout << BOLD << YELLOW << "\n[WhoAmI test]" << RESET << std::endl;
    b.whoAmI();

    /////// Copy ssignment operator /////
    std::cout << BOLD << BLUE << "\n--- Copy ssignment operator ---" << RESET << std::endl;
    DiamondTrap c("Temp");
    c = b;
    std::cout << BOLD << YELLOW << "\n[WhoAmI test]" << RESET << std::endl;
    c.whoAmI();

    /////////// Slope finished ////////////
    std::cout << BOLD << BLUE << "\n--- End of program ---" << RESET << std::endl;

    return 0;
}