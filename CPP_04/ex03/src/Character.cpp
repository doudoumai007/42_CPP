#include "Character.hpp"

Character::Character(const std::string& name): name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] =  new AMateria();
}
Character::Character(const Character& other) : name(other.name)
{
}
Character& Character::operator=(const Character& other)
{
	if (this!= &other)

}

Character::~Character(){}

std::string const& getName() const;
void equip(AMateria* m);
void unequip(int idx);
void use(int idx, ICharacter& target);