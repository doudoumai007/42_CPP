#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap a("Arthur");
    ClapTrap b("Lancelot");

    std::cout << "\n--- Basic attack test ---" << std::endl;
    a.attack("Lancelot");
    b.takeDamage(3);

    std::cout << "\n--- Repair test ---" << std::endl;
    b.beRepaired(5);

    std::cout << "\n--- Kill test ---" << std::endl;
    b.takeDamage(100);  // 应该直接变 0

    std::cout << "\n--- Try to attack when dead ---" << std::endl;
    b.attack("Arthur"); // 应该提示 dead

    std::cout << "\n--- Energy drain test ---" << std::endl;
    for (int i = 0; i < 12; i++)
        a.attack("Training Dummy"); // 超过 energy 次数

    std::cout << "\n--- Try repair without energy ---" << std::endl;
    a.beRepaired(5);

    std::cout << "\n--- End of program ---" << std::endl;

    return 0;
}