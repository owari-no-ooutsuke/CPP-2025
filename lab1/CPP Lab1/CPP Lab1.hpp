#pragma once

//��������� ax^2 + bx + c
typedef struct {
	double a;
	double b;
	double c;
} quadEq;

//����� ���������
typedef struct {
	int rootCount; //���������� ������
	double* roots; //������ ������
} eqSolution;


//���������� �������������
double Discriminant(quadEq const& eq);