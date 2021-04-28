#include "Point.h"
#include <math.h>

Point::Point(double xparam, double yparam) { // конструктор с параметрами(без принадлежности к кластеру)
	x = xparam;
	y = yparam;
	fclast = 0;
}

Point::Point() :x(0), y(0), fclast(0) // конструктор без параметров
{

}

Point::~Point(){} //деструктор класса Point

void Point::Setlable(int cparam) { // принадлежность к определенному кластеру
	fclast = cparam;
}

Point::Point(double xparam, double yparam, int cparam) { // конструктор с параметрами
	x = xparam;
	y = yparam;
	fclast = cparam;
	RVector();
}

double Point::RVector() { // нахождение радиус вектора точки
	return(sqrt(x + y));
}

double Point::Distance(const Point& ppoint) {
	return(sqrt((x - ppoint.x) * (x - ppoint.x) + (y - ppoint.y) * (y - ppoint.y)));
}

double Point::Givexcord(){
	return x;
}

double Point::Giveycord() {
	return y;
}

void Point::Accure(double pog1, double pog2) {
	x += pog1;
	y += pog2;
}

void Point::Accurex(double pog1) {
	x += pog1;
}

void Point::Accurey(double pog2) {
	y += pog2;
}
Point::Point(const Point& ppoint) { // копирующий конструктор
	x = ppoint.x;
	y = ppoint.y;
	fclast = ppoint.fclast;
}

int Point::GiveLable() { // вернуть метку кластера
	return (fclast);
}

