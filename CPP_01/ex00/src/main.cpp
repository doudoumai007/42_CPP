#include "Zombie.hpp"
#include <string>

int main()
{
    Zombie *z = newZombie("HeapZombie");
    z->announce();
    delete z;

    randomChump("StackZombie");
    return (0);
}