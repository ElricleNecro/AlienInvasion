#include <iostream>

#include "galaxy/uniformsphere.hpp"

int main(int argc, char *argv[])
{
	galaxy::UniformSphere sphere(10);
	sphere.generate(100000);



	(void)argc;
	(void)argv;
	return 0;
}
