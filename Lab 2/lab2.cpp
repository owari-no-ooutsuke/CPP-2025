#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#define P_CORRECT 60
#define N 10

using std::string;
using std::vector;
using std::ifstream;

class Equation {
public:
	double a, b, c;
	bool isValid();
};

bool Equation::isValid() {
	if (a == 0 && b == 0 && c == 0) {
		return false;
	}
	else {
		return true;
	}
}

class Answer {
public:
	string studName;
	vector<vector<double>> solutions;
};

class Person {
protected:
	Equation ReadEq(ifstream& fin);
	vector<double> EqSolution(Equation& eq);
};

Equation Person::ReadEq(ifstream& fin) {
	double coeffs[3];
	for (int i = 0; i < 3; i++) {
		fin >> coeffs[i];
		if (fin.fail()) {
			for (int j = 0; j < 3; j++) {
				coeffs[j] = 0;
			}
			break;
		}
	}
	Equation eq = { coeffs[0], coeffs[1], coeffs[2] };
	return eq;
}

vector<double> Person::EqSolution(Equation& eq) {
	vector<double> sol;
	if (eq.a == 0) {
		return sol;
	}

	double d = eq.b * eq.b - 4 * eq.a * eq.c;
	if (d > 0) {
		sol.push_back((-eq.b - pow(d, 0.5)) / (2 * eq.a));
		sol.push_back((-eq.b + pow(d, 0.5)) / (2 * eq.a));
	}

	else if (d == 0) {
		sol.push_back(-eq.b / (2 * eq.a));
	}

	return sol;
}

class Student : public Person {
public:
	string name;
	virtual Answer Solve(string taskFilename) = 0;
	virtual ~Student() {};
};

class Good : public Student {
public:
	Good(string studName) { name = studName; };
	Answer Solve(string taskFilename);
};

Answer Good::Solve(string taskFilename) {
	Answer ans;
	ans.studName = name;

	ifstream fin(taskFilename);
	Equation eq = ReadEq(fin);
	while (eq.isValid()) {
		vector<double> sol = EqSolution(eq);
		ans.solutions.push_back(sol);
		eq = ReadEq(fin);
	}
	fin.close();
	return ans;
}

class Average : public Student {
public:
	Average(string studName) { name = studName; };
	Answer Solve(string taskFilename);
};

Answer Average::Solve(string taskFilename) {
	srand(time(NULL));
	Answer ans;
	ans.studName = name;

	ifstream fin(taskFilename);
	Equation eq = ReadEq(fin);
	while (eq.isValid()) {
		int randNum = rand() % 100 + 1;
		vector<double> sol;
		if (randNum <= P_CORRECT) {
			sol = EqSolution(eq);
		}
		else {
			sol.push_back(0);
		}
		ans.solutions.push_back(sol);
		eq = ReadEq(fin);
	}
	fin.close();
	return ans;
}

class Bad : public Student {
public:
	Bad(string studName) { name = studName; };
	Answer Solve(string taskFilename);
};

Answer Bad::Solve(string taskFilename) {
	Answer ans;
	ans.studName = name;

	ifstream fin(taskFilename);
	Equation eq = ReadEq(fin);
	while (eq.isValid()) {
		vector<double> sol = { 0 };
		ans.solutions.push_back(sol);
		eq = ReadEq(fin);
	}
	fin.close();
	return ans;
}