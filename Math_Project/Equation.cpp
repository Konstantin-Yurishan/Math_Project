#include "Equation.h"

void Equation::training()
{

	srand(time(NULL));

	std::chrono::steady_clock sc;//объект класса часы
	auto start = sc.now();//берем тек время


	int answear, num, range;
	std::string sign = "";

	if (difficult == 0) {
		range = 10;
	}
	else if (difficult == 1) {
		range = 100;
	}
	else if (difficult == 2) {
		range = 1000;
	}
	else {
		range = 10;
	}

	while (repeat) {

		num = rand() % 4;

		if (num == 0) { //+
			sign = " + ";
			x = rand() % (range - (-range)) + (-range);
			y = rand() % (range - (-range)) + (-range);
			result = x + y;
		}
		else if (num == 1) {//-
			sign = " - ";
			x = rand() % (range - (-range)) + (-range);
			y = rand() % (range - (-range)) + (-range);
			result = x - y;
		}
		else if (num == 2) {//*
			sign = " * ";
			x = rand() % (range - (-range)) + (-range);
			y = rand() % (range - (-range)) + (-range);
			result = x * y;
		}
		else {// /

			sign = " / ";

			while (true) {
				x = rand() % (range - (-range)) + (-range);
				y = rand() % (range - (-range)) + (-range);

				if (x < y || x % y != 0 || y == 0) { continue; }
				else { break; }
			}

			result = x / y;

		}

		while (true) {

			std::cout << x << sign << y << " = ??" << std::endl;
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
	std::cout << "Time is " << time_span.count() << std::endl;
}
