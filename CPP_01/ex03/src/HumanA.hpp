#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
	private:
		std::string		name;
		const Weapon	&weapon;
		
	public:
		HumanA(const std::string &name, const Weapon &weapon);
		void    attack();
};

#endif