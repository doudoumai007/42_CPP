#include <iostream>
#include <cstdlib>

#include "Array.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // Test deep copy with scope
    // if it's not deep copy, there will be double free when calling destructor
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    // -2 out of range
	std::cout << BOLD << BLUE << "--- Try -2 (out of range) ---\n" << RESET;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Max_value out of range
	std::cout << BOLD << BLUE << "--- Try MAX_VAL (out of range) ---\n" << RESET;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // Test subscript operator []
	std::cout << BOLD << BLUE << "--- Test subscript operator [] ---\n" << RESET;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << numbers[MAX_VAL -1] << std::endl;
    delete [] mirror;
    return 0;
}