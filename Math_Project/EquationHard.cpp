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


	for (int i = 0; i < 2; i++) {
		signs.push_back(setSign());//заполнение векетора с конца
	}

	for (int i = 0; i < 3; i++) {
		nums.push_back(rand() % (10 - 1) + 1);
	}

	std::vector<std::string> signs1(signs);
	std::vector<int> nums1(nums);

	std::string equattt = "";

	for (int i = 0; i < 2; i++) {

		equattt += std::to_string(nums1.at(i)) + " ";
		equattt += signs1.at(i) + " ";

		if (i == 1) {
			equattt += std::to_string(nums1.at(i + 1)) + " = ??";
		}
	}

	std::vector<std::string> OPZ;
	std::stack<std::string> OP;

	for (int i = 0; i < equattt.size(); i++) {

		std::string temp = std::to_string(equattt.at(i));

		if (equattt.at(i) >= '0' && equattt.at(i) <= '9') {
			OPZ.push_back(temp);
		}
		else {
			if ((temp == "*" || temp == "/") && (OP.top() == "*" || OP.top() == "/")) {
				OPZ.push_back(OP.top());
				OP.pop();
				OP.push(temp);
			}
			else {
				OP.push(temp);
			}
			
		}




	}


	return equattt;
}

std::string EquationHard::makePolish(const std::string& str)
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
	std::cout << srpn << std::endl; // результирующая строка в ОПЗ

	return srpn;
}
