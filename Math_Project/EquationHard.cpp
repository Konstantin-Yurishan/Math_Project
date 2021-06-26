#include "EquationHard.h"

void EquationHard::training()
{

	std::cout << "I'm born!" << std::endl;

	srand(time(NULL));
	std::chrono::steady_clock sc;//?????? ?????? ????
	auto start = sc.now();//????? ??? ?????

	int answear, num;
	std::string sign = "";
	std::cout << "I'm born!" << std::endl;

	while (repeat) {

		num = rand() % 4;

		if (num == 0) { //+
			sign = " + ";
			x = rand() % difficult;
			y = rand() % difficult;
			result = x + y;
		}
		else if (num == 1) {//-
			sign = " - ";
			x = rand() % difficult;
			y = rand() % difficult;
			result = x - y;
		}
		else if (num == 2) {//*
			sign = " * ";
			x = rand() % difficult;
			y = rand() % difficult;
			result = x * y;
		}
		else {// /

			sign = " / ";

			while (true) {
				x = rand() % difficult;
				y = rand() % difficult;

				if (x < y || x % y != 0 || y == 0) { continue; }
				else { break; }
			}

			result = x / y;

		}

		std::cout << "I'm born!" << std::endl;

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

	std::cout << "I'm born!" << std::endl;

	auto end = sc.now();//?????????? ????????? ???????
	auto time_span = static_cast<std::chrono::duration<double>>(end - start);

	std::cout << "Your IQ is " << score << std::endl;
	std::cout << "Time is " << time_span.count() << std::endl;
}
