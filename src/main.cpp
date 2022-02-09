#include <iostream>

#include "constants.hpp"

int main() {
	std::cout << "Hello, World! v"
			  << PROJECT_3D2_VERSION_MAJOR << "."
			  << PROJECT_3D2_VERSION_MINOR << "."
			  << PROJECT_3D2_VERSION_PATCH << "."
			  << PROJECT_3D2_VERSION_TWEAK
			  << std::endl;
	return 0;
}
