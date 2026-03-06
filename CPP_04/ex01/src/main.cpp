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

	std::cout << BOLD << YELLOW << "[Animal1 Array]" << RESET << std::endl;
	Animal *array_Animal[10];

	std::cout << BOLD << YELLOW << "[Dog Group]" << RESET << std::endl;
	for(int i = 0; i < 5; i++)
		array_Animal[i] = new Dog();

	std::cout << BOLD << YELLOW << "[Cat Group]" << RESET << std::endl;
	for(int i = 5; i < 10; i++)
		array_Animal[i] = new Cat();


	/////////// Make Sound //////////
	std::cout << BOLD << BLUE << "\n--- Make Sound ---" << RESET << std::endl;
	for(int i = 0; i < 10; i++)
		array_Animal[i]->makeSound();

	
	///////// Test Deep copy ////////
	std::cout << BOLD << BLUE << "\n--- Test Deep copy ---" << RESET << std::endl;

	std::cout << BOLD << YELLOW << "[Creating dog1]" << RESET << std::endl;
	Dog dog1;

	std::cout << BOLD << YELLOW << "\n[Setting idea in dog1]" << RESET << std::endl;
	dog1.getBrain()->setIdea(0, "I want food");
	std::cout << "dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;

	std::cout << BOLD << YELLOW << "\n[Copying dog1 to dog2]" << RESET << std::endl;
	Dog dog2 = dog1;
	std::cout << "dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

	std::cout << BOLD << YELLOW << "\n[Modifying dog2 idea by \"I want sleep\"]" << RESET << std::endl;
	dog2.getBrain()->setIdea(0, "I want sleep");
	std::cout << "dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << "dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;


	/////////// Program Finished //////////
	std::cout << BOLD << BLUE << "\n--- Program Finished ---" << RESET << std::endl;
	for(int i = 0; i < 10; i++)
	{
		std::cout << BOLD << YELLOW << "\n[Animal " << i << "]" << RESET << std::endl;
		delete(array_Animal[i]);
	}
	std::cout << std::endl;
    return (0);
}