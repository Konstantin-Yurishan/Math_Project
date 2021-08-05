#include "EquationHard.h"
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <map>
#include <cctype>
#include <stack>

void EquationHard::training()
{

	srand(time(NULL));
	std::chrono::steady_clock sc;//объект класса часы
	auto start = sc.now();//берем тек время

	int answear, num;
	std::string equa = "";
	std::string Newequa;

	//запись в файл
	std::ofstream out;
	//out.open("..\\log.txt");
	out.open("..\\log.txt", std::ios::app); //добавить без перезаписи

	out << "/********** normal session with " << repeat << " repeats **********/" << std::endl;

	// закрытие файлы
	while (repeat) {

		std::string equa = complexEqua();

		out << equa << std::endl;
		out << "result is " << result << std::endl;

		while (true) {

			std::cout << equa << std::endl;
			std::cin >> answear;

			out << "player answer is " << answear << std::endl;

			if (answear == result) {
				std::cout << "Great!" << std::endl;
				repeat--;
				break;
			}
			else {
				std::cout << "Wrong!" << std::endl;
				std::cout << "Right answer is " << result << std::endl;
				score--;
				break;
			}
		}
	}


	auto end = sc.now();//переменная окончания времени
	auto time_span = static_cast<std::chrono::duration<double>>(end - start);

	std::cout << "Your IQ is " << score << std::endl;
	std::cout << "Time is " << time_span.count() << std::endl;  //огграничить количество знаков после запятой до 1

	out << "player iq is " << score << std::endl;
	out << "session time is " << time_span.count() << std::endl << std::endl;

	out.close();
}


std::string EquationHard::setSign()
{
	int variant = rand() % 4;

	if (variant == 0) {
		return "+";
	}
	else if (variant == 1) {
		return "-";
	}
	else if (variant == 2) {
		return "/";
	}
	else {
		return "*";
	}
}


std::string EquationHard::complexEqua()
{

	std::vector<std::string> signs;
	std::vector<int> nums;

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator

	

	top = 10;
	bottom = -10;

	operands = 3;
	operators = 2;

	std::uniform_int_distribution<> distr(bottom, top); // define the range

	for (int i = 0; i < operators; i++) {
		signs.push_back(setSign());//заполнение вектора с конца
	}

	for (int i = 0; i < operands; i++) {
		nums.push_back(distr(gen));
	}


	std::vector<std::string> signs1(signs);
	std::vector<int> nums1(nums);

	std::string equattt = "";

	for (int i = 0; i < operators; i++) {

		equattt += std::to_string(nums1.at(i)) + " ";
		equattt += signs1.at(i) + " ";

		if (i == 1) {
			equattt += std::to_string(nums1.at(i + 1));
		}
	}

	equattt += "= ??";

	std::string OPZ = makePolish(equattt);

	result = getResult(OPZ);

	//std::cout << OPZ << std::endl;

	//std::cout << equattt << std::endl;

	return equattt;
}

std::string EquationHard::makePolish(std::string& str)
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

int EquationHard::getResult(std::string& OPZ) {

	std::stack<int> stk;

	int a, b;

	for (int i = 0; i < 9; i += 2) {

		if (std::isdigit(OPZ.at(i))) {
			std::string s = OPZ.substr(i, 1);
			stk.push(std::stoi(s));
		}
		else {
			if (OPZ[i] == '-') {
				b = stk.top();
				stk.pop();
				a = stk.top();
				stk.pop();
				stk.push(a - b);
			}
			else if (OPZ[i] == '+') {
				b = stk.top();
				stk.pop();
				a = stk.top();
				stk.pop();
				stk.push(a + b);
			}
			else if (OPZ[i] == '/') {
				b = stk.top();
				stk.pop();
				a = stk.top();
				stk.pop();
				stk.push(a / b);
			}
			else if (OPZ[i] == '*') {
				b = stk.top();
				stk.pop();
				a = stk.top();
				stk.pop();
				stk.push(a * b);
			}
		}
	}

	return stk.top();

}
