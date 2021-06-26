#pragma once
#include"Equation.h"

class EquationNormal :protected Equation
{
private:
	int z;
public:

	EquationNormal(int repeat) : Equation(repeat) { difficult = 100; }

	void training();
	std::string setSumm();
	std::string setSub();
	std::string setDel();
	std::string setMult();
	std::string setSign();
	std::string complexEqua();
};

