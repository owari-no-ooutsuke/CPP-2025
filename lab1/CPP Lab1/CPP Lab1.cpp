#define CRT_SECURE_NO_WARNINGS
#include "CPP Lab1.hpp"
#include <cmath>

//вычисление дискриминанта
double Discriminant(quadEq const& eq) {
	return eq.b * eq.b - 4 * eq.a * eq.c;
}

//нахождение корней
eqSolution Solution(quadEq const& eq) {
	double d = Discriminant(eq);
	eqSolution sol;

	if (d > 0) {
		sol.rootCount = 2;
		sol.roots = (double*)malloc(sizeof(double) * 2);
		sol.roots[0] = (-eq.b - pow(d, 0.5)) / (2 * eq.a);
		sol.roots[1] = (-eq.b + pow(d, 0.5)) / (2 * eq.a);
	}

	else if (d == 0) {
		sol.rootCount = 1;
		sol.roots = (double*)malloc(sizeof(double));
		sol.roots[0] = -eq.b / (2 * eq.a);
	}

	else {
		sol.rootCount = 0;
		sol.roots = nullptr;
	}

	return sol;
}