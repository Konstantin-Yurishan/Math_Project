/*
* Пользователь при старте программы должен ввести своё имя, для занесения в таблицу лидеров.
* 
* TODO Вид окна с уравнением:
*			
* 
*					X + Y = ??
*				------------------
*				  time mm:ss::ms
* 
*				 Answer: ______
* 
* 
Пользователь вводит вариант ответа или выбирает из нескольких вариантов (варинты будут отличаться +- на рандомное значение).
Если правильный, то выдаётся следующее уравнение.
Если ответ не правильный, даётся ещё одна попытка или выводится правильный ответ и следующее уравнение.
Прогресс сохраняется и читается из файла.
Режим тренировки таблицы умножения.
*------------------------------
* Сетевое взаимодействие клиент\сервер, P2P
* Бот для телеграм
*/

#include <iostream>
#include "Equation.h"
#include "EquationEasy.h"
#include "EquationNormal.h"
#include "EquationHard.h"

int main()
{
	
	int repeat, dif;
	
	while (true) {
		std::cout << "Choose the difficult." << std::endl;
		std::cout << "1. Easy." << std::endl;
		std::cout << "2. Normal." << std::endl;
		std::cout << "3. Hard." << std::endl;
		std::cout << "0. Exit." << std::endl;
		std::cin >> dif;


		if (dif == 1) {
			std::cout << "Enter the repeat number:";
			std::cin >> repeat;
			EquationEasy a(repeat);
			a.training();
		}
		else if (dif == 2) {
			std::cout << "Enter the repeat number:";
			std::cin >> repeat;
			EquationNormal b(repeat);
			b.training();
		}
		else if (dif == 3) {
			std::cout << "Enter the repeat number:";
			std::cin >> repeat;
			EquationHard c(repeat);

			c.training();
		}
		else if (dif == 0) {
			exit(0);//завершает всю программу сразу
		}
		else {
			std::cout << "Wrong choice!" << std::endl;
		}
	}

	
	return 0;
}