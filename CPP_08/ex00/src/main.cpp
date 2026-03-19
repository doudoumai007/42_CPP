#include "easyfind.hpp"

#include <vector>
#include <list>
#include <iostream>

int main()
{
    //Vector
    std::vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);

    // T = std::vector<int>
    try
    {
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Found: " << *it << std::endl;
        std::vector<int>::iterator it2 = easyfind(v, 5);
        std::cout << "Found: " << *it2 << std::endl;
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    //List
    std::list<int> l;
    l.push_back(10);
    l.push_back(20);

    // T = std::list<int>
    try
    {
        std::list<int>::iterator it = easyfind(l, 10);
        std::cout << "Found: " << *it << std::endl;
        std::list<int>::iterator it2 = easyfind(l, 30);
        std::cout << "Found: " << *it2 << std::endl;
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}