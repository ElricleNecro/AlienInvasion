#include <iostream>

#include "profile/uniformsphere.hpp"

int main(int argc, char *argv[])
{
	profile::UniformSphere sphere(10);
	sphere.generate(100000L);

	(void)argc;
	(void)argv;
	return 0;
}
