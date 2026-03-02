#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int main()
{
	//////////////////////////////  Case 1 //////////////////////////////////////////
	std::cout << "\033[1;34m"
			  << "------------ CASE 1: both set weapon type at the begining -------------"
			  << "\033[0m" 
			  << std::endl;
	
	{
		Weapon club = Weapon("[crude spiked club]");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("[some other type of club]");
		bob.attack();
	}

	{
		Weapon club = Weapon("[crude spiked club]");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("[some other type of club]");
		jim.attack();
	}

	//////////////////////////////  Case 2 //////////////////////////////////////////
	std::cout << std::endl
			  << "\033[1;34m"
			  << "----- CASE 2: one set weapon first and the other set weapon later -----"
			  << "\033[0m" 
			  << std::endl;

	{
		Weapon club = Weapon("[crude spiked club]");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("[some other type of club]");
		bob.attack();
	}

	{
		Weapon club = Weapon("[crude spiked club]");
		HumanB jim("Jim");
		jim.attack();
		club.setType("[some other type of club]");
		jim.setWeapon(club);
		jim.attack();
	}
	return 0;
}