#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie();
		Zombie(const std::string& name);
		void	announce( void );
		void	setName(const std::string& name);
};

Zombie* zombieHorde(int N, std::string name);

#endif