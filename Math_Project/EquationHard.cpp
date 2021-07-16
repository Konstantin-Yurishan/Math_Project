#include "EquationHard.h"

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


/*
	for (int i = 0; i < 2; i++) {

		if (signs.at(i) == "/") {
			
			if (signs.at(i) == "/") {//получение значение sings
				result = nums.at(0) / nums.at(1);
				signs.erase(signs.begin() + i, signs.begin() + i + 1);
				nums.erase(nums.begin(), nums.begin() + 2);//cnbhft стираем два элемента
				nums.insert(nums.begin(), result);//помещаем полученный результат в вектор
			}
		else if(signs.at(i) == "*"){ {//получение значение sings
				result = nums.at(0) * nums.at(1);
				signs.erase(signs.begin() + i, signs.begin() + i + 1);
				nums.erase(nums.begin(), nums.begin() + 2);//cnbhft стираем два элемента
				nums.insert(nums.begin(), result);//помещаем полученный результат в вектор
			}
		}
	
	
		if (signs.at(i) == "-") {//получение значение sings
			result = nums.at(0) - nums.at(1);
			nums.erase(nums.begin(), nums.begin() + 2);//cnbhft стираем два элемента
			nums.insert(nums.begin(), result);//помещаем полученный результат в вектор
		}
		else {
			result = nums.at(0) + nums.at(1);
			nums.erase(nums.begin(), nums.begin() + 2);//cnbhft стираем два элемента
			nums.insert(nums.begin(), result);//помещаем полученный результат в вектор
		}
	}
*/
	std::string equattt = "";

	for (int i = 0; i < 2; i++) {

		equattt += std::to_string(nums1.at(i)) + " ";
		equattt += signs1.at(i) + " ";

		if (i == 1) {
			equattt += std::to_string(nums1.at(i + 1)) + " = ??";
		}
	}


	return equattt;
}
