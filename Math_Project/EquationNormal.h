#pragma once
#include"Equation.h"

class EquationNormal :protected Equation
{
private:

public:

	EquationNormal(int repeat) : Equation(repeat) { difficult = 100; }

	void training();

};
