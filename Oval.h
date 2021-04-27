#pragma once

#include "Point.h"
#include <vector>

class Oval {
private:
	double xc; //координаты центра облака
	double yc;
	int amount; //количество точек
	double dspx;
	double dspy;
	std::vector <Point> vecp; // множество точек, образующих облако
public:
	Oval(); // дефолтный конструктор
	Oval(int aparam, double xparam, double yparam, double dxparam, double dyparam); //  конструктор с параметрами
	~Oval(); // дестркуктор 
	void operator = (const Oval& poval);
	void AddtoPointlist(std::vector<Point>& pvec);
	void Show(); // вывод облака в консоль
	

	// ..........................операции преобразования облака точек

	void Rotatecenter(double phix);// вращение вокруг центра облака точек
	void Rotatedecartcenter(double phix); // вращение вокруг начал системы координат
	void MoveX(double dx); // сдвиг по OX
	void MoveY(double dy); // сдвиг по OY
	void PrittoFile();// запись облака точек в файл(перезапись файла, добавленный овал будет первым в данном облаке)
	void AddToFile(); // добавление овала в конец
};
