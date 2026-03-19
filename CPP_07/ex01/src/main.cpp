#include "iter.hpp"
#include <iostream>

int main( void )
{
	int arr[] = {1, 2, 3};
	iter(arr, sizeof(arr)/sizeof(arr[0]), print);

	return (0);
}