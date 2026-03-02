#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point const a(0, 0);
	Point const b(2, 0);
	Point const c(1, 1);
	Point const point(1, 0.9);


	std::cout << "a(" << a.getX().toFloat() << "," << a.getY().toFloat() << ")\n";
	std::cout << "b(" << b.getX().toFloat() << "," << b.getY().toFloat() << ")\n";
	std::cout << "c(" << c.getX().toFloat() << "," << c.getY().toFloat() << ")\n";
	std::cout << "point(" << point.getX().toFloat() << "," << point.getY().toFloat() << ")\n";


	if (!bsp(a, b, c, point))
		std::cout << "The point is not in the triangle." << std::endl;
	else
		std::cout << "The point is in the triangle." << std::endl;
	return (0);
}