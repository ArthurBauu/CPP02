#include "point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(3, 3);
	Point edge(0, 3);
	Point outside(10, 10);

	std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;   // devrait être 1
	std::cout << "On edge: " << bsp(a, b, c, edge) << std::endl;   // devrait être 0
	std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl; // devrait être 0

	return 0;
}