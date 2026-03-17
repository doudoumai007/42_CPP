#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data d = {42, 3.1415926};

	//Serialize
	uintptr_t raw = Serializer::serialize(&d);
	std::cout << raw << std::endl;

	//Deserialize
	Data* new_ptr = Serializer::deserialize(raw);
	std::cout << "int : "<< new_ptr->x << "\nfloat: " << new_ptr->y << std::endl;

	return (0);
}