#define CRT_SECURE_NO_WARNINGS
#include "CPP Lab1.hpp"

double Discriminant(quadEq const& eq) {
	return eq.b * eq.b - 4 * eq.a * eq.c;
}