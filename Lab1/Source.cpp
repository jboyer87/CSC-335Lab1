#include <iostream>
#include "P1dot1.h"
#include "C2dot4.h"
#include "P3dot2.h"
#include "P4dot1.h"

int main() {
	std::cout << "P1.1: " << std::endl;
	P1dot1::run();

	std::cout << std::endl;

	std::cout << "C2.4: " << std::endl;
	C2dot4::run();

	std::cout << std::endl << std::endl;

	std::cout << "P3.2: " << std::endl;
	P3dot2::run();

	std::cout << std::endl << std::endl;

	std::cout << "P4.1: " << std::endl;
	P4dot1::run();

	return 0;
}