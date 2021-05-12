#pragma once

class Point {
private:
	double x; // кординаты по (x,y)
	double y; 
	int fclast; // принадлежность к кластеру
public:
	Point(); // конструктор без параметров
	Point(double xparam, double yparam); // конструктор с координатами
	Point(double xparam, double yparam, int cparam); // констуркутор со всеми полями
	~Point(); // деструктор 
	Point(const Point& ppoint); // копирующий конструктор
	void Setlable(int cparam); // метод изменения принадлежности к кластеру
	double RVector(); // метод определения расстояния от центра декартовой сиситемы до точки
	double Distance(const Point& ppoint); // расстояние до другой точки
	double Givexcord(); // вернуть координату X
	double Giveycord(); // вренуть координату Y
	int GiveLable(); // вернуть метку кластера
	void Accure(double pog1, double pog2); // методы отвечающие за сдивг точки
	void Accurex(double pog1);
	void Accurey(double pog2);
	void SetPoint(Point& ppoint);
	//void operator = (const Point& ppoint); // переопределенный оператор
};
