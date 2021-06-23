#pragma once
#include"Equation.h"

class EquationEasy :protected Equation
{
private:

public:

	EquationEasy(int repeat) : Equation(repeat) { difficult = 10; }
	
	void training();

};

