#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int main()
{
    // ================================
    // Create MateriaSource && learn Materia
    // ================================
    IMateriaSource* src = new MateriaSource();

    // Learn 2 Materias
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // ================================
    // Create Characters
    // ================================
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    // ================================
    // Equip Materia
    // ================================
    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp); // equip Ice

    tmp = src->createMateria("cure");
    me->equip(tmp); // equip Cure

    // ================================
    // Use Materia
    // ================================
    std::cout << BOLD << BLUE << "--- Use Materia ---\n" << RESET;
	
	std::cout << me->getName();
    me->use(0, *bob); // Ice -> Bob
	std::cout << me->getName();
    me->use(1, *bob); // Cure -> Bob

    // ================================
    // Test deep copy Character
    // ================================
    std::cout << BOLD << BLUE << "\n--- Test Character deep copy ---\n" << RESET;
    Character copyMe(*(Character*)me); // copy constructor

	std::cout << copyMe.getName();
    copyMe.use(0, *bob); // Ice
	std::cout << copyMe.getName();
    copyMe.use(1, *bob); // Cure

    // ================================
    // Test deep copy MateriaSource
    // ================================
    std::cout << BOLD << BLUE << "\n--- Test MateriaSource deep copy ---\n" << RESET;
    MateriaSource copySrc(*(MateriaSource*)src);

    AMateria* tmp2 = copySrc.createMateria("ice");
    AMateria* tmp3 = copySrc.createMateria("cure");

    Character alice("Alice");
    alice.equip(tmp2);
    alice.equip(tmp3);

	std::cout << alice.getName();
    alice.use(0, *bob); // Ice
	std::cout << alice.getName();
    alice.use(1, *bob); // Cure

    // ================================
    // Program Finished
    // ================================
    delete bob;
    delete me;
    delete src;
	// delete tmp4;
	// delete tmp5;

    // 注意：tmp2, tmp3 已经被装备到 alice，析构时 Character 会 delete
    return (0);
}