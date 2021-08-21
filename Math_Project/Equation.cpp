#include "Equation.h"

void Equation::complexEqua()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(bottom, top); // define the range

	for (int i = 0; i < operands; i++) {
		if (i == operands - 1) {
			equation += std::to_string(distr(gen));
			break;
		}
		equation += std::to_string(distr(gen)) + " ";
		equation += setSign() + " ";
	}

	std::string OPZ = makePolish(equation);

	result = getResult(OPZ);

	std::cout << "Result is: " << result << std::endl;
	std::cout << "Equation: " << equation << std::endl;
	std::cout << "OPZ is: " << OPZ << std::endl;

}

std::string Equation::setSign()
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, 3); // define the range

	std::string sign[4] = { "-", "+", "*", "/" };
	return sign[distr(gen)];
}

std::string Equation::makePolish(std::string& str)
{
	std::string srpn;
	std::string::size_type ind;

	while ((ind = str.find(' ')) != std::string::npos) {
		str.erase(ind, 1);
	}

	std::map<char, size_t> map; // карта весов символов
	map.insert(std::make_pair('*', 3));
	map.insert(std::make_pair('/', 3));
	map.insert(std::make_pair('+', 2));
	map.insert(std::make_pair('-', 2));
	map.insert(std::make_pair('(', 1));

	std::stack<char> stack;

	for (auto c : str) // формировка результирующей строки в ОПЗ
	{
		if (!isalnum(c) && ('.' != c))
		{
			srpn += ' ';
			if (')' == c)
			{
				while (stack.top() != '(')
				{
					srpn += stack.top();
					stack.pop();
					srpn += ' ';
				}
				stack.pop();
			}
			else if ('(' == c)
			{
				stack.push(c);
			}
			else if (stack.empty() || (map[stack.top()] < map[c]))
			{
				stack.push(c);
			}
			else
			{
				do
				{
					srpn += stack.top();
					srpn += ' ';
					stack.pop();
				} while (!(stack.empty() || (map[stack.top()] < map[c])));
				stack.push(c);
			}
		}
		else
		{
			srpn += c;
		}
	}

	while (!stack.empty())// остаток из стека добавляется в результ. строку
	{
		srpn += stack.top();
		srpn += ' ';
		stack.pop();
	}

	return srpn;
}


int Equation::getResult(std::string& OPZ) {

	std::stack<int> stk;

	int a = 0, b = 0;

	for (int i = 0; i < OPZ.length(); i++) {

		if (std::isdigit(OPZ.at(i))) {
			if (i < OPZ.length() - 1) if (std::isdigit(OPZ.at(i + 1))) {
				std::string s = OPZ.substr(i, 2);
				stk.push(std::stoi(s));
				continue;
			}
			std::string s = OPZ.substr(i, 1);
			stk.push(std::stoi(s));
		}
		else {
			if (OPZ[i] == '-') {
				b = stk.top();
				stk.pop();
				if (!stk.empty()) {
					a = stk.top();
					stk.pop();
				}
				stk.push(a - b);
			}
			else if (OPZ[i] == '+') {
				b = stk.top();
				stk.pop();
				if (!stk.empty()) {
					a = stk.top();
					stk.pop();
				}
				stk.push(a + b);
			}
			else if (OPZ[i] == '/') {
				b = stk.top();
				if (b == 0) {
					std::cout << "Error!" << std::endl;
					return 0;
				}
				stk.pop();
				if (!stk.empty()) {
					a = stk.top();
					stk.pop();
				}
				stk.push(a / b);
			}
			else if (OPZ[i] == '*') {
				b = stk.top();
				stk.pop();
				if (!stk.empty()) {
					a = stk.top();
					stk.pop();
				}
				stk.push(a * b);
			}
		}
	}

	return stk.top();

}
