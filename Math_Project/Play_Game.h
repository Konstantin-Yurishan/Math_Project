/*
����� �������� �� ����. 
�������� ��� ��������� ��������� ���� (���������� ���������, ����� � ���������, �������� ���������), ���� �� ����� ��� ���, ���������� ���������. 

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

	int operands;	//���������� ���������
	std::vector<std::string> signs;	//����� ��� ���������
	int time;	//����� (���� ����� ��� ������ 0, �� ���� �� �� �����)
	std::pair<int, int> range;	//������ ��� ����� � ���������
	int equals;	//���������� ���������

public:

	Play_Game(int operands = 2, std::vector<std::string> signs = { "+", "-" }, int time = 0, std::pair<int, int> range = { 0, 10 }, int equals = 5) {
		

		//����
		//1. ����� ���������
		//1.1 ���������� ���������
		//1.2 �����
		//1.3 �������� ��������
		//1.3 
		//2. ������ ����
		//2.1 ���� �� �����
		// 	   2.1.1 �����
		//2.2 ���� ��� ����������� �������
		//     2.2.1 ���������� ���������

		range = std::make_pair(0, 10);

		int menu_point;
		while (true) {
			std::cout << "\t\tMenu!" << std::endl;
			std::cout << "1. ����� ���������" << std::endl;
			std::cout << "2. ������ ����" << std::endl;
			std::cout << "0. �����" << std::endl;

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
				std::cout << "������� ���������� ��������!!!" << std::endl;
			}
		}
	}

	void difficult_menu() {

		int menu_point;
		while (true) {
			std::cout << "1. ���������� ���������" << std::endl;
			std::cout << "2. �����" << std::endl;
			std::cout << "3. �������� ��������" << std::endl;
			std::cout << "0. Exit" << std::endl;
			std::cin >> menu_point;

			if (menu_point == 1) {
				std::cin >> operands;
			}
			else if (menu_point == 2) {
				std::string temp;
				std::cout << "������� ����� �� ������ (0 - ��� ����������):";
					
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
				std::cout << "������� �������� ��������(xx xx):";
				std::cin >> range.first >> range.second;
			}
			else if (menu_point == 0) {
				break;
			}
			else {
				std::cout << "������� ���������� ��������!!!" << std::endl;
			}
		}

	}

	void game_menu() {

		int menu_point;
		while (true) {
			std::cout << "1. ���� �� �����" << std::endl;
			std::cout << "2. ���� ��� �������" << std::endl;
			std::cout << "0. �����" << std::endl;

			std::cin >> menu_point;

			if (menu_point == 1) {
				int temp;
				while (true) {
					std::cout << "������� ����� � ��������: " << std::endl;
					std::cin >> temp;
					if (temp <= 10) {
						std::cout << "������� ����� ����� 10 ������!" << std::endl;
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
					std::cout << "������� ���������� ���������: " << std::endl;
					std::cin >> temp;
					if (temp < 3) {
						std::cout << "����� ������ ���������!" << std::endl;
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
				std::cout << "������� ���������� ��������!!!" << std::endl;
			}
		}

	}

	void game() {

		if (time > 0) {

			
			std::chrono::steady_clock sc;//������ ������ ����
			auto start = sc.now();//����� ��� �����
			
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

