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
	std::string parse;
	std::vector<Point> arrpoint; //for all 
	int p_num;
	double p_eps;
	int p_Minpts;
public:
	Poisk(std::string param_string, std::vector<Point> p_arrpoint) : parse(param_string), arrpoint(p_arrpoint) {
	};
	void ChangeParse(std::string param_str);
	void ChangeNum(int c_num);
	void ChangeEps(double c_eps);
	void ChangeMinpts(int c_Minpts);
	void S_DBSCAN(int Minpts, double eps);
	void S_HIERARCHICAL(int p_num);
	void S_WAVE(double p_eps);
	~Poisk() {
		arrpoint.resize(0);
	};
	int Main_Func();
 };