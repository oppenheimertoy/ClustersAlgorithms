#pragma once

#include "Oval.h"
#include "Point.h"
#include <vector>


class Field {
private:
	std::vector <Point> vecall;
	int numov;

public:
	Field(); 
	Field(int n);
	~Field();
	void AddOval(int aparam, double xparam, double yparam, double dxparam, double dyparam);
	void PrintToFile();
	void FillFromFile( const char* filename);
	void AddOval(Oval& poval);
	std::vector<Point> Get_Points();
};
