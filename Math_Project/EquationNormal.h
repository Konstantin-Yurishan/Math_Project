#pragma once
#include"Equation.h"

class EquationNormal :protected Equation
{
private:
	int z;
public:

	EquationNormal(int repeat) : Equation(repeat), z{ 0 } { difficult = 100;  srand(time(NULL)); }

	void training();
	std::string setSign();
	std::string complexEqua();
};

