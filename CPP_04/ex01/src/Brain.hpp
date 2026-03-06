#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		//Getter
		std::string getIdea(int index);

		//Setter
		void setIdea(int index, const std::string& idea);
};


#endif