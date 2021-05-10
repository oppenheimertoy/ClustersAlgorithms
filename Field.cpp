#include "Field.h"
#include "Oval.h"
#include "Point.h"
#include<iostream>
#include <fstream>


Field::Field():numov(0){
	vecall.resize(0);
}

Field::Field(int n) {
	numov = n;
	int aparam;
	double xparam, yparam, dxparam, dyparam;
	for (int i = 0; i < n; ++i) {
		std::cin>>aparam>> xparam>>yparam>>dxparam>>dyparam;
		Oval(aparam, xparam, yparam, dxparam, dyparam).AddtoPointlist(vecall);
	}
}

Field::~Field() {
	vecall.resize(0);
}

void Field::AddOval(int aparam, double xparam, double yparam, double dxparam, double dyparam) {
	Oval(aparam, xparam,yparam, dxparam, dyparam).AddtoPointlist(vecall);
}

void Field::AddOval(Oval& poval) {
	poval.AddtoPointlist(vecall);
}

void Field::PrintToFile() {
	std::ofstream f;
	f.open("D:\\First need\\Desktop\\C++ projects\\clasterscurs\\field.txt", std::ios::out);
	for (int i = 0; i < vecall.size(); ++i) {
		f << vecall[i].Givexcord() << '\t' << vecall[i].Giveycord() << '\t' << vecall[i].GiveLable() << std::endl;
	}
	f.close();
}

void Field::FillFromFile(const char *filename) {
	double x, y; 
	int lable;
	std::ifstream f;
	f.open(filename, std::ios::in);
	while (!f.eof()) {
			f >> x >> y >> lable;
			vecall.push_back(Point(x, y, lable));
		}
}

std::vector<Point> Field::Get_Points() {
	return vecall;
}
