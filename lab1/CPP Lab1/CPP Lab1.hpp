#pragma once

//уравнение ax^2 + bx + c
typedef struct {
	double a;
	double b;
	double c;
} quadEq;

//корни уравнения
typedef struct {
	int rootCount; //количество корней
	double* roots; //массив корней
} eqSolution;


//вычисление дискриминанта
double Discriminant(quadEq const& eq);