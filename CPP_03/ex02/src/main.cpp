#include "FragTrap.hpp"
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
    FragTrap a("A");

    /////////// Test /////////////
    std::cout << BOLD << BLUE << "\n--- Function test ---" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "[Basic attack test]" << RESET << std::endl;
    a.attack("Enemy");

    std::cout << BOLD << YELLOW << "\n[Repair test]" << RESET << std::endl;
    a.beRepaired(30);

    std::cout << BOLD << YELLOW << "\n[Damage test]" << RESET << std::endl;
    a.takeDamage(200);  // should be 0

    std::cout << BOLD << YELLOW << "\n[Attack when dead]" << RESET << std::endl;
    a.attack("Enemy"); // dead notif

    std::cout << BOLD << YELLOW << "\n[HighFives test]" << RESET << std::endl;
    a.highFivesGuys();

    /////// Copy constructor ///////
    std::cout << BOLD << BLUE << "\n--- Copy constructor ---" << RESET << std::endl;
    FragTrap b(a);
    std::cout << BOLD << YELLOW << "[Attack when dead]" << RESET << std::endl;
    b.attack("Enemy"); // dead notif

    /////// Copy ssignment operator /////
    std::cout << BOLD << BLUE << "\n--- Copy ssignment operator ---" << RESET << std::endl;
    FragTrap c("Temp");
    c = b;
    std::cout << BOLD << YELLOW << "[Attack when dead]" << RESET << std::endl;
    c.attack("Enemy");

    /////////// Slope finished ////////////
    std::cout << BOLD << BLUE << "\n--- End of program ---" << RESET << std::endl;

    return 0;
}