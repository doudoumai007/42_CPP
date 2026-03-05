#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int main()
{
	/////////// Create Class //////////
	std::cout << BOLD << BLUE << "--- Create Class ---" << RESET << std::endl;

	std::cout << BOLD << YELLOW << "[Animal1]" << RESET << std::endl;
	const Animal* Animal1 = new Animal();

	std::cout << BOLD << YELLOW << "[Dog1]" << RESET << std::endl;
	const Animal* Dog1 = new Dog();

	std::cout << BOLD << YELLOW << "[Cat1]" << RESET << std::endl;
	const Animal* Cat1 = new Cat();

	std::cout << BOLD << YELLOW << "[Animal2]" << RESET << std::endl;
	const WrongAnimal* Animal2 = new WrongAnimal();

	std::cout << BOLD << YELLOW << "[Cat2]" << RESET << std::endl;
	const WrongAnimal* Cat2 = new WrongCat();


	/////////// Get type //////////
	std::cout << BOLD << BLUE << "\n--- Get type ---" << RESET << std::endl;

	std::cout << BOLD << YELLOW << "[Dog1]" << RESET << std::endl;
	std::cout << Dog1->getType() << " " << std::endl;

	std::cout << BOLD << YELLOW << "[Cat1]" << RESET << std::endl;
	std::cout << Cat1->getType() << " " << std::endl;

	std::cout << BOLD << YELLOW << "[Cat2]" << RESET << std::endl;
	std::cout << Cat2->getType() << " " << std::endl;


	/////////// Make Sound //////////
	std::cout << BOLD << BLUE << "\n--- Make Sound ---" << RESET << std::endl;
	std::cout << BOLD << YELLOW << "[Animal1]" << RESET << std::endl;
	Animal1->makeSound();
	std::cout << BOLD << YELLOW << "[Dog1]" << RESET << std::endl;
	Dog1->makeSound();
	std::cout << BOLD << YELLOW << "[Cat1]" << RESET << std::endl;
	Cat1->makeSound();
	std::cout << BOLD << YELLOW << "[Cat2]" << RESET << std::endl;
	Cat2->makeSound();

	/////////// Program Finished //////////
	std::cout << BOLD << BLUE << "\n--- Program Finished ---" << RESET << std::endl;
	std::cout << BOLD << YELLOW << "[Animal1]" << RESET << std::endl;
    delete(Animal1);

	std::cout << BOLD << YELLOW << "[Dog1]" << RESET << std::endl;
	delete(Dog1);

	std::cout << BOLD << YELLOW << "[Cat1]" << RESET << std::endl;
	delete(Cat1);

	std::cout << BOLD << YELLOW << "[Animal2]" << RESET << std::endl;
	delete(Animal2);

	std::cout << BOLD << YELLOW << "[Cat2]" << RESET << std::endl;
	delete(Cat2);
	
    return (0);
}