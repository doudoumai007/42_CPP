#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data d = {42, 3.1415926};

	//Serialize
	std::cout << "Origin address: "<< &d << std::endl; //origin address
	uintptr_t raw = Serializer::serialize(&d);
	std::cout << "Address in raw int: "<<raw << std::endl;

	//Deserialize
	Data* new_ptr = Serializer::deserialize(raw);
	std::cout << "Address after deserialize: " << new_ptr << std::endl; //Address after deserialize
	//Value
	std::cout << "int : "<< new_ptr->x << "\nfloat: " << new_ptr->y << std::endl;

	return (0);
}