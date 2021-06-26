#pragma once
#include"Equation.h"

class EquationHard :protected Equation
{
private:

public:

	EquationHard(int repeat) : Equation(repeat) { difficult = 1000; }

	void training();

};
