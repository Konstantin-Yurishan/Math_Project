#include "EquationNormal.h"

void EquationNormal::training()
{

	srand(time(NULL));
	std::chrono::steady_clock sc;//объект класса часы
	auto start = sc.now();//берем тек время

	int answear, num;
	std::string equa = "";
	std::string Newequa;

	//запись в файл
	std::ofstream out;
	out.open("..\\log.txt");
	//out.open("..\\log.txt", std::ios::app); //добавить без перезаписи
	out << "Trello!" << std::endl;

	out.close();

	// закрытие файлы
	while (repeat) {

		num = rand() % 4;

		if (num == 0) { //+
			equa = setSumm();
		}
		else if (num == 1) {//-

			equa = setSub();
		}
		else if (num == 2) {//*
			equa = setMult();
		}
		else {// /

			equa = setDel();

		}

		while (true) {

			std::cout << equa << std::endl;
			std::cin >> answear;

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

}

std::string EquationNormal::setSumm()
{

	x = rand() % difficult;
	y = rand() % difficult;
	result = x + y;

	return std::to_string(x) + " + " + std::to_string(y) + "??";
}

std::string EquationNormal::setSub()
{
	x = rand() % difficult;
	y = rand() % difficult;
	result = x - y;
	return std::to_string(x) + " - " + std::to_string(y) + "??";
}

std::string EquationNormal::setDel()
{
	while (true) {
		x = rand() % difficult;
		y = rand() % difficult;

		if (x < y || x % y != 0 || y == 0) { continue; }
		else { break; }

	}
	result = x / y;
	return std::to_string(x) + " / " + std::to_string(y) + " = ??";

}

std::string EquationNormal::setMult()
{
	x = rand() % difficult;
	y = rand() % difficult;
	result = x * y;
	return std::to_string(x) + " * " + std::to_string(y) + "??";
}

std::string EquationNormal::setSign()
{
	return rand() % 2 == 1 ? "-" : "+";
}


std::string EquationNormal::complexEqua()
{

	z = rand() % difficult;

	std::string sig = setSign();
	std::string Newequa = setSumm() + sig + std::to_string(z);

	if (sig == "-") {
		result = result - z;
	}
	else {
		result = result + z;
	}
	
	//конструктор собирает уравнение
	//записываем в result результат
	//возвращаем уравнение в виде строки

	return std::string();
}
