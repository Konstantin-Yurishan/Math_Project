#pragma once
#include"Equation.h"

class EquationHard :protected Equation
{
private:
	int z;
public:

	EquationHard(int repeat = 0) : Equation(repeat), z{ 0 } { difficult = 100;  srand(time(NULL)); }


	void training();
	std::string setSign();
	std::string complexEqua();

	std::string makePolish(std::string&);
};

