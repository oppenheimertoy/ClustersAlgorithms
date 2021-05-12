#pragma once
#include <vector>
#include <cmath>
#include "Point.h"
#include "Field.h"

class WAVET {
private:
	std::vector<Point> w_arrpoints;
	std::vector<std::vector<double>> w_matrix;
	double w_eps;
public:
	~WAVET() {
		w_arrpoints.resize(0);
		w_matrix.resize(0);
	};
	WAVET(std::vector<Point> p_arrpoints, double p_eps) {
		w_arrpoints = p_arrpoints;
		w_matrix.resize(0);
		w_eps = p_eps;
	}
	void FireNeighbours(int p_lable, int p_index);
	void Init_WAVE();
	void PrintToFile_W();
	std::vector<Point> Get_WAVE();
	bool CheckAllClusters();
};