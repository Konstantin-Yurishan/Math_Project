/*
Класс отвечает за игру. 
Получает как параметры сложность игры (количество операндов, знаки в уравнении, диапазон операндов), игра на время или нет, количество уравнений. 

*/

#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <time.h>
#include <random>
#include "Equation.h"

#pragma once
class Play_Game
{
private:

	int operands;	//количество операндов
	std::vector<std::string> signs;	//знаки для уравнений
	int time;	//время (если равно или меньше 0, то игра не на время)
	std::pair<int, int> range;	//рейндж для чисел в уравнении
	int equals;	//количество уравнений

public:

	Play_Game(int operands = 2, std::vector<std::string> signs = { "+", "-" }, int time = 0, std::pair<int, int> range = { 0, 10 }, int equals = 5) {
		

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

		range = std::make_pair(0, 10);

		int menu_point;
		while (true) {
			std::cout << "\t\tMenu!" << std::endl;
			std::cout << "1. Выбор сложности" << std::endl;
			std::cout << "2. Начать игру" << std::endl;
			std::cout << "0. Выход" << std::endl;

			std::cin >> menu_point;

			if (menu_point == 1) {
				difficult_menu();
			}
			else if (menu_point == 2) {
				game_menu();
			}
			else if (menu_point == 0) {
				exit(0);
			}
			else {
				std::cout << "Введите корректное значение!!!" << std::endl;
			}
		}
	}

	void difficult_menu() {

		int menu_point;
		while (true) {
			std::cout << "1. Количество операндов" << std::endl;
			std::cout << "2. Знаки" << std::endl;
			std::cout << "3. Диапазон значений" << std::endl;
			std::cout << "0. Exit" << std::endl;
			std::cin >> menu_point;

			if (menu_point == 1) {
				std::cin >> operands;
			}
			else if (menu_point == 2) {
				std::string temp;
				std::cout << "Вводите знаки по одному (0 - для завершения):";
					
				while (true) {
					std::cin >> temp;
					if (temp != "0" && signs.size() < 4) {
						signs.push_back(temp);
					}
					else {
						break;
					}
				}
			}
			else if (menu_point == 3) {
				int temp;
				std::cout << "Введите диапазон значений(xx xx):";
				std::cin >> range.first >> range.second;
			}
			else if (menu_point == 0) {
				break;
			}
			else {
				std::cout << "Введите корректное значение!!!" << std::endl;
			}
		}

	}

	void game_menu() {

		int menu_point;
		while (true) {
			std::cout << "1. Игра на время" << std::endl;
			std::cout << "2. Игра без времени" << std::endl;
			std::cout << "0. Выход" << std::endl;

			std::cin >> menu_point;

			if (menu_point == 1) {
				int temp;
				while (true) {
					std::cout << "Введите время в секундах: " << std::endl;
					std::cin >> temp;
					if (temp <= 10) {
						std::cout << "Введите время более 10 секунд!" << std::endl;
					}
					else {
						time = temp;
						break;
					}
				}

				game();

			}
			else if (menu_point == 2) {
				int temp;
				while (true) {
					std::cout << "Введите количество уравнений: " << std::endl;
					std::cin >> temp;
					if (temp < 3) {
						std::cout << "Нужно больше уравнений!" << std::endl;
					}
					else {
						equals = temp;
					}
				}

				game();

				
			}
			else if (menu_point == 0) {
				break;
			}
			else {
				std::cout << "Введите корректное значение!!!" << std::endl;
			}
		}

	}

	void game() {

		if (time > 0) {

			
			std::chrono::steady_clock sc;//объект класса часы
			auto start = sc.now();//берем тек время
			
			auto end = sc.now();
			while (static_cast<std::chrono::duration<double>>(end - start).count() < time) {
				end = sc.now();

				//std::cout << (static_cast<std::chrono::duration<double>>(end - start).count()) << std::endl;
				Equation equa(3, 0, 10);
				int temp;
				std::cout << "Enter the answer: ";
				std::cin >> temp;
				if (temp == equa.getResult()) {
					std::cout << "Correct!" << std::endl;
				} else {
					std::cout << "Wrong! Answer is " << equa.getResult() << std::endl;
				}
				//Equation equa(operands, range.first, range.second);


			}

		

		}
		else {

		}



	}


};

