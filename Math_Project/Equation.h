#pragma once
#include <random>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

class Equation
{
private:

	int result;
	std::string equation;

	int top; // верхня граница для числа в уравнении
	int bottom; // нижняя граница для числе в уравнении
	int operands; // количество операндов
	int operators; // количество операторов

	std::string setSign();
	void complexEqua();
	std::string makePolish(std::string&);
	int getResult(std::string&);

public:

	Equation(int operands = 2, int bottom = 0, int top = 10) : operands{ operands }, bottom{ bottom }, top{ top }, operators{ operands - 1 },
		equation{ "" }, result{ 0 } {
		complexEqua();
		
	};

	int getResult() { return result; }
	std::string getequation() { return equation; }


};