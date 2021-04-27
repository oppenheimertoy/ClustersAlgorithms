#pragma once

#include <vector>
#include <cmath>
#include "Point.h"
#include "Field.h"

#define Unclassified 0
#define Noise -2
#define Failure -3
#define Success -1

class DBSCAN {
private:
	std::vector<Point> d_arrpoint;
	int d_Minpts;
	double d_eps;
public:
	DBSCAN(std::vector<Point> arrpoint, int Minpts, double eps) {
		d_arrpoint=arrpoint;
		d_Minpts=Minpts;
		d_eps=eps;
	};
	~DBSCAN() {};
	std::vector<Point> regionQuery(Point ppoint);
	int ExpandCluster(Point ppoint,   int p_lable);
	int Init_DBSCAN();
	std::vector<Point> Get_DBS();
	void PrintToFile_D();
	void Changelb(Point ppoint, int lab);
	void Delete(Point ppoint, std::vector<Point> &pointsparam);

};