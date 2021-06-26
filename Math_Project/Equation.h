#pragma once
#include <random>
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>

class Equation  
{
protected:

	int x;
	int y;
	int result;
	int repeat;
	int score;
	int difficult;
	
public:

	Equation(int repeat) : repeat{ repeat }, x{ 0 }, y{ 0 }, result{ 0 }, score{ repeat }, difficult{ 0 } {};
	Equation() = default;

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setResult(int result) { this->result = result; }
	void setRepeat(int repeat) { this->repeat = repeat; }

	int getX() { return x; }
	int getY() { return y; }
	int getResult() { return result; }
	int getRepeat() { return repeat; }

	void training();  



};

