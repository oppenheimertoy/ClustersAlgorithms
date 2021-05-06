#pragma once
#include <vector>
#include <cmath>
#include <string>
#include "Point.h"
#include "Field.h"
#include "DBSCAN.h"
#include "HIERARCHICAL.h"
#include "WAVE.h"
class Poisk {
private:
	std::vector<Point> arrpoint; //for all 
	int p_num;
	double p_eps;
	int p_Minpts;
public:
	Poisk(std::vector<Point> p_arrpoint) : arrpoint(p_arrpoint), p_num(0), p_eps(0), p_Minpts(0) {
	};
	void ChangeNum(int c_num);
	void ChangeEps(double c_eps);
	void ChangeMinpts(int c_Minpts);
	void S_DBSCAN(int Minpts, double eps);
	void S_HIERARCHICAL(int p_num);
	void S_WAVE(double p_eps);
	void CleanLables();
	void OpenGNUplot(int p_clast);
	~Poisk() {
		arrpoint.resize(0);
	};
	void Main_Func();
	int AmountOFClusters();
 };