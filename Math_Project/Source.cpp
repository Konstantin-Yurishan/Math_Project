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

/*

Класс создающий уравнения (equation) -> 
	Конструкторы:
		По умолчанию
		С заданием сложности (количество операндов, диапазон значений)

Класс предоставляющий интерфейс для взаимодействия с уравнениями

*/

#include <iostream>
#include "Equation.h"
#include "Play_Game.h"

int main()
{
	setlocale(0, "");
	/*
	int repeat, dif;

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



		// закрытие файлы
	/*
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

		*/

	//Equation equa(3, 0, 10);

	//Меню
	//1. Выбор сложности
	//1.1 Количество операндов
	//1.2 Знаки
	//1.3 Диапазон значений
	//1.3 
	//2. Начать игру
	//2.1 Игра на время
	// 	   2.1.1 Время
	//2.2 Игра без ограничения времени
	//     2.2.1 Количество уравнений

	Play_Game();



	return 0;
}